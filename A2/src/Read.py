## @file Read.py
#  @title Read
#  @author Joshua Guinness, guinnesj, 400134735
#  @date Febuary 11, 2019

from StdntAllocTypes import *
from DCapALst import *
from SALst import *

## @brief Loads in the student data and updates the state of the SALst module
#  @param A filename of student data
#  @return idk yet
def load_stdnt_data(s):

    SALst.init()

    f = open(s, 'r')

    for line in f:
        temp = line.split(', ')
        student_info = []
        
        student_info.append(temp[1])
        student_info.append(temp[2])
        student_info.append(GenT[temp[3]])
        student_info.append(float(temp[4]))

        temp2 = temp[5].replace('[', "")
        temp3 = temp2.replace(']', "")
        temp4 = temp3.split(', ')

        for i in temp4:
            i = DeptT[i]

        student_info.append(SeqADT(temp4))
        student_info.append(bool(temp[6]))

        final_info= SInfoT(student_info[0], student_info[1], student_info[2],
        student_info[3], student_info[4], student_info[5])

        #final_info = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.civil, DeptT.chemical]), True)

    SALst.add(temp[0], final_info)

    f.close()

## @brief Loads in the department data and updates the state of the DCapALst module
#  @param p1 A filename of department data
#  @return idk yet
def load_dcap_data(s):

    DCapALst.init()

    f = open(s, 'r')
    DCapALst.init()
    for line in f:
        temp = line.split(', ')
        DCapALst.add(DeptT[temp[0]], temp[1])

    f.close()

# Will not use this, use for testing but kick down the road later on
stdnt_data = "StdntData.txt"
dept_capacity = "DeptCap.txt"

load_stdnt_data(stdnt_data)
load_dcap_data(dept_capacity)

