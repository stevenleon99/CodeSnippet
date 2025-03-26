#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};

void bfs(vector<vector<int>> const& grid, vector<vector<bool>>& isVisited, int x, int y, int& count){
    queue<vector<int>> que;
    que.push({x, y});
    while (!que.empty()){
        vector<int> temp = que.front();
        que.pop();
        for (int i=0; i<4; i++){
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx<0 || nextx>=grid.size() || nexty<0 || nexty >= grid[0].size()) continue;
            que.push({nextx, nexty});
            isVisited[nextx][nexty] = true;
            count++;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    int result = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == 1 && isVisited[i][j] == false) {
                int count = 1;
                bfs(grid, isVisited, i, j, count);
                result = max(result, count);
            }
        }
    }
    return 0;
}

