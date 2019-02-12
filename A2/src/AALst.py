## @file AALst.py
#  @title AALst
#  @author Joshua Guinness, guinnesj, 400134735
#  @date Febuary 11, 2019

from StdntAllocTypes import *


## @brief Departments and the students allocated to them
class AALst:

    ## @brief Makes the list empty
    @staticmethod
    def init():
        AALst.s = []

        for dept in (DeptT):
            AALst.s.append((dept, []))

    ## @brief Adds a student to a department
    #  @param p1 Department of type DeptT
    #  @param p2 MacId of student
    @staticmethod
    def add_stdnt(dep, m):
        for i in AALst.s:
            if (i[0] == dep):
                i[1].append(m)

    ## @brief Outputs a list of students allocated to the specified department
    #  @param p1 Department of type DeptT
    #  @return list of allocated macids to the specified department
    @staticmethod
    def lst_alloc(d):
        for i in AALst.s:
            if (i[0] == d):
                return i[1]

    ## @brief Checks the number of students allocated to a specified department
    #  @param p1 Department of type DeptT
    #  @return Number of students allocated to a specified department
    @staticmethod
    def num_alloc(d):
        for i in AALst.s:
            if (i[0] == d):
                return len(i[1])