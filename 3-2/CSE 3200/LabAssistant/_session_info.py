from tkinter import *
from tkinter import messagebox
import pandas as pd

font = ("Ubuntu", 12, "bold")


class Session(Toplevel):
    def __init__(self):
        # window definition
        Toplevel.__init__(self)
        self.title("Session Info")
        self.resizable(False, False)
        self.geometry("+600+150")
        # component definition
        self._course_label = Label(self, text="Course No: ", font=font)
        self._instructor_label = Label(self, text="Instructor Code: ", font=font)
        self._course_entry = Entry(self, width=20, bg="white", font=font)
        self._instructor_entry = Entry(self, width=20, bg="white", font=font)
        self._submit_button = Button(self, text="Start Session",
                                     font=font, command=self.get_data)
        # place components
        self._place_components()

    def _place_components(self):
        self._course_label.grid(row=0, column=0, sticky=E, padx=5, pady=5)
        self._course_entry.grid(row=0, column=1, padx=5, pady=5)
        self._instructor_label.grid(row=1, column=0, padx=5, pady=5)
        self._instructor_entry.grid(row=1, column=1, padx=5, pady=5)
        self._submit_button.grid(row=2, columnspan=2, padx=5, pady=5)

    def get_data(self):
        course = self._course_entry.get()
        instructor = self._instructor_entry.get()
        if (course == "") or (instructor == "") is True:
            messagebox.showwarning("Error", "Please provide all info")
        else:
            new_session = pd.read_csv("session.csv")
            new_session.loc[0] = [0, course, instructor]
            new_session.to_csv("session.csv")
            self.destroy()
