---
title: Test Automation
description: ESAT CyberArk application testing framework.
---

ESAT CyberArk application testing framework for automated password management.

## Application Function

The ESAT CyberArk application takes subsystem/device info (HLA name, subsystem name, serial number, manufacturing number), creates a password, and stores it in the CyberArk database.

## Unit Test

- Test `generate_password(HLA, subsys, serial, manufactureNumber)` function
- Use `@patch` from `unittest.mock` to simulate database insertion
- Define variety of test cases as input
- Verify correct password generation

## API Test

- Test if substance is created in CyberArk database correctly
- Use `request` to insert item via endpoint
- Use `request` to get inserted item
- Compare obtained item with inserted one

Methods:
- Postman + Newman (run Postman collections from terminal)
- request + pytest

## CI/CD

Add unit test script to GitHub Actions. Verify correct return on every build.

## pytest

Show printing messages:

```bash
pytest -s unittest_demo.py
```