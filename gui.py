from tkinter import *
from tkinter.ttk import *
from ctypes import *


class GUIWindow:
    def __init__(self, root):
        self.root = root

        self.main_label = Label(root, text="Sudoku Solver")
        self.main_label.config(font=(DEFAULT_MODE, 32))

        style = Style()
        style.configure('TButton', font=('calibri', 20, 'bold'),
                        borderwidth='4')

        self.start_button = Button(root, text="START", command=self.start)

        self.close_button = Button(root, text="INFO", command=self.info)

        '''self.main_label.grid(row=0, column=1,
                             padx=((root.winfo_screenwidth()//2)*0.3, 0),
                             pady=((root.winfo_screenheight()//2)*0.125, 0))'''
        self.main_label.grid(row=0, column=1)
        self.start_button.grid(row=1, column=0,
                               padx=(0, 0),
                               pady=(0, 0))
        self.close_button.grid(row=1, column=2)

    def start(self):
        test = CDLL("./solver.so")
        test.hello()

    def info(self):
        print("Need to implement this")


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
