## @file SALst.py
#  @title SALst
#  @author Joshua Guinness, guinnesj, 400134735
#  @date Febuary 11, 2019

from StdntAllocTypes import *
from AALst import *
from DCapALst import *

## @brief Students and operations to preform on them
class SALst:

	s = []

	## @brief Makes the list empty
	@staticmethod
	def init():
		SALst.s = []

	## @brief Adds a student to the list
	#  @param p1 macid of student
	#  @param p2 student info
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

	## @brief Removes a student from the list
	#  @param p1 macid of a student
	@staticmethod
	def remove(m):
		is_inside = False
		for i in SALst.s:
			if (i[0] == m)
				is_inside = True
				SALst.s.remove(i)

		if (is_inside == False):
			raise KeyError

	## @brief Checks to see if a student exists in the list
	#  @param p1 macid of a student
	#  @return Boolean about whether the student exists
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

	## @brief Gets the info about a particular student
	#  @param p1 macid of a student
	#  @return Info about the specified student
	@staticmethod
	def info(m):
		is_inside = False
		for i in SALst.s:
			if(i[0] == m):
				is_inside = True
				return i[1]

		if (is_inside == False):
			raise KeyError

	## @brief Sorts the student in decreasing order of GPA
	#  @param p1 lamda function
	#  @return idk yet
	@staticmethod
	def sort(f):
		L = []
		temp = SALst.s
		while (len(temp) > 0):
			for i in range(len(temp)):
				if (get_gpa(temp[i][0], ))
				

	## @brief Checks to see if the end of the sequence is reached
	#  @param p1 The instance of the class
	#  @return Boolean value about whether have reached end of sequence
	@staticmethod
	def average(f):

	## @brief Checks to see if the end of the sequence is reached
	#  @param p1 The instance of the class
	#  @return Boolean value about whether have reached end of sequence
	@staticmethod
	def allocate

	def __get_gpa__(m, s):
		for i in SALst.s:
			if (i[0] == m):
				return i[1].gpa

		