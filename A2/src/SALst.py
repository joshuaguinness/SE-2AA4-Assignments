# Created by Joshua Guinness

from StdntAllocTypes import *
from AALst import *
from DCapALst import *

class SALst:
	def __init__(self):
		self.s = []

	def add(m, i):
		is_inside = False
		for i in self.s:
			if (i[0] == m):
				is_inside = True

		if (is_inside == True):
			raise KeyError
		else:
			self.s.append((m, i))

	def remove(m):
		is_inside = False
		for i in self.s:
			if (i[0] == m)
				is_inside = True
				self.s.remove(i)

		if (is_inside == False):
			raise KeyError

	def elm(m):
		for i in self.s:
			if (i[0] == m):
				return i

	def info(m):
		is_inside = False
		for i in self.s:
			if(i[0] == m):
				is_inside = True
				return i[1]

		if (is_inside == False):
			raise KeyError

	def sort(f):

	def average():

	def allocate

	def get_gpa(m, s):
		