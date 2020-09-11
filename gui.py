from tkinter import *
from tkinter.ttk import *
from ctypes import *


class GUIWindow:
    def __init__(self, root):
        entries = []
        for a in range(0, 360, 40):
            for b in range(0, 360, 40):
                temp = Entry(root)
                temp.place(x=a, y=b, width=40, height=40)
                entries.append(temp)


def setWindow(root):
    screen_width = root.winfo_screenwidth()
    screen_height = root.winfo_screenheight()

    window_width = screen_width//2
    window_height = screen_height//2

    x_offset = (screen_width//2) - (screen_width//4)
    y_offset = (screen_height//2) - (screen_height//4)

    window_size = str(window_width) + "x" + str(window_height)
    window_offset = str(x_offset) + "+" + str(y_offset)

    root.geometry(window_size + "+" + window_offset)
    root.title("Sudoku Solver")


root = Tk()
setWindow(root)
gui = GUIWindow(root)
root.mainloop()
