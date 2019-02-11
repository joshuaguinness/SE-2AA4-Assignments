# Created by Joshua Guinness

from StdntAllocTypes import *

class AALst:

	s = []

	@staticmethod
	def init():
		AALst.s = []

		for Dept in (DeptT):
			AALst.s.append((Dept, []))

	@staticmethod
	def add_stdnt(dep, m):
		for i in AALst.s
			if (i[0] == dep):
				i[1].append(m)

	@staticmethod
	def lst_alloc(d):
		for i in AALst.s:
			if (i[0] == d):
				return i[1]

	@staticmethod
	def num_alloc(d):
		for i in AALst.s:
			if (i[0] == d):
				return len(i[1])