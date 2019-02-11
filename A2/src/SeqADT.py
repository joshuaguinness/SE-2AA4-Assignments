# Coded by Joshua Guinness

@staticmethod
class SeqADT:

def __init__ (self, x):
	self.s = x
	self.i = 0

def start(self):
	self.i = 0

def next(self):
	if (self.i >= len(self.s)):
		raise StopIteration
		
	return self.s[self.i]
	self.i = self.i + 1

def end(self):
	if (self.i >= len(self.s)):
		return True

