#include <iosteam>
#include <vector>

using namespace std;

int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
void dfs(vector<vector<int>>grid, vector<vector<bool>> isVisited, int x, int y){
    if (isVisited[x][y] || grid[x][y] == 0) return;
    isVisited[x][y] = true;
    for (int i=0; i<4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
        dfs(grid, isVisited, nextx, nexty);
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

    int result=0;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (isVisited[i][j] == false && grid[i][j] == 1) {
                result ++;
                dfs(grid, visited, i, j);
            }
        }
    }
    return 0;
}
