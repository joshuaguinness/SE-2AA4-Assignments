# Coded by Joshua Guinness

class SeqADT:

def __init__ (self, x):
	self.s = x
	self.i = 0

	return self

def start(self):
	self.i = 0

def next(self):
	if (self.i >= len(self.s)):
		
	return self.s[self.i]
	self.i = self.i + 1

def end(self):
	if (self.i >= len(self.s)):
		return True

