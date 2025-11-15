# Base image
FROM python:3.11-slim

# Set working directory inside container
WORKDIR /dockerfile

# Copy files from host into container
COPY . .

# Install dependencies
RUN pip install --no-cache-dir -r requirements.txt

# Run the application
CMD ["python", "app.py"]
