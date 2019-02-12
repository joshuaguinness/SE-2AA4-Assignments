## @file DCapALst.py
#  @title DCapALst
#  @author Joshua Guinness, guinnesj, 400134735
#  @date Febuary 11, 2019

from StdntAllocTypes import *


## @brief Departments and their capacities and functions to preform operations on them
class DCapALst:

    ## @brief Makes the list empty
    @staticmethod
    def init():
        DCapALst.s = []

    ## @brief Adds a department and its capacity to the list
    #  @param p1 Department of type DeptT
    #  @param p2 Capacity of type integer
    @staticmethod
    def add(d, n):

        if (len(DCapALst.s) == 0):
            DCapALst.s.append((d, n))
        else:
            is_inside = False
            for i in DCapALst.s:
                if (i[0] == d):
                    is_inside == True
        
            if (is_inside == True):
                raise KeyError
            else:
                DCapALst.s.append((d, n))
    
    ## @brief Removes a department from the set
    #  @param p1 Department of type DeptT
    @staticmethod
    def remove(d):
        is_inside = False
        for i in DCapALst.s:
            if (i[0] == d):
                is_inside == True
                DCapALst.s.remove(i)

        if (is_inside == False):
            raise KeyError

    ## @brief Checks to see if a department already exists in the set
    #  @param p1 Department of type DeptT
    #  @return Boolean value about whether the department already exists
    @staticmethod
    def elm(d):
        is_inside = False
        for i in DCapALst.s:
            if (i[0] == d):
                is_inside = True

        if (is_inside == True):
            return True
        else:
            return False

    ## @brief Checks the current capacity of a department
    #  @param p1 Department of type DeptT
    #  @return Capacity of the passed department
    @staticmethod
    def capacity(d):
        is_inside = False
        for i in DCapALst.s:
            if (i[0] == d):
                is_inside = True
                return int(i[1])

        if (is_inside == False):
            raise KeyError
        