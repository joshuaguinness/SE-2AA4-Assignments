## @file testCalc.py
#  @Joshua Guinness, guinnesj 
#  @A module to test CalcModule.py 
#  @January 14-18, 2019

# Imports
from CalcModule import *
from ReadAllocationData import *
import unittest

# Test Case 1:
# Checks response of functions when the files are empty.

if (readStdnts('TestingData/rawStudentData2') == []
    and readFreeChoice('TestingData/freeChoice2') == []
    and readDeptCapacity('TestingData/rawDepartmentData2') == {}):
    print("Test Case 1: Pass")
else:
    print("Test Case 1: Fail")
    

# Test Case 2:
# Testing whether sort function sorts students by gpa properly
student_dictionaries = readStdnts('TestingData/rawStudentData')
students_with_free_choice = readFreeChoice('TestingData/freeChoice')
department_capacity = readDeptCapacity('TestingData/rawDepartmentData')

sorted_student_dictionaries = sort(student_dictionaries)

if (sorted_student_dictionaries == [{'gender': 'male', 'gpa': 12.0, 'choices': ['software', 'electrical', 'mechanical'], 'lname': 'Guinness', 'fname': 'Joshua', 'macid': 'guinnesj'},
                                    {'gender': 'male', 'gpa': 11.9, 'choices': ['materials', 'engphys', 'software'], 'lname': 'Guinness', 'fname': 'Daniel', 'macid': 'danielg'},
                                    {'gender': 'female', 'gpa': 11.2, 'choices': ['chemical', 'electrical', 'engphys'], 'lname': 'Khani', 'fname': 'Sophia', 'macid': 'khanis1'},
                                    {'gender': 'male', 'gpa': 9.8, 'choices': ['civil', 'mechanical', 'materials'], 'lname': 'Tara', 'fname': 'Mickey', 'macid': 'taram1'},
                                    {'gender': 'female', 'gpa': 8.6, 'choices': ['mechanical', 'civil', 'materials'], 'lname': 'Brown', 'fname': 'Grace', 'macid': 'browng'},
                                    {'gender': 'female', 'gpa': 7.1, 'choices': ['engphys', 'chemical', 'civil'], 'lname': 'Kass', 'fname': 'Cassie', 'macid': 'cassyk'},
                                    {'gender': 'male', 'gpa': 6.4, 'choices': ['software', 'civil', 'electrical'], 'lname': 'So', 'fname': 'Leon', 'macid': 'leon2'},
                                    {'gender': 'female', 'gpa': 6.3, 'choices': ['mechanical', 'electrical', 'software'], 'lname': 'Smith', 'fname': 'Roxanne', 'macid': 'smithr'},
                                    {'gender': 'female', 'gpa': 4.4, 'choices': ['mechanical', 'electrical', 'chemical'], 'lname': 'Xiao', 'fname': 'Joy', 'macid': 'joyxiao'},
                                    {'gender': 'male', 'gpa': 2.2, 'choices': ['software', 'materials', 'civil'], 'lname': 'Choy', 'fname': 'Timothy', 'macid': 'choyt2'}]):
    print("Test Case 2: Pass")
else:
    print("Test Case 2: Fail")

# Test Case 3:
# Testing whether average function returns the correct average for males
student_dictionaries = readStdnts('TestingData/rawStudentData')

average_gpa = average(student_dictionaries, 'male')

if (average_gpa > 8.45 and average_gpa < 8.47):
    print("Test Case 3: Pass")
else:
    print("Test Case 3: Fail")

# Test Case 4:
# Testing whether average function returns the correct average for females
student_dictionaries = readStdnts('TestingData/rawStudentData')

average_gpa = average(student_dictionaries, 'female')

if (average_gpa > 7.51 and average_gpa < 7.53):
    print("Test Case 4: Pass")
else:
    print("Test Case 4: Fail")

# Test Case 5:
# Testing whether average function returns the correct average for males on a different data set
student_dictionaries = readStdnts('TestingData/rawStudentData3')

average_gpa = average(student_dictionaries, 'male')

if (average_gpa > 6.73 and average_gpa < 6.75):
    print("Test Case 5: Pass")
else:
    print("Test Case 5: Fail")

# Test Case 6:
# Testing whether average function returns the correct average for females on a different data set
student_dictionaries = readStdnts('TestingData/rawStudentData3')

average_gpa = average(student_dictionaries, 'female')

if (average_gpa > 9.21 and average_gpa < 9.23):
    print("Test Case 6: Pass")
else:
    print("Test Case 6: Fail")

# Test Case 7:
# Testing whether average function returns the correct average when there are no students of the gender called
student_dictionaries = readStdnts('TestingData/rawStudentData4')

average_gpa = average(student_dictionaries, 'female')

if (average_gpa == None):
    print("Test Case 7: Pass")
else:
    print("Test Case 7: Fail")


# Test Case 8:
# Testing whether allocate function allocates the students properly
student_dictionaries = readStdnts('TestingData/rawStudentData')
students_with_free_choice = readFreeChoice('TestingData/freeChoice')
department_capacity = readDeptCapacity('TestingData/rawDepartmentData')

allocation_dictionary = allocate(student_dictionaries, students_with_free_choice, department_capacity)

if (allocation_dictionary == {'engphys': [{'gender': 'female', 'gpa': 7.1, 'choices': ['engphys', 'chemical', 'civil'], 'lname': 'Kass', 'fname': 'Cassie', 'macid': 'cassyk'}],
                              'civil': [{'gender': 'male', 'gpa': 9.8, 'choices': ['civil', 'mechanical', 'materials'], 'lname': 'Tara', 'fname': 'Mickey', 'macid': 'taram1'}],
                              'chemical': [{'gender': 'female', 'gpa': 11.2, 'choices': ['chemical', 'electrical', 'engphys'], 'lname': 'Khani', 'fname': 'Sophia', 'macid': 'khanis1'}],
                              'materials': [{'gender': 'male', 'gpa': 11.9, 'choices': ['materials', 'engphys', 'software'], 'lname': 'Guinness', 'fname': 'Daniel', 'macid': 'danielg'}],
                              'electrical': [{'gender': 'female', 'gpa': 4.4, 'choices': ['mechanical', 'electrical', 'chemical'], 'lname': 'Xiao', 'fname': 'Joy', 'macid': 'joyxiao'}],
                              'mechanical': [{'gender': 'female', 'gpa': 8.6, 'choices': ['mechanical', 'civil', 'materials'], 'lname': 'Brown', 'fname': 'Grace', 'macid': 'browng'},
                                             {'gender': 'female', 'gpa': 6.3, 'choices': ['mechanical', 'electrical', 'software'], 'lname': 'Smith', 'fname': 'Roxanne', 'macid': 'smithr'}],
                              'software': [{'gender': 'male', 'gpa': 12.0, 'choices': ['software', 'electrical', 'mechanical'], 'lname': 'Guinness', 'fname': 'Joshua', 'macid': 'guinnesj'},
                                           {'gender': 'male', 'gpa': 6.4, 'choices': ['software', 'civil', 'electrical'], 'lname': 'So', 'fname': 'Leon', 'macid': 'leon2'}]}):
    print("Test Case 8: Pass")
else:
    print("Test Case 8: Fail")

# Test Case 9:
# Testing whether allocate function allocates the students properly when no one has free choice
student_dictionaries = readStdnts('TestingData/rawStudentData')
students_with_free_choice = readFreeChoice('TestingData/freeChoice2')
department_capacity = readDeptCapacity('TestingData/rawDepartmentData')

allocation_dictionary = allocate(student_dictionaries, students_with_free_choice, department_capacity)

if (allocation_dictionary == {'engphys': [{'gender': 'female', 'gpa': 7.1, 'choices': ['engphys', 'chemical', 'civil'], 'lname': 'Kass', 'fname': 'Cassie', 'macid': 'cassyk'}],
                              'civil': [{'gender': 'male', 'gpa': 9.8, 'choices': ['civil', 'mechanical', 'materials'], 'lname': 'Tara', 'fname': 'Mickey', 'macid': 'taram1'}],
                              'chemical': [{'gender': 'female', 'gpa': 11.2, 'choices': ['chemical', 'electrical', 'engphys'], 'lname': 'Khani', 'fname': 'Sophia', 'macid': 'khanis1'}],
                              'materials': [{'gender': 'male', 'gpa': 11.9, 'choices': ['materials', 'engphys', 'software'], 'lname': 'Guinness', 'fname': 'Daniel', 'macid': 'danielg'}],
                              'electrical': [{'gender': 'female', 'gpa': 4.4, 'choices': ['mechanical', 'electrical', 'chemical'], 'lname': 'Xiao', 'fname': 'Joy', 'macid': 'joyxiao'}],
                              'mechanical': [{'gender': 'female', 'gpa': 8.6, 'choices': ['mechanical', 'civil', 'materials'], 'lname': 'Brown', 'fname': 'Grace', 'macid': 'browng'},
                                             {'gender': 'female', 'gpa': 6.3, 'choices': ['mechanical', 'electrical', 'software'], 'lname': 'Smith', 'fname': 'Roxanne', 'macid': 'smithr'}],
                              'software': [{'gender': 'male', 'gpa': 12.0, 'choices': ['software', 'electrical', 'mechanical'], 'lname': 'Guinness', 'fname': 'Joshua', 'macid': 'guinnesj'},
                                           {'gender': 'male', 'gpa': 6.4, 'choices': ['software', 'civil', 'electrical'], 'lname': 'So', 'fname': 'Leon', 'macid': 'leon2'}]}):
    print("Test Case 9: Pass")
else:
    print("Test Case 9: Fail")

print("All Test Cases Complete")
