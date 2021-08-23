from tkinter import *
from tkinter import ttk
from render_pdf.render_pdf import render_pdf

font = ("Ubuntu", 12, "bold")


class ViewRecords(Toplevel):
    def __init__(self, records, record_type, record_no):
        Toplevel.__init__(self)
        self.records = records
        self.record_type = record_type
        self.record_no = record_no
        self.tree = ttk.Treeview(self, height=30)
        self.window()
        self.place_components()
        self.place_records()

    def window(self):
        self.title("Records")
        self.resizable(False, False)
        self.geometry("+100+0")

    def place_components(self):
        self.table()
        self.tree.pack()
        self.convert_to_pdf_button()

    def table(self):
        self.tree["columns"] = ("one", "two", "three", "four", "five")
        self.tree.column("#0", width=0, stretch=NO, anchor=CENTER)
        self.tree.column("one", width=200, stretch=NO, anchor=CENTER)
        self.tree.column("two", width=200, stretch=NO, anchor=CENTER)
        self.tree.column("three", width=100, stretch=NO, anchor=CENTER)
        self.tree.column("four", width=200, stretch=NO, anchor=CENTER)
        self.tree.column("five", width=200, stretch=NO, anchor=CENTER)
        # define headings
        self.tree.heading("one", text="Date", anchor=CENTER)
        self.tree.heading("two", text="Student ID", anchor=CENTER)
        self.tree.heading("three", text="Laptop No", anchor=CENTER)
        self.tree.heading("four", text="Receive time", anchor=CENTER)
        self.tree.heading("five", text="Return time", anchor=CENTER)

    def place_records(self):
        count = 0
        for record in self.records:
            self.tree.insert(parent="", index="end", iid=count, text="",
                             values=(record[1], record[2], record[3], record[4], record[5]))
            count = count+1

    def convert_to_pdf_button(self):
        convert_button = Button(self, text="Convert to PDF", width=12,
                                font=font, command=self.goto_pdf_render)
        convert_button.pack()

    def goto_pdf_render(self):
        render_pdf(self.records, self.record_type, self.record_no)
