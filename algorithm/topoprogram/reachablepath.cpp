#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs(vector<vector<int>> graph, int x, int y){
    if (x == y) {
        result.push_back(path);
        return;
    }

    for (int i=1; i<=y; i++){
        if (graph[x][i] ==1) {
            path.push_back(i);
            dfs(graph, i, y);
            path.pop_back();
        }
    }
}


int main(int argc, char const *argv[])
{
    int n, m, s, t;
    cin >> n >> m;

    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));

    while(m--) {
        cin >> s >> t;
        graph[s][t] = 1;
    }
    path.push_back(1);
    dfs(graph, 1, n);

    // print the result

    return 0;
}
