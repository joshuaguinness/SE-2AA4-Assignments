## @file Read.py
#  @title Read
#  @author Joshua Guinness, guinnesj, 400134735
#  @date Febuary 11, 2019

from StdntAllocTypes import *
from DCapALst import *
from SALst import *

def load_stdnt_data(s):

	SALst.init()

	f = open(s, 'r')

	for line in f:
		temp = line.split(',')

		student_info = []
		for Info in (SInfoT):
			

	SALst.add(temp[0], student_info)

	f.close()

def load_dcap_data(s):

	DCapALst.init()

	f = open(s, 'r')
		

	for line in f:
		temp = line.split(',')


	f.close()


stdnt_data = "StdntData.txt"
dept_capacity = "DeptCap.txt"

load_stdnt_data(stdnt_data)
load_dcap_data(dept_capacity)

