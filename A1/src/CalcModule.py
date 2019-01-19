## @file CalcModule.py
#  @Joshua Guinness 
#  @A to preform operations on the data got from the ReadAllocationData.py
#  @January 14-18, 2019

# Imports
from ReadAllocationData import *
import sys


# For this function I am assuming that the information contained in S is corrected and formatted properly

## @brief A function which sorts the students based on gpa from highest to lowest
#  @param p1 A list of dictionaries of students
#  @return Returns a list of dictionaries of students sorted by gpa
def sort(S):

    # Sorts students by GPA from highest to lowest using Bubble Sort
    # Bubble sort implementation gotten from: https://www.geeksforgeeks.org/python-program-for-bubble-sort/
    for i in range (len(S)):
        for j in range (0, len(S)-1-i):

            # How to access stuff from dictionaries gotten from: https://www.pythonforbeginners.com/dictionary/how-to-use-dictionaries-in-python
            if (S[j].get('gpa') < S[j+1].get('gpa')):
                swap(S, j, j+1)
    
    return S


# For this function I am assuming that the information contained in L is correct and formatted properly
# and the value passed for g is either 'male' or 'female.'

## @brief A function which gets the average gpa of either all the male or female students
#  @param p1 A list of dictionaries of students
#  @param p2 A string which is either 'male' or 'female'
#  @return Returns the average gpa
def average(L, g):

    total_sum = 0
    counter = 0

    # Iterates through each student, checks the gender, then adds the gpa to a sum if the gender matches
    for i in range(len(L)):
        if (L[i].get('gender') == g):
            total_sum += L[i].get('gpa')
            counter += 1

    # Returns none if there are no students with that gender
    if (counter == 0):
        return None

    # Returns the total sum gpa divided by the number of students of that gender
    else:
        average_gpa = total_sum / counter
        return average_gpa


# For this function I am assuming that the contents of S, F, and C are correct and formatted properly.
# I am also assuming that their is enough department capacity to handle all the people with free choice
# Finally I am assuming that their is enough department capacity to grant everyone at least their third choice

## @brief A function which allocates the students into their streams.
#  @details It first allocates those with free choice, then it allocates those without free choice in order of gpa
#  @param p1 A list of dictionaries of students
#  @param p2 A list of students with free choice
#  @param p3 A dictionary of department capacities
#  @return Returns a dictionary of allocated students
def allocate(S, F, C):

    # Creation of the allocation dictionary
    allocation_dictionary = {'civil': [], 'chemical': [], 'electrical': [], 'mechanical': [], 'software': [], 'materials': [], 'engphys': []}

    # Students are now sorted from highest GPA to lowest
    sorted_students = sort(S)

    # Allocate students with free choice
    
    # Iterates through all the students with free choice, first checking to make sure their gpa is >= 4.0,
    # if not then it does not allocate them. If it meets the gpa requirements, it allocates the student to
    # the program of their first choice by adding their dictionary to the allocation dictionary
    for i in F:
        student_choice = ""
        for j in sorted_students:
            if (i == j.get('macid') and j.get('gpa') >= 4.0):
                student_choice = j.get('choices')[0]
                allocation_dictionary.get(student_choice).append(j)

                # Reduces the department capacity of the most recent choice by one
                C[student_choice] = C[student_choice]-1

    # Allocate all the rest of the students.
    
    # First check to make sure the student has a gpa >= 4.0, and they were not allocated in previously by free choice,
    # not allocating them if they don't. If they do, it allocates them by order of gpa, by placing them into
    # their first, second, or third choice by department capacity. It then decreases the department capacity by one.
    for i in sorted_students:

        # Checking if a value is in a list from: https://thispointer.com/python-how-to-check-if-an-item-exists-in-list-search-by-value-or-condition/
        if ((i.get('gpa') >= 4.0) and (i.get('macid') not in F)):
            first_choice = i.get('choices')[0]
            second_choice = i.get('choices')[1]
            third_choice = i.get('choices')[2]
            if (C.get(first_choice) >= 1):
                allocation_dictionary.get(first_choice).append(i)
                C[first_choice] = C[first_choice]-1
            elif (C.get(second_choice) >= 1):
                allocation_dictionary.get(second_choice).append(i)
                C[second_choice] = C[second_choice]-1
            elif (C.get(third_choice) >= 1):
                allocation_dictionary.get(third_choice).append(i)
                C[third_choice] = C[third_choice]-1

    # Returns the dicionary of allocated students
    return allocation_dictionary

# Function to swap two elements in a list. This function is used to implement
# bubble sort in the sort() function above
def swap(list, elem1, elem2):
    
    temp = list[elem1]
    list[elem1] = list[elem2]
    list[elem2] = temp

    return list

