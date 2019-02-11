## @file SALst.py
#  @title SALst
#  @author Joshua Guinness, guinnesj, 400134735
#  @date Febuary 11, 2019

from StdntAllocTypes import *
from AALst import *
from DCapALst import *

## @brief Departments and the students allocated to them
class SALst:

	s = []

	@staticmethod
	def init():
		SALst.s = []

	@staticmethod
	def add(m, i):
		is_inside = False
		for i in SALst.s:
			if (i[0] == m):
				is_inside = True

		if (is_inside == True):
			raise KeyError
		else:
			SALst.s.append((m, i))

	@staticmethod
	def remove(m):
		is_inside = False
		for i in SALst.s:
			if (i[0] == m)
				is_inside = True
				SALst.s.remove(i)

		if (is_inside == False):
			raise KeyError

	@staticmethod
	def elm(m):
		is_inside = False
		for i in SALst.s:
			if (i[0] == m):
				is_inside = True
		
		if (is_inside == True):
			return True
		else:
			return False

	@staticmethod
	def info(m):
		is_inside = False
		for i in SALst.s:
			if(i[0] == m):
				is_inside = True
				return i[1]

		if (is_inside == False):
			raise KeyError

	@staticmethod
	def sort(f):
		L = []
		temp = SALst.s
		while (len(temp) > 0):
			for i in range(len(temp)):
				if (get_gpa(temp[i][0], ))
				

	@staticmethod
	def average(f):

	@staticmethod
	def allocate

	def __get_gpa__(m, s):
		for i in SALst.s:
			if (i[0] == m):
				return i[1].gpa

		