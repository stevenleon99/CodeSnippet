import requests
from bs4 import BeautifulSoup

def extract_table_from_gdoc(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')

    table = soup.find('table')
    rows = table.find_all('tr')

    data = []
    for row in rows:
        cols = row.find_all(['td', 'th'])  # Include headers if any
        data.append([col.get_text(strip=True) for col in cols])
        
    return data



# Example link
url = 'https://docs.google.com/document/d/e/2PACX-1vQGUck9HIFCyezsrBSnmENk5ieJuYwpt7YHYEzeNJkIb9OSDdx-ov2nRNReKQyey-cwJOoEKUhLmN9z/pub'
table_data = extract_table_from_gdoc(url)
table_data = table_data[1:]  # Skip the header row if present

# print the extracted data according to the x, y coordinates
# for the place without data, print a blank space

maxR = 0
maxC = 0
for row in table_data:
    maxR = max(maxR, int(row[2]))
    maxC = max(maxC, int(row[0]))

rows = maxR+1     # number of rows (height)
cols = maxC+1     # number of columns (width)

grid = [[' ' for _ in range(cols)] for _ in range(rows)]

for rowData in table_data:
    # print(rowData)
    x = int(rowData[2])  # x coordinate
    y = int(rowData[0])  # y coordinate
    value = rowData[1]   # value at the coordinates
    grid[x][y] = value
  
for i in range(rows):
    for j in range(cols):
        print(grid[i][j], end='')
    print('')