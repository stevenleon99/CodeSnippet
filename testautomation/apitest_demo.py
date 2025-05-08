import requests
import pytest
import time

BASE_URL = "http://localhost:8000"

# Sample device data

test_data = {
    "HLA": "HLA1",
    "subsys": "SubSysX",
    "serialNum": "SN_TEST_001",
    "ManufactureNum": "MFG_TEST_001",
    "password": "TestPassword123"
}

def test_save_to_db_and_retrieve():
    # Step 1: POST to save the item
    save_resp = requests.post(f"{BASE_URL}/api/device", json=test_data)
    assert save_resp.status_code == 200
    
    time.sleep(3)  # Optional: wait for a second to ensure the data is saved
    
    # Step 2: GET to retrieve and verify
    retrieve_resp = requests.get(f"{BASE_URL}/api/device/{test_data['serialNum']}")
    assert retrieve_resp.status_code == 200
    result = retrieve_resp.json()

    # Step 3: Validate content
    for key in test_data:
        assert result.get(key) == test_data[key]