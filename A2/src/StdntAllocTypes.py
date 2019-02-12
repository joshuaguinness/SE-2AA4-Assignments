## @file StdntAllocTypes.py
#  @title StdntAllocTypes
#  @author Joshua Guinness, guinnesj, 400134735
#  @date Febuary 11, 2019

from SeqADT import *
from typing import NamedTuple
from enum import Enum


## @brief Enumeration class for gender
class GenT(Enum):
    male = 1
    female = 2

## @brief Enumeration class for engineering departments
class DeptT(Enum):
    civil = 1
    chemical = 2
    electrical = 3
    mechanical = 4
    software = 5
    materials = 6
    engphys = 7

## @brief NamedTuple for info about each student
class SInfoT(NamedTuple):
    fname: str
    lname: str
    gender: GenT
    gpa: float
    choices: SeqADT
    freechoice: bool