# Created by Joshua Guinness

import SeqADT
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

class SInfoT(NamedTuple):
	fname: string
	lname: string
	gender: GenT
	gpa: float
	choices: SeqADT(DeptT)
	freechoice: bool
