from tkinter import *
from window_builder import WindowBuilder


if __name__ == '__main__':
    root = Tk()
    root.title("Lab Assistant")
    root.geometry("1050x695+100+0")
    root.resizable(False, False)
    content = WindowBuilder(root)
    root.mainloop()
