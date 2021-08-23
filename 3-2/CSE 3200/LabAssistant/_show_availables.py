from tkinter import *

font = ("Ubuntu", 12, "bold")


class ShowAvailables(Toplevel):
    def __init__(self, availables):
        Toplevel.__init__(self)
        self.title("Available")
        self.geometry("+500+100")
        self.resizable(False, False)
        self.available = self.create_available_text(availables)
        self.text_area = Text(self, bg="white",
                              height=10, width=35,
                              padx=10, pady=10,
                              wrap=WORD, font=font)
        self.text_area_content()

    def text_area_content(self):
        self.text_area.pack(fill=BOTH, expand=1)
        self.text_area.insert(END, self.available)

    def create_available_text(self, availables):
        if len(availables) is 0:
            return "No laptops are available now."
        return "\t".join(availables)
