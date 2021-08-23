from tkinter import *
from _assign_pc import pc_assign_components
from _searches import search_boxes
from _view_info import view_info
from _session_info import Session
from tkinter import messagebox
import pandas as pd


class WindowBuilder:
    def __init__(self, master):
        self.master = master
        # frames
        self.assign_laptop_frame = LabelFrame(self.master, font="arial 15 bold")
        self.search_info_frame = LabelFrame(self.master, font="arial 15 bold")
        self.list_frame = Frame(self.master)
        # menu creation
        self.main_menu = Menu()
        self.master.config(menu=self.main_menu)
        self.new_session_menu = Menu(self.main_menu, tearoff=False)
        # place the menu
        self.new_session_create_menu()
        # place the frames
        self.f_assign_laptop_frame()
        self.search_frame()
        self.f_list_frame()

    def new_session_create_menu(self):
        self.main_menu.add_cascade(label="New", menu=self.new_session_menu)
        self.new_session_menu.add_command(label="New Session",
                                          command=self.create_new_session)

    def create_new_session(self):
        if len(pd.read_csv("session.csv")) is 0:
            new = Session()
        else:
            messagebox.showwarning("Error", "A session is already active!")

    def f_assign_laptop_frame(self):
        self.assign_laptop_frame["text"] = "Student Info"
        self.assign_laptop_frame["padx"] = 15
        self.assign_laptop_frame["pady"] = 15
        self.assign_laptop_frame["bg"] = "white"
        self.assign_laptop_frame.grid(row=1, column=0, padx=10, pady=10)
        pc_assign_components(self.assign_laptop_frame)

    def search_frame(self):
        self.search_info_frame["text"] = "Search"
        self.search_info_frame["padx"] = 15
        self.search_info_frame["pady"] = 15
        self.search_info_frame["bg"] = "white"
        self.search_info_frame.grid(row=2, column=0, padx=10, pady=10)
        search_boxes(self.search_info_frame)

    def f_list_frame(self):
        # self.list_frame["height"] = 900
        self.list_frame["bg"] = "white"
        self.list_frame.grid(row=1, rowspan=2, column=1, padx=10, pady=10)
        view_info(self.list_frame)
