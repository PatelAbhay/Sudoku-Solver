from tkinter import *


class GUIWindow:
    def __init__(self, root):
        self.root = root
        root.title("A simple GUI")

        self.label = Label(root, text="Sudoku Solver")

        self.greet_button = Button(root, text="Greet", command=self.greet)

        self.close_button = Button(root, text="Close", command=root.quit)

        self.label.grid(columnspan=2, sticky=W)
        self.greet_button.grid(row=1)
        self.close_button.grid(row=1, column=1)

    def greet(self):
        print("Hello")


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


root = Tk()
setWindow(root)
gui = GUIWindow(root)
root.mainloop()
