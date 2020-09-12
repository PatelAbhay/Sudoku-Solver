from tkinter import *
from ctypes import *
import ctypes


class EntrySquare:
    def __init__(self, root, row, col, color):
        self.value = StringVar()
        self.input = Entry(root, textvariable=self.value, width=4, bg=color,
                           borderwidth=0, highlightcolor='yellow', highlightthickness=1,
                           cursor='arrow', highlightbackground='black',
                           font="Helvetica", justify="center")

        self.input.grid(row=row, column=col, ipadx=5, ipady=10)

    def getValue(self):
        if not self.isValidNum(self.input.get()):
            return 0
        return int(self.input.get())

    def isValidNum(self, str):
        if str in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
            return True
        return False


class GUIWindow:
    def __init__(self, root):
        self.root = root
        self.sudoku = []
        for i in range(9):
            temp_row = []
            for j in range(9):
                if (i < 3 or i > 5) and (j < 3 or j > 5):
                    color = 'gray'
                elif i in [3, 4, 5] and j in [3, 4, 5]:
                    color = 'gray'
                else:
                    color = 'white'

                temp_row += [EntrySquare(root, i+1, j, color)]
            self.sudoku.append(temp_row)

        self.solve = Button(root, text="Solve", command=self.solveSudoku)
        self.info = Button(root, text="Info")
        self.new = Button(root, text="New", command=self.clearSudoku)

        self.solve.grid(row=3, column=9)
        self.info.grid(row=5, column=9)
        self.new.grid(row=7, column=9)

    def convertToCArray(self, board):
        arr = (ctypes.c_int * 81)(*board)
        return arr

    def generateCompletedBoard(self, arr):
        finished = []
        for i in range(0, 9):
            temp_list = []
            for j in range(0, 9):
                temp_list.append(arr[9*i+j])
            finished.append(temp_list)
        return finished

    def solveSudoku(self):
        matrix = []
        for i in range(9):
            for j in range(9):
                matrix.append(int(self.sudoku[i][j].getValue()))

        c_array = self.convertToCArray(matrix)
        execute = CDLL("./solver.so")
        execute.solve_sudoku(c_array)

        completed = self.generateCompletedBoard(c_array)

        for i in range(9):
            for j in range(9):
                self.sudoku[i][j].value.set(completed[i][j])

    def clearSudoku(self):
        for i in range(9):
            for j in range(9):
                self.sudoku[i][j].value.set('')


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
