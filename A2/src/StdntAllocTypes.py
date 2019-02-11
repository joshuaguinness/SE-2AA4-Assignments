# Created by Joshua Guinness

from SeqADT import *
from collections import namedtuple
from enum import Enum
#GenT use an enumerate type

class GenT(Enum):
	male = 1
	female = 2

class DeptT(Enum):
	civil = 1
	chemical = 2
	electrical = 3
	mechanical = 4
	software = 5
	materials = 6
	engphys = 7

class SInfoT(namedtuple):
	fname: str
	lname: str
	gender: GenT
	gpa: float
	choices: SeqADT
	freechoice: bool