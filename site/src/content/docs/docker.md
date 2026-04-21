---
title: Docker
description: Docker containerization examples and configuration.
---

Docker configuration and containerization examples.

## Contents

- **dockerfile/** - Docker build files and application
  - `Dockerfile` - Container definition
  - `app.py` - Application to containerize
  - `requirements.txt` - Python dependencies
- **Installing Docker The Fast Way.html** - Docker setup guide

## Building & Running

```bash
# Build the Docker image
docker build -t triviacode-app ./dockerfile

# Run the container
docker run -it triviacode-app
```
