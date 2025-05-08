**Summarize the unittest api test and CI/CD**
*Summary: The CI/CD, Unit Test and API Test can be integrated into the project in the following sequence:*

```mermaid
graph TD
    A[Step 1: Write Unit Tests] --> B[Step 2: Write API Tests]
    B --> C[Step 3: Start Backend Server <br> for API Testing]
    C --> D[Step 4: Verify API Response <br> with Assertions]
    D --> E[Step 5: Create CI Workflow]
    E --> F[Step 6: Integrate Unit + <br> API Tests into CI Pipeline ]
    F --> G[Step 7: CI Runs Tests <br> Automatically on Push/PR ]
```

- `CI/CD` can incorporate unittest and API test; it orchestrates and automates the pipeline of compile/test/deploy. The unit test framework like pytest/unitest can be integrated into CI for instance by `github action` which defines a series of actions (in .yaml) to run testing tasks.

```mermaid
graph TD
    A[Trigger GitHub Action<br>on Push or PR] --> B[Choose Runner OS<br>e.g., ubuntu-latest]
    B --> C[Checkout Code<br>from Repository]
    C --> D[Set Up Python Environment<br>with setup-python Action]
    D --> E[Install Dependencies<br>via pip or requirements.txt]
    E --> F[Run Unit Tests<br>with pytest]
    F --> G[View Test Results<br>in GitHub Actions UI]
```

- unit test scripts are employed to assure individual function running properly and return expected results. Some external dependencies can be excluded by mocking. It is an effective way to decouple the core function from the external dependencies.


- API tests are performed when you want to test the functionality of REST application. usually need to startup the endpoint server; use get/post to trigger an event or request some information; and use assert to compare the obtained information with the expected infromation. 

```mermaid
sequenceDiagram
    participant Tester as Test Script (Postman / Pytest)
    participant Server as Backend Server
    participant DB as Database (e.g., CyberArk)

    Tester->>Server: POST /api/device<br>with JSON payload
    Server->>DB: Save device info
    DB-->>Server: Acknowledge success
    Server-->>Tester: 200 OK + success message

    Note over Tester: Validate status code == 200<br>Assert response content

    Tester->>Server: GET /api/device/{serial_number}
    Server->>DB: Fetch device info by serial_number
    DB-->>Server: Return matching record
    Server-->>Tester: 200 OK + JSON data

    Note over Tester: Assert returned data matches<br>what was originally sent
```