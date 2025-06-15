#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

const int MAX_V = 100;
const int INF = 987654321;

int V = 11; // 간선의 수
// vector<pair<이웃 노드, 가중치>> adj[현재 노드]
vector<pair<int, int> > adj[MAX_V];

// selected 변수: 선택한 간선의 정점 정보가 저장됨
int prim(vector<pair<int, int> >& selected) {
    selected.clear(); // 시작이니까 벡터 비우기

    // 현재 트리에 어떤 정점이 있는지 체크
    // 처음이니까 모두 false로 함
    vector<bool> added(V, false);
    // 이웃한 정점 중 가장 가까운 정점
    // parent: 정점의 부모
    vector<int> minWeight(V, INF), parent(V, -1);

    int ret = 0; // 모든 간선의 값
    //0의 부모는 자기 자신이고 자기 자신과의 거리는 0
    minWeight[0] = parent[0] = 0;
    for (int iter = 0; iter < V; iter++) {
        int u = -1; // u가 첫 시작점일 때
        for (int v = 0; v < V; v++) {
            if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
                u = v;
        }

        if (parent[u] != u)
            // selected에 저장
            selected.push_back(make_pair(parent[u], u));

        ret += minWeight[u];
        added[u] = true; // 방문하였음

        for (int i = 0; i < adj[u].size(); i++) {
            // v: u와 인접한 정점
            // weight: 가중치
            int v = adj[u][i].first, weight = adj[u][i].second;
            if (!added[v] && minWeight[v] > weight) {
                parent[v] = u;
                minWeight[v] = weight; // 작으면 수정하기
            }
        }
    }
    return ret; // ret 값 반환
}

int main() {
    ifstream fp("FIN_1.txt"); // Input할 파일
    char line[100];
    int n = 0; // 해당 파일의 라인 수
    while (!fp.eof()) {
        fp >> line;
        n++;
    }
    fp.close();

    ifstream fp2("FIN_1.txt"); // 읽을 파일
    if (fp2.is_open()) {
        // 해당 파일의 라인 수 만큼 반복
        for (int i = 0; i < n; i++) {
            // 현재 노드, 이웃 노드, 가중치
            int u, v, w;
            fp2 >> u >> v >> w;
            // 저장하기
            adj[v].push_back(make_pair(v, w));
        }
    }
    else cout << "파일이 존재하지 않습니다." << endl;
    fp2.close();

    vector<pair<int, int> > selected;
    int mst = prim(selected);
    cout << "mst: " << mst << endl;

    for (int i = 0; i < selected.size(); i++) {
        cout << selected[i].first << "-" << selected[i].second << endl;
    }
    cout << endl;
}