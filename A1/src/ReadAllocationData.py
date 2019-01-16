## @file ReadAllocationData.py
#  @author 
#  @brief 
#  @date

#How to open a file taken from: https://docs.python.org/3/tutorial/inputoutput.html#reading-and-writing-files


def readStdnts(s):

    # Creates a new dictionary
    student_info = []

    # Opens the file for reading
    f = open(s, 'r')

    # Reads in each line, converts to a dictionary, then adds the dictionay to the list
    for line in f:

        # Strips the newline character at the end of the string
        line = line.rstrip() #https://stackoverflow.com/questions/275018/how-can-i-remove-a-trailing-newline-in-python

        # Splits each line at each tab into a list
        student_string = line.split('\t') #https://www.pythoncentral.io/cutting-and-slicing-strings-in-python/

        # Splits the choices at commans and spaces
        choices = student_string[5].split(', ')

        # Transforms the current line student to a dictionary
        student_dictionary = {'macid': student_string[0], 'fname': student_string[1], 'lname': student_string[2],
                              'gender': student_string[3], 'gpa': float(student_string[4]), 'choices': choices}

        # Adds the current dictionary to a list of student info
        student_info.append(student_dictionary)

    # Closes the file
    f.close()

    print(student_info)

    # Return statement
    return student_info

def readFreeChoice(s):

    # Creates an empty list
    students_free_choice = []

    # Opens the file
    f = open(s, 'r')

    # Iterates through the file, stripping the new line character, and appending each macid to the list
    for line in f:
        line = line.rstrip()
        students_free_choice.append(line)

    # Closes the file
    f.close()

    print(students_free_choice)

    # Returns the list
    return students_free_choice

def readDeptCapacity(s):

    # Create an empty dictionary
    department_capacity = {}

    # Opens the file
    f = open(s, 'r')

    for line in f:
        line = line.rstrip()
        list = line.split(' ')
        department_capacity[list[0]] = int(list[1]) #https://docs.python.org/3/tutorial/datastructures.html#dictionaries

    # Closes the file
    f.close()

    print(department_capacity)

    # Returns a dictionary of the departments and their capacity
    return department_capacity


readStdnts('rawStudentData')
readFreeChoice('freeChoice')
readDeptCapacity('rawDepartmentData')

