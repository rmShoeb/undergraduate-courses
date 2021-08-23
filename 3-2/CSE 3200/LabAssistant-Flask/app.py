from flask import Flask, request, render_template, url_for, redirect
# from render_pdf.render_pdf import render_pdf
import sqlite3
import datetime
import hashlib

app = Flask(__name__)

globals
con = sqlite3.connect('records.db', check_same_thread=False)
cur = con.cursor()
temp_id = 0
session_info = {}
available_laptops = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
                     28, 29, 30]
records = []
# records[x][0] is id-for-html-to recognise-individual-record
# records[x][1] is laptop-no
# records[x][2] is student-id
# records[x][3] is assign-time
# records[x][4] is return-time


@app.route("/")
def index():
    return redirect("/login")


@app.route("/login", methods=["POST", "GET"])
def login():
    if request.method == "POST":
        confidential = []
        f = open("confidential.txt", "r")
        for line in f:
            confidential.append(line.strip())
        f.close()
        identity = hashlib.sha512(request.form["identity"].encode()).hexdigest()
        password = hashlib.sha512(request.form["password"].encode()).hexdigest()
        if (identity == confidential[0]) and (password == confidential[1]) is True:
            if len(session_info) > 0:
                return redirect('/home')
            else:
                return redirect("create-session")
        else:
            return render_template("/login.html", error="Please enter correct info!")
    else:
        return render_template("login.html", error="")


@app.route("/admin", methods=["GET", "POST"])
def admin():
    if request.method == "GET":
        return render_template("admin_home.html")
    else:
        return "still thinking"


@app.route("/create-session", methods=["POST", "GET"])
def create_session():
    if request.method == "POST":
        session_info["course_code"] = request.form["course-code"]
        session_info["instructor_code"] = request.form["instructor-code"]
        return redirect("/home")
    else:
        return render_template("/create_session.html")


@app.route("/home", methods=["GET", "POST"])
def home():
    if request.method == "GET":
        return render_template(
            "home.html",
            session_info=session_info,
            records=records,
            available_laptops=available_laptops,
        )
    else:
        return "still thinking"


@app.route("/search-by-student-id", methods=["POST"])
def search_by_student_id():
    student_id = request.form['studentID']
    query = "select * from pc_assign_record where roll=" + student_id +" order by date desc"
    cur.execute(query)
    fetched_records = cur.fetchall()
    # fetched_records is a list of tuples
    return render_template('show_results.html', list_of_tuples=fetched_records)


@app.route("/search-by-laptop-no", methods=["POST"])
def search_by_laptop_no():
    laptop_no = int(request.form['laptopno'])
    query = "select * from pc_assign_record where pc_no="+str(laptop_no)+" order by date desc limit 30"
    cur.execute(query)
    fetched_records = cur.fetchall()
    # print(fetched_records)
    return render_template('show_results.html', list_of_tuples=fetched_records)


@app.route("/search-by-date", methods=["POST"])
def search_by_date():
    date = request.form['date']
    query = "select * from pc_assign_record where date='" + date + "'"
    cur.execute(query)
    fetched_records = cur.fetchall()
    # print(fetched_records)
    return render_template('show_results.html', list_of_tuples=fetched_records)


@app.route("/report-a-problem", methods=["POST"])
def record_problem():
    # record the problem into database
    return redirect("/home")


@app.route("/pc-assign", methods=["POST"])
def assign_pc():
    global temp_id
    identity = request.form["student-id"]
    pc_no = int(request.form["pc-no"])
    # print(datetime.datetime.now().time().strftime("%H-%M"))
    records.append(
        [
            temp_id,
            pc_no,
            identity,
            datetime.datetime.now().time().strftime("%H:%M"),
            ""
        ]
    )
    temp_id = temp_id + 1
    available_laptops.remove(pc_no)
    return redirect("/home")


@app.route("/return-pc/<int:id>")
def return_pc(id):
    records[id][4] = datetime.datetime.now().time().strftime("%H:%M")
    available_laptops.append(records[id][1])
    available_laptops.sort()
    return redirect("/home")


@app.route("/save-records-to-database")
def save_to_database():
    global temp_id, con, cur
    # save to database
    today = datetime.datetime.now().strftime("%Y-%m-%d")
    for record in records:
        try:
            query = "INSERT INTO 'pc_assign_record' ('date', 'roll', 'pc_no', 'assign_time', 'return_time') VALUES(?," \
                    "?,?,?,?) "
            cur.execute(query, (today, record[2], record[1], record[3], record[4]))
            con.commit()
        except Exception as e:
            print(e)
    # reset everything related to this session
    records.clear()
    session_info.clear()
    temp_id = 0
    return redirect('/create-session')


@app.route("/logout")
def logout():
    return redirect("/login")


if __name__ == "__main__":
    app.run(debug=True)
