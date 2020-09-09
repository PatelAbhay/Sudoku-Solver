from tkinter import *


class GUIWindow:
    def __init__(self, root):
        self.root = root
        root.title("A simple GUI")

        self.label = Label(root, text="This is our first GUI!")

        self.greet_button = Button(root, text="Greet", command=self.greet)

        self.close_button = Button(root, text="Close", command=root.quit)

        self.label.grid(columnspan=2, sticky=W)
        self.greet_button.grid(row=1)
        self.close_button.grid(row=1, column=1)

    def greet(self):
        print("Hello")


root = Tk()
gui = GUIWindow(root)
root.mainloop()
