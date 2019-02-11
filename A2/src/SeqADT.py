## @file SeqADT.py
#  @title SeqADT
#  @author Joshua Guinness, guinnesj, 400134735
#  @date Febuary 11, 2019

## @brief A class which defines an abstract data type which is a sequence
class SeqADT:

    ## @brief Initialized the state variables of the new instance.
    #  @param p1 The instance of the class.
    #  @param p2 A sequence of T.
    def __init__ (self, x):
        self.s = x
        self.i = 0

    ## @brief Sets the integer variable to zero.
    #  @param p1 The instance of the class.
    def start(self):
        self.i = 0

    ## @brief Outputs the current element of the sequence then moving to the next element
    #  @param p1 The instance of the class
    #  @return The current element of the sequence
    def next(self):
        if (self.i >= len(self.s)):
            raise StopIteration
        
        return self.s[self.i]
        self.i = self.i + 1

    ## @brief Checks to see if the end of the sequence is reached
    #  @param p1 The instance of the class
    #  @return Boolean value about whether have reached end of sequence
    def end(self):
        if (self.i >= len(self.s)):
            return True
        else:
            return False