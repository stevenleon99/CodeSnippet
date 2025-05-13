#include <iostream>
#include <vector>

using namespace std;
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int count;

void dfs(vector<vector<int>>& grid, int x, int y){
    for (int i=0; i<4; i++) {
        int sidex = x + dir[i][0];
        int sidey = y + dir[i][1];
        if (sidex < grid.size() && sidex >=0 && sidey < grid[0].size() && sidey >=0) {
            if (grid[sidex][sidey] == 0) count++;

        }
    }
    grid[x][y] = 2;
    for (int i=0; i<4; i++) {
        int sidex = x + dir[i][0];
        int sidey = y + dir[i][1];
        if (sidex < grid.size() && sidex >=0 && sidey < grid[0].size() && sidey >=0) {
            if (grid[sidex][sidey] == 1) {
                dfs(grid, sidex, sidey);
            }

        }
    }
}

int main(int argc, const char** argv) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid (n, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> result;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            count = 0;
            if (grid[i][j] == 1) {
                dfs(grid, i, j);
            }
            if (count) result.push_back(count);
        }
    }

    for (int i=0; i<result.size(); i++) {
        cout << "idx " << i << ": " << result[i] << endl;
    }
    
    return 0;
}