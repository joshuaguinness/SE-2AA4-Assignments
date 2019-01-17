## @file CalcModule.py
#  @Joshua Guinness 
#  @brief 
#  @date 

from ReadAllocationData import *

def sort(S):

    # Sorts in students by GPA by highest to lowest
    # https://www.geeksforgeeks.org/python-program-for-bubble-sort/
    for i in range (len(S)):
        for j in range (0, len(S)-1-i):
            if (S[j].get('gpa') < S[j+1].get('gpa')): #https://www.pythonforbeginners.com/dictionary/how-to-use-dictionaries-in-python
                swap(S, j, j+1)
    
    return S

def average(L, g):

    total_sum = 0
    counter = 0

    for i in range(len(L)):
        if (L[i].get('gender') == g):
            total_sum += L[i].get('gpa')
            counter += 1

    if (counter == 0):
        return None
    else:
        average_gpa = total_sum / counter
        return average_gpa

def allocate(S, F, C):

    allocation_dictionary = {'civil': [], 'chemical': [], 'electrical': [], 'mechanical': [], 'software': [], 'materials': [], 'engphys': []}

    # Students are now sorted from highest GPA to lowest
    sorted_student_dictionaries = sort(S)

    # Allocate students with free choice
    for i in F:
        student_choice = ""
        for j in sorted_student_dictionaries:
            if (i == j.get('macid')):
                student_choice = j.get('choices')[0]
                allocation_dictionary[student_choice] = [allocation_dictionary[student_choice], i]
                C[student_choice] = C[student_choice]-1
            

    return allocation_dictionary

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
average_gpa = average(student_dictionaries, 'male')
allocation_dictionary = allocate(student_dictionaries, students_with_free_choice, department_capacity)
print(allocation_dictionary)
print(department_capacity)
               


