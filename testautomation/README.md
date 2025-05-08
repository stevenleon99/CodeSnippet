**Application Function**
ESAT CyberArk application: input the info of the subsystem/device (schema design: HLA name, subsystem name, serial number, manufacturing number), the software will create a password to this substance and store this entry into cyberark database. 

***unit test***
- test the function generate_password(HLA: str, subsys: str, serial: str, manufactureNumber: str)
- use @patch from unittest.mock to simulate the behavior of inserting to database
- define a variety of test case as input
- verify if the function can generate correct password with the input

***api test***
- test if the substance is created in the cyberark database correctly after the input is given
- use request to insert an item by calling the endpoint of server
- use the request to get the item just inserted
- compare the item obtained with that inserted
- there are two popular methods:
  - postmand + Newman (a tool developed by the Postman team, running by npm, to run Postman collections (requests+test) directly from the terminal)
  - request + pytest

***CI/CD***
- add the unit test script to the github action. Verify the script can received correct return everytime the software is built

***pytest***
- use the following to show the printing messages
```
pytest -s .\unittest_demo.py
```
