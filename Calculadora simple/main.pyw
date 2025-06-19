#!/usr/bin/env python3
#Calculadora simple
#Profesor Edmundo Guiliani
#Alumno Erick Liendo

from tkinter import *

class App(Tk):
	def __init__(self):
		super().__init__()
		self.title("Calculadora")
		self.__widgets__()
		self.bind("<Configure>", lambda event: self.update())
		self.mainloop()
	def __widgets__(self):
		self.entry = Entry(self)
		self.entry.grid(row=0, column=0, columnspan=4)
		botones = [
			'7', '8', '9', '+',
			'4', '5', '6', '-',
			'1', '2', '3', '*',
			'.', '0', '=', '/',
			'CC',
		]
		c = 0
		r = 1
		c_limit = 4
		for b in botones:
			if c == c_limit: c = 0;r+=1
			Button(self, text=b, command=lambda señal=b: self.__actions__(señal)).grid(row=r, column=c, sticky='nsew')
			c+=1
		Button(self, text="CR", command=lambda : self.__actions__("CR")).grid(row=5, column=1, columnspan=4, sticky='nsew')
	def __actions__(self, b):
		txt = self.entry.get()
		if not b in ['.','=', 'CC', 'CR']:
			self.entry.insert(END, b)
		if b == '.' and not '.' in txt:
			self.entry.insert(END, b)
		elif b == 'CC':
			self.entry.delete(len(txt)-1, END)
		elif b == "CR": self.entry.delete(0, END)
		elif b == '=':
			self.entry.delete(0, END)
			res = eval(txt)
			self.entry.insert(END, res)
if __name__ == '__main__':
	App()
