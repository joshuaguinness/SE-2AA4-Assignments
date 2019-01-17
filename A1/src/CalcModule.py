## @file CalcModule.py
#  @Joshua Guinness 
#  @brief 
#  @date 

from ReadAllocationData import *

def sort(S):

    #print(S[2].get('gpa')) #https://www.pythonforbeginners.com/dictionary/how-to-use-dictionaries-in-python

    # Sorts in students by GPA by highest to lowest
    # https://www.geeksforgeeks.org/python-program-for-bubble-sort/
    for i in range (len(S)):
        for j in range (0, len(S)-1-i):
            if (S[j].get('gpa') < S[j+1].get('gpa')):
                swap(S, j, j+1)
    
    return S

def average(L, g):

    average_gpa = 5

    return average_gpa

def allocate(S, F, C):

    dictionary = 5

    return dicionary



# Function to swap two elements in a list
def swap(list, elem1, elem2):
    temp = list[elem1]
    list[elem1] = list[elem2]
    list[elem2] = temp
    return list
    



student_dictionaries = readStdnts('rawStudentData')
students_with_free_choice = readFreeChoice('freeChoice')
department_capacity = readDeptCapacity('rawDepartmentData')

sorted_student_dictionaries = sort(student_dictionaries)
               


