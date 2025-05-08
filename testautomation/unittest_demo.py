import pytest
from unittest.mock import patch
from unittest_object import generate_password, isPasswordValid, save_to_db

# unit test for password generation and validation
# Sample valid schema data
valid_inputs = [
    ("HLA1", "SubsystemA", "SN123456", "MFG987654"),
    ("HLA2", "SubsystemB", "SN654321", "MFG123456"),
    ("Test-HLA", "Sys-X", "SN-0001", "MFG-0001")
]

@pytest.fixture
def testSetup():
    print("Setup for the test \n")
    yield 1
    print("teardown for the test \n")

@patch("unittest_object.save_to_db")
def test_generate_password_with_valid_password(mock_save_to_db, testSetup):
    # simulate the save_to_db function to always return True
    mock_save_to_db.return_value = True
    
    assert testSetup == 1
    
    for hla, subsysm, serialNum, manufactureNum in valid_inputs:
        password = generate_password(hla, subsysm, serialNum, manufactureNum)
        assert isPasswordValid(password)
        mock_save_to_db.assert_called_with({
            "HLA": hla,
            "subsys": subsysm,
            "serialNum": serialNum,
            "ManufactureNum": manufactureNum,
            "password": password
        })
        