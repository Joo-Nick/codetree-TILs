#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[100001];
bool visited[100001];
int parent[100001];

void Dfs(int x) {
    for(int i = 0; i < (int) edges[x].size(); i++){
        int y = edges[x][i];
        if(!visited[y]){
            visited[y] = true;
            parent[y] = x;

            Dfs(y);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        int x, y;
        cin >> x >> y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    visited[1] = true;
    Dfs(1);

    for(int i = 2; i <= n; i++)
        cout << parent[i] << endl;
    return 0;
}