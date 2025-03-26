#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
int dir[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
map<int, int> mp;
int count;

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int x, int y, int marked){
    if (isVisited[x][y] || grid[x][y] == 0) return;

    isVisited[x][y] = true;
    grid[x][y] = marked;
    count++;
    for (int i=0; i<4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || 
            nexty < 0 || 
            nextx >= grid.size() || 
            nexty >= grid[0].size()) continue;
        dfs(grid, isVisited, nextx, nexty, marked);
    }

    return;
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
    int marked=2;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == 1 && isVisited[i][j] == false){
                count = 0;
                dfs(grid, isVisited, i, j, marked);
                mp[marked] = count;
                cout << "count: " << count << endl;
                marked++;
            }
        }
    }
    int result = INT_MIN;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++) {
            set<int> st;
            if (grid[i][j] == 0) {
                for (int k=0; k<4; k++){
                    int landx = i + dir[k][0];
                    int landy = j + dir[k][1];
                    if (landx < 0 || landy < 0 || landx >= grid.size() || landy >= grid[0].size()) continue;
                    st.insert(grid[landx][landy]);
                }
                int cur_result = 0;
                for (auto l : st) {
                    std::cout << "st: " << l << " " << mp[l] << std::endl;
                    cur_result += mp[l];
                }
                result = max(result, cur_result+1);
            }
        }
    }
    std:: cout << "result is " << result << std::endl;
    return 0;
}
