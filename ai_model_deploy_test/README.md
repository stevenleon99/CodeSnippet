# AI Model Deploy Test

Examples and tests for deploying machine learning models with inference capabilities.

## Contents

- **inference.py** - Model inference implementation
- **receive.py** - Receive and process model predictions
- **deploy_files/** - Deployment configuration and application files
  - `app.py` - Main application entry point
  - `requirements.txt` - Python dependencies

## Usage

```bash
# Install dependencies
pip install -r deploy_files/requirements.txt

# Run inference
python inference.py

# Receive predictions
python receive.py
```
