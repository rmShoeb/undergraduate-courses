from tkinter import *
from tkinter import messagebox
from tkcalendar import *
import datetime
import sqlite3
from __view_records import ViewRecords

font = ("Ubuntu", 11)
con = sqlite3.connect("records.db")
cur = con.cursor()


def search_boxes(frame):
    search_by_roll(frame)
    search_by_pc(frame)
    search_by_date(frame)


def search_by_roll(frame):
    roll_entry = Entry(frame, font=font, width=10)
    roll_entry.grid(row=0, column=0, padx=5, pady=5)

    def get_roll_for_search():
        roll = roll_entry.get()
        if roll != "":
            if roll.isnumeric() is True:
                roll_entry.delete(0, END)
                query = "select * from pc_assign_record where roll=" + roll+" order by date desc"
                cur.execute(query)
                records = cur.fetchall()
                if len(records) is 0:
                    messagebox.showinfo("Empty", "There is no record to show!")
                else:
                    view_record_object = ViewRecords(records, "roll", roll)
            else:
                messagebox.showwarning("Error", "Invalid Input!")
        else:
            messagebox.showwarning("Error", "No Input provided!")

    search_button = Button(frame, text="Search By Roll", width=12,
                           font=font, command=get_roll_for_search)
    search_button.grid(row=0, column=1, padx=5, pady=5)


def search_by_pc(frame):
    pc_entry = Entry(frame, font=font, width=10)
    pc_entry.grid(row=1, column=0, padx=5, pady=5)

    def get_pc_for_search():
        pc_no = int(pc_entry.get())
        if pc_no != "":
            pc_entry.delete(0, END)
            query = "select * from pc_assign_record where pc_no="+str(pc_no)+" order by date desc limit 30"
            cur.execute(query)
            records = cur.fetchall()
            if len(records) is 0:
                messagebox.showinfo("Empty", "There is no record to show!")
            else:
                view_record_object = ViewRecords(records, "pc", pc_no)
        else:
            messagebox.showwarning("Error", "No Input provided!")

    search_button = Button(frame, text="Search By Laptop", width=12,
                           font=font, command=get_pc_for_search)
    search_button.grid(row=1, column=1, padx=5, pady=5)


def search_by_date(frame):
    today = datetime.datetime.today()
    year = today.strftime("%Y")
    month = today.strftime("%m")
    day = today.strftime("%d")
    cal = Calendar(frame, selectmode="day",
                   year=int(year), month=int(month), day=int(day))
    cal.grid(row=2, column=0, columnspan=2)

    def get_date():
        selected_date = str(cal.selection_get())
        query = "select * from pc_assign_record where date='" + selected_date + "'"
        cur.execute(query)
        records = cur.fetchall()
        if len(records) is 0:
            messagebox.showinfo("Empty", "There is no record to show!")
        else:
            view_record_object = ViewRecords(records, "date", selected_date)

    search_button = Button(frame, text="Search by date", width=10,
                           font=font, command=get_date)
    search_button.grid(row=3, column=0, columnspan=2, padx=5, pady=5)
