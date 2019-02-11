#Created by Joshua Guinness

from StdntAllocTypes import *

class DCapALst:
	
	s = []

	@staticmethod
	def init():
		DCapALst.s = []

	@staticmethod
	def add(d, n):
		is_inside = False
		for i in DCapALst.s:
			if (i[0] == d):
				is_inside == True
		
		if (is_inside == True):
			raise KeyError
		else:
			DCapALst.s = DCapALst.s.append((d, n))
	
	@staticmethod
	def remove(d):
		is_inside = False
		for i in DCapALst.s:
			if (i[0] == d):
				is_inside == True
				DCapALst.s.remove(i)

		if (is_inside == False):
			raise KeyError

	@staticmethod
	def elm(d):
		for i in DCapALst.s:
			if (i[0] == d):
				return i

	@staticmethod
	def capacity(d):
		is_inside = False
		for i in DCapALst.s:
			if (i[0] == d):
				is_inside = True
				return i[1]

		if (is_inside == False):
			raise KeyError
		