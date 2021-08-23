from tkinter import *
from tkinter import ttk
from tkinter import messagebox
import datetime
import sqlite3
import pandas as pd
from __assign_record_checker import CheckRecordValidity
from render_pdf.render_pdf import render_pdf
from _show_availables import ShowAvailables

font = ("Ubuntu", 12, "bold")


check_record_validity = CheckRecordValidity()
records = {}  # {"roll": [pc-no, "assign_time", "return_time"]}
today = datetime.datetime.now().strftime("%Y-%m-%d")
con = sqlite3.connect("records.db")
cur = con.cursor()

global tree
global row_count
row_count = 0


def get_pc_assign_record(roll, pc_no):
    global row_count
    validity = check_record_validity.is_valid(roll, pc_no)
    if validity is True:
        records[roll] = [pc_no, datetime.datetime.now().strftime("%H:%M"), ""]
        check_record_validity.assigned_pc(roll, pc_no)
        tree.insert(parent="", index="end", iid=row_count, text="",
                    values=(pc_no, roll, datetime.datetime.now().strftime("%H:%M"), ""))
        row_count = row_count + 1
    else:
        messagebox.showwarning("Error", validity)


def remove_all():
    for record in tree.get_children():
        tree.delete(record)


def pc_return_update():
    select = tree.focus()
    values = tree.item(select, "values")
    if values == "":
        messagebox.showwarning("Error", "No entry selected!")
    elif values[3] == "":
        records[values[1]][2] = datetime.datetime.now().strftime("%H:%M")
        tree.item(select, values=(values[0], values[1], values[2],
                                  datetime.datetime.now().strftime("%H:%M")))
        check_record_validity.pc_returned(values[1], int(values[0]))
    else:
        messagebox.showwarning("Error", "This PC has already been returned!")


def save_to_database_possibility():
    for record in records:
        if records[record][2] is "":
            return False
    return True


def save_to_database():
    if len(pd.read_csv("session.csv")) is 0:
        messagebox.showwarning("Error", "No Session was created!")
    elif len(records) is 0:
        messagebox.showwarning("Error", "No records to save!")
    elif save_to_database_possibility() is True:
        for record in records:
            try:
                query = "INSERT INTO 'pc_assign_record' ('date', 'roll', 'pc_no', 'assign_time', 'return_time')" \
                        "VALUES(?,?,?,?,?)"
                cur.execute(query, (today, record, records[record][0],
                                    records[record][1], records[record][2]))
                con.commit()
            except EXCEPTION as e:
                messagebox.showwarning("Error", e)
        goto_render()
        remove_all()
        messagebox.showinfo("Success", "Records saved")
    else:
        messagebox.showwarning("Error", "Some PC has not been returned yet!")


def format_data():
    formatted_data = []
    for roll, record in records.items():
        formatted_data.append((0, today, roll, record[0], record[1], record[2]))
    return formatted_data


def goto_render():
    if len(records) is 0:
        messagebox.showwarning("Error", "No records to save!")
    elif save_to_database_possibility() is True:
        render_pdf(format_data(), "today", today)
    else:
        messagebox.showwarning("Error", "Some PC has not been returned yet!")


def check_available():
    show = ShowAvailables(check_record_validity.available_pcs())


def view_info(frame):
    global tree
    tree = ttk.Treeview(frame, height=30)
    # define columns
    tree["columns"] = ("one", "two", "three", "four")
    tree.column("#0", width=0, stretch=NO, anchor=CENTER)
    tree.column("one", width=100, stretch=NO, anchor=CENTER)
    tree.column("two", width=200, stretch=NO, anchor=CENTER)
    tree.column("three", width=200, stretch=NO, anchor=CENTER)
    tree.column("four", width=200, stretch=NO, anchor=CENTER)
    # define headings
    tree.heading("one", text="Laptop No", anchor=CENTER)
    tree.heading("two", text="Student ID", anchor=CENTER)
    tree.heading("three", text="Receive time", anchor=CENTER)
    tree.heading("four", text="Return time", anchor=CENTER)
    # place
    tree.grid(row=1, column=0, columnspan=3)
    # check available pcs
    available = Button(frame, text="Check Available", width=12,
                       font=font, command=check_available)
    available.grid(row=2, column=0)
    # laptop has been returned
    return_button = Button(frame, text="Return", width=12,
                           font=font, command=pc_return_update)
    return_button.grid(row=2, column=1)
    # save records in database
    save_to_database_button = Button(frame, text="Save", width=12,
                                     font=font, command=save_to_database)
    save_to_database_button.grid(row=2, column=2)
