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

    #for i in range(5, 8):
     #   print(i)

    SALst.init()

    f = open(s, 'r')

    for line in f:
        temp = line.split(', ')
        student_info = []
        #print(len(temp))
        student_info.append(temp[1])
        student_info.append(temp[2])
        student_info.append(GenT[temp[3]])
        student_info.append(float(temp[4]))

        list_dept = []

        for i in range(5, len(temp)-1):
            temp2 = temp[i].replace('[', "")
            temp3 = temp2.replace(']', "")
            temp4 = DeptT[temp3]
            #print(temp4)
            list_dept.append(temp4)

        #print(list_dept)

        #for i in temp4:
         #   i = DeptT[i]

        student_info.append(SeqADT(list_dept))
        string = temp[-1]
        string2 = string.replace('\n', "")
        if (string2 == "True"):
            student_info.append(True)
        else:
            student_info.append(False)

        #print(student_info)
        #print("")

        final_info = SInfoT(student_info[0], student_info[1], student_info[2],
        student_info[3], student_info[4], student_info[5])
        #print(final_info)
        SALst.add(temp[0], final_info)

    f.close()

## @brief Loads in the department data and updates the state of the DCapALst module
#  @param p1 A filename of department data
#  @return idk yet
def load_dcap_data(s):

    DCapALst.init()

    f = open(s, 'r')
    for line in f:
        string = line.rstrip('\n')
        temp = string.split(', ')
        DCapALst.add(DeptT[temp[0]], temp[1])

    f.close()

# Will not use this, use for testing but kick down the road later on
stdnt_data = "StdntData.txt"
dept_capacity = "DeptCap.txt"

load_stdnt_data(stdnt_data)
load_dcap_data(dept_capacity)

#print(SALst.s)

#print(SALst.elm("smithj"))

print(SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0))

#print(SALst.average(lambda x: x.gender == GenT.male))
#print(SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0))

