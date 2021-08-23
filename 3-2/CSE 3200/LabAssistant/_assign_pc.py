from tkinter import *
from tkinter import messagebox
from _view_info import get_pc_assign_record

font = ("Ubuntu", 11, "bold")


def pc_assign_components(frame):
    roll_label = Label(frame, text="Roll: ", bg="white", font=font)
    pc_label = Label(frame, text="Laptop No: ", bg="white", font=font)
    roll_entry = Entry(frame, font=font)
    pc_entry = Entry(frame, font=font)
    roll_label.grid(row=0, column=0, padx=5, pady=5, sticky=E)
    roll_entry.grid(row=0, column=1, padx=5, pady=5)
    pc_label.grid(row=1, column=0, padx=5, pady=5, sticky=E)
    pc_entry.grid(row=1, column=1, padx=5, pady=5)

    def get_record_entry():
        roll = roll_entry.get()
        pc_no = pc_entry.get()
        if roll and pc_no != "":
            roll_entry.delete(0, END)
            pc_entry.delete(0, END)
            get_pc_assign_record(roll, int(pc_no))
        else:
            messagebox.showwarning("Info Missing", "Please enter all info")

    record_entry_button = Button(frame, text="Record", width=10,
                                 font=font, command=get_record_entry)
    record_entry_button.grid(row=2, column=1, padx=5, pady=5)
