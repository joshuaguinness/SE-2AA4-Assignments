import pytest
from StdntAllocTypes import *
from AALst import *
from DCapALst import *
from Read import *
from SeqADT import *


class TestingClass:

    def setup_method(self, method):
        load_dcap_data("DeptCap.txt")
        load_stdnt_data("StdntData.txt")

    ## Testing the DCapALst modle
    
    # Checking to see whether departments correctly exist after reading in the data
    def test_CivilExists(self):
        assert DCapALst.elm(DeptT.civil)

    def test_ChemExists(self):
        assert DCapALst.elm(DeptT.chemical)
    
    def test_ElecExists(self):
        assert DCapALst.elm(DeptT.electrical)

    def test_MechExists(self):
        assert DCapALst.elm(DeptT.mechanical)

    def test_SoftExists(self):
        assert DCapALst.elm(DeptT.software)

    def test_MatExists(self):
        assert DCapALst.elm(DeptT.materials)

    def test_Phys(self):
        assert DCapALst.elm(DeptT.engphys)

    # Checking to see if getting the current capacity of the department works

    def test_GetCapacityCivil(self):
        assert DCapALst.capacity(DeptT.civil) == 100

    def test_GetCapacityMech(self):
        assert DCapALst.capacity(DeptT.mechanical) == 100

    def test_GetCapacityPhys(self):
        assert DCapALst.capacity(DeptT.engphys) == 100

    # Checking to see if removing a department works

    def test_RemoveDept(self):
        DCapALst.remove(DeptT.software)
        assert not DCapALst.elm(DeptT.software)

    # Checking to see if adding a department works

    def test_AddDept(self):
        DCapALst.remove(DeptT.software)
        DCapALst.add(DeptT.software, 100)
        assert DCapALst.elm(DeptT.software)

    # Checking the SALst module

    def test_StudentExists(self):
        assert SALst.elm("brownc")

    def test_RemoveStudent(self):
        SALst.remove("brownc")
        assert not SALst.elm("brownc")

    # Checking the AALst module

    def test_StudentAdd(self):
        SALst.allocate()
        AALst.add_stdnt(DeptT.civil, "brownc")
        assert AALst.num_alloc(DeptT.civil) == 2