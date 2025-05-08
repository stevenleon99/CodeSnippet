specialSign = ['@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '{', '}', '[', ']', '|', ':', ';', '"', "'", '<', '>', ',', '.', '?', '/']
CapitalLetter = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
digit = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
smallLetter = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

# the following function should be lived in the product softwre module
def isPasswordValid(password: str) -> bool:
    # Implementation of password validation logic
    requirement = 5
    if len(password) >= 10: requirement -= 1
    if any(char in specialSign for char in password): requirement -= 1
    if any(char in CapitalLetter for char in password): requirement -= 1
    if any(char in digit for char in password): requirement -= 1
    if any(char in smallLetter for char in password): requirement -= 1
    
    if requirement == 0:
        return True
    else: return False

def save_to_db(item_json_info)->bool:
    print("the password is successfully saved to the database ...") # dummy function to simulate save to db
    print(item_json_info)
    return True


def generate_password(HLA: str, subsys: str, serialNum: str, ManufactureNum: str) -> str:
    # Implementation of password generation logic
    save_to_db({"HLA": HLA, "subsys": subsys, "serialNum": serialNum, "ManufactureNum": ManufactureNum, "password": "Steve123456@"})
    return "Steve123456@" # fixed password for testing - pass
    # return "Steve12@" # fixed password for testing - failed (shorter than 10 characters)
    # return "Steve123@" # fixed password for testing - failed (different from the password used in save_to_db)

if __name__ == "__main__":
    # Run the test
    print(generate_password("HLA1", "SubsystemA", "SN123456", "MFG987654"))
