from jinja2 import Environment, FileSystemLoader
from weasyprint import HTML
import pandas as pd

env = Environment(loader=FileSystemLoader('.'))
template = env.get_template("render_pdf/helper.html")


def process_data(list_of_tuple):
    data_frame = pd.DataFrame.from_records(list_of_tuple, columns=["id", "Date", "Student ID", "Laptop No",
                                                                   "Receive Time", "Return Time"])
    data_frame.drop("id", axis=1, inplace=True)
    return data_frame


def heading_string(record_type, record_no):
    if record_type == "today":
        session = pd.read_csv("session.csv")
        title = "Records of " + record_no + " Course No " + session["course_no"][0]
        string = "Records of " + record_no + "<br>Course No: " + session["course_no"][0]
        string = string + "<br>Instructor Code: " + session["instructor_code"][0]
        pd.DataFrame.from_dict({"course_no": [], "instructor_code": []}).to_csv("session.csv")
    elif record_type == "date":
        string = "Records of "+record_no
        title = string
    elif record_type == "roll":
        string = "Records with Student ID "+record_no
        title = string
    else:
        string = "Records with Laptop No "+str(record_no)
        title = string
    return string, title


def render_pdf(data, record_type, record_no):
    dataframe = process_data(data)
    string, title = heading_string(record_type, record_no)
    template_vars = {"title": "Report",
                     "heading": string,
                     "records": dataframe.to_html(index=False, justify="center",
                                                  classes=["table table-bordered"])}
    html_out = template.render(template_vars)
    HTML(string=html_out).write_pdf(title+".pdf", stylesheets=["render_pdf/style.css"])
