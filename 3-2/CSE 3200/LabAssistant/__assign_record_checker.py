import pandas as pd


class CheckRecordValidity:
    def __init__(self):
        self.pcs = pd.read_csv("pcs.csv").to_numpy()
        self.students_that_currently_have_pc = []

    def is_pc_assigned(self, pc_no):
        return self.pcs[pc_no - 1][1]

    def is_pc_entry_valid(self, pc_no):
        if pc_no > len(self.pcs):
            return False
        elif pc_no < 1:
            return False
        else:
            return True

    def is_student_assigned_pc(self, roll):
        if roll in self.students_that_currently_have_pc:
            return True
        return False

    def is_student_valid(self, roll):
        return roll.isnumeric()

    def is_valid(self, roll, pc_no):
        if self.is_student_valid(roll) is False:
            return "Invalid Student ID!"
        if self.is_pc_entry_valid(pc_no) is False:
            return "Invalid Laptop No!"
        if self.is_pc_assigned(pc_no) and self.is_student_assigned_pc(roll) is True:
            return "This student has already been assigned this PC!"
        if self.is_student_assigned_pc(roll) is True:
            return "This student has already been assigned a PC!"
        if self.is_pc_assigned(pc_no) is True:
            return "This PC has already been assigned to another student!"
        return True

    def assigned_pc(self, roll, pc_no):
        self.pcs[pc_no - 1][1] = True
        self.students_that_currently_have_pc.append(roll)

    def pc_returned(self, roll, pc_no):
        self.pcs[pc_no - 1][1] = False
        self.students_that_currently_have_pc.remove(roll)

    def available_pcs(self):
        available = []
        for pc in self.pcs:
            if pc[1] is False:
                available.append(str(pc[0]))
        return available
