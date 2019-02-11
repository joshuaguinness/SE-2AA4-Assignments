#Created by Joshua Guinness

import StdntAllocTypes

@staticmethod
class DCapALst:
	
	def __init__(self):
		self.s = []

	def add(self, d, n):
		is_inside = False
		for i in self.s:
			if (i[0] == d):
				is_inside == True
		
		if (is_inside == True):
			raise KeyError
		else:
			self.s = self.s.append((d, n))

	def remove(d):
		is_inside = False
		for i in self.s:
			if (i[0] == d):
				is_inside == True
				self.s.remove(i)

		if (is_inside == False):
			raise KeyError

	def elm(d):
		for i in self.s:
			if (i[0] == d):
				return i

	def capacity(d):
		is_inside = False
		for i in self.s:
			if (i[0] == d):
				is_inside = True
				return i[1]

		if (is_inside == False):
			raise KeyError
		