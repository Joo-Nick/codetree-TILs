#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 100000

using namespace std;

int n;
vector<pair<int, int>> edges[MAX_N + 1];
bool visited[MAX_N + 1];
int dist[MAX_N + 1];

void DFS(int x) {

    for(pair<int,int> e:edges[x]){
        int y = e.first;
        int d = e.second;

        if(!visited[y]){
            visited[y] = true;
            dist[y] = dist[x] + d;
            DFS(y);
        }
    }
}

// x랑 가장 먼 정점의 번호, x와 그 점 사이의 거리
pair<int, int> FindFarthestVertex(int x) {
    for(int i = 1; i <= n; i++) {
        visited[i] = false;
        dist[i] = 0;
    }

    visited[x] = true;
    dist[x] = 0;
    DFS(x);

    int farthest_dist = -1;
    int farthest_vertex = -1;
    for(int i = 1; i <= n; i++) {
        if(dist[i] > farthest_dist) {
            farthest_dist = dist[i];
            farthest_vertex = i;
        }
    }

    return {farthest_vertex, farthest_dist};
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int x,y,d;
        cin >> x >> y >> d;

        edges[x].push_back({y,d});
        edges[y].push_back({x,d});
    }

    int f_vertex;
    tie(f_vertex, ignore) = FindFarthestVertex(1);

    int diameter;
    tie(ignore, diameter) = FindFarthestVertex(f_vertex);

    cout << diameter;

    return 0;
}