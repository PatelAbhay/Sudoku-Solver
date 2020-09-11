from tkinter import *
from ctypes import *


class GUIWindow:
    def __init__(self, root):
        self.sudoku = []
        for i in range(1, 10):
            self.sudoku += [[0, 0, 0, 0, 0, 0, 0, 0, 0]]

        for i in range(0, 9):
            for j in range(0, 9):
                if (i < 3 or i > 5) and (j < 3 or j > 5):
                    color = 'gray'
                elif i in [3, 4, 5] and j in [3, 4, 5]:
                    color = 'gray'
                else:
                    color = 'white'

                self.sudoku[i][j] = Entry(root, width="4", bg=color, cursor='arrow', borderwidth=0,
                                          highlightcolor='yellow', highlightthickness=1, highlightbackground='black')
                self.sudoku[i][j].grid(row=i, column=j, ipadx=10, ipady=14)

    def isValidNum(S):
        if S in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
            return True
        return False


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
