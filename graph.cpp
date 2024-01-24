#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& graph, int first) {
    int n = graph.size();
    vector<bool> checked(n, false);
    stack<int> stc;
    stc.push(first);

    while (!stc.empty()) {
        int v = stc.top();
        stc.pop();

        if (!checked[v]) {
            checked[v] = true;
            cout << "Visited: " << v << endl;

            for (int i : graph[v]) {
                if (!checked[i]) {
                    stc.push(i);
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = { {1, 2}, {0, 2, 3}, {0, 1, 4}, {1}, {2} };
    int first = 0;

    dfs(graph, first);

    return 0;
}