# Created by Joshua Guinness

from StdntAllocTypes import *
from DCapALst import *
from SALst import *

def load_stdnt_data(s):

	SALst.init()

	f = open(s, 'r')

	for line in f:
		temp = line.split(',')



def load_dcap_data(s):





stdnt_data = "StdntData.txt"
dept_capacity = "DeptCap.txt"

load_stdnt_data(stdnt_data)
load_dcap_data(dept_capacity)

