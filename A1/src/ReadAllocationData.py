## @file ReadAllocationData.py
#  @author 
#  @brief 
#  @date

# Import for error raising and exiting
import sys

def readStdnts(s):

    # Creates a new list which will store student dictionaries
    student_info = []

    # Try-Except statement for opening the file
    try:
        
        # Opens the file for reading
        # How to open a file taken from: https://docs.python.org/3/tutorial/inputoutput.html#reading-and-writing-files
        f = open(s, 'r')
        
    except:
        
        # Exit if the file does not exist or can't be opened.
        # Method seen here: https://python-forum.io/Thread-How-to-exit-after-a-try-exception
        sys.exit("Error opening the file of student data!")

    # Reads in each line, converts to a dictionary, then adds the dictionay to the list
    for line in f:

        # Strips the newline character at the end of the string.
        # Method taken from: https://stackoverflow.com/questions/275018/how-can-i-remove-a-trailing-newline-in-python
        line = line.rstrip()

        # Splits each line at each tab into a list
        # How the split strings taken from here: #https://www.pythoncentral.io/cutting-and-slicing-strings-in-python/
        student_string = line.split('\t')

        # Splits the choices at commas and spaces
        choices = student_string[5].split(', ')

        # Transforms the current line student to a dictionary
        student_dictionary = {'macid': student_string[0], 'fname': student_string[1], 'lname': student_string[2],
                              'gender': student_string[3], 'gpa': float(student_string[4]), 'choices': choices}

        # Adds the current dictionary to a list of student info
        student_info.append(student_dictionary)

    # Closes the file
    f.close()

    #print(student_info)

    # Return statement
    return student_info

def readFreeChoice(s):

    # Creates an empty list
    students_free_choice = []

    # Try-Except block for opening the file
    try:
        
        # Opens the file
        f = open(s, 'r')
        
    except:
        
        sys.exit("Error opening the file of students with free choice!")

    # Iterates through the file, stripping the new line character, and appending each macid to the list
    for line in f:
        line = line.rstrip()
        students_free_choice.append(line)

    # Closes the file
    f.close()

    #print(students_free_choice)

    # Returns the list
    return students_free_choice

def readDeptCapacity(s):

    # Create an empty dictionary
    department_capacity = {}

    # Try-Except for opening the file
    try:

        # Opens the file
        f = open(s, 'r')

    except:

        sys.exit("Error opening the file of department capacities!")

    # Iterates through the file line by line, splitting at spaces, and adding the department and its capacity to a dictionary
    for line in f:
        line = line.rstrip()
        list = line.split(' ')

        # How to add key's and values to a dictionary got from: https://docs.python.org/3/tutorial/datastructures.html#dictionaries
        department_capacity[list[0]] = int(list[1])

    # Closes the file
    f.close()

    #print(department_capacity)

    # Returns a dictionary of the departments and their capacity
    return department_capacity


#readStdnts('rawStudentData')
#readFreeChoice('freeChoice')
#readDeptCapacity('rawDepartmentDatas')

