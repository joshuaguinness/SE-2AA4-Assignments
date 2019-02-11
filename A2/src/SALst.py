## @file SALst.py
#  @title SALst
#  @author Joshua Guinness, guinnesj, 400134735
#  @date Febuary 11, 2019

from StdntAllocTypes import *
from AALst import *
from DCapALst import *

## @brief Students and operations to preform on them
class SALst:

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
            if (i[0] == m):
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
        temp = SALst.s.copy()

        for i in temp:
            if (f(i[1]) == False):
                temp.remove(i)

        while (len(temp) > 0):
            highest = -1
            element_number = 0
            for i in range(len(temp)):
                if (temp[i][1].gpa > highest):
                    temp[i][1].gpa > highest
                    element_number = i
                    i = i+1

            L.append(temp[element_number][0])
            temp.remove(temp[element_number])

        return L
                
    ## @brief Checks to see if the end of the sequence is reached
    #  @param p1 The instance of the class
    #  @return Boolean value about whether have reached end of sequence
    @staticmethod
    def average(f):

        temp = SALst.s.copy()

        for i in temp:
            if (f(i[1]) == False):
                temp.remove(i)

        if (len(temp) == 0):
            raise ValueError

        total = 0
        number = len(temp)

        for i in temp:
            total = total + i[1].gpa

        return total/number

    ## @brief Checks to see if the end of the sequence is reached
    #  @param p1 The instance of the class
    #  @return Boolean value about whether have reached end of sequence
    @staticmethod
    def allocate():
        
        AALst.init()

        F = SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0)
        for m in F:
            ch = SALst.info(m).choices
            AALst.add_stdnt(ch.next(), m)

        S = SALst.sort(lambda t: not t.freechoice and t.gpa >= 4.0)
        for m in S:
            ch = SALst.info(m).choices
            alloc = False
            while (not alloc and not ch.end()):
                d = ch.next()
                if (AALst.num_alloc(d) < DCapALst.capacity(d)):
                    AALst.add_stdnt(d, m)
                    alloc = True
            if (not alloc):
                raise RuntimeError
