# Created by Joshua Guinness

from SeqADT import *
from collections import namedtuple
from enum import Enum
#GenT use an enumerate type

class GenT(Enum):
	MALE = 1
	FEMALE = 2

class DeptT(Enum):
	CIVIL = 1
	CHEMICAL = 2
	ELECTRICAL = 3
	MECHANICAL = 4
	SOFTWARE = 5
	MATERIALS = 6
	ENGPHYS = 7

class SInfoT(namedtuple):
	fname: str
	lname: str
	gender: GenT
	gpa: float
	choices: SeqADT
	freechoice: bool