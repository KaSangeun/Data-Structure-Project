#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

const int MAX_V = 100;
const int INF = 987654321;

int V = 11; // ������ ��
// vector<pair<�̿� ���, ����ġ>> adj[���� ���]
vector<pair<int, int> > adj[MAX_V];

// selected ����: ������ ������ ���� ������ �����
int prim(vector<pair<int, int> >& selected) {
    selected.clear(); // �����̴ϱ� ���� ����

    // ���� Ʈ���� � ������ �ִ��� üũ
    // ó���̴ϱ� ��� false�� ��
    vector<bool> added(V, false);
    // �̿��� ���� �� ���� ����� ����
    // parent: ������ �θ�
    vector<int> minWeight(V, INF), parent(V, -1);

    int ret = 0; // ��� ������ ��
    //0�� �θ�� �ڱ� �ڽ��̰� �ڱ� �ڽŰ��� �Ÿ��� 0
    minWeight[0] = parent[0] = 0;
    for (int iter = 0; iter < V; iter++) {
        int u = -1; // u�� ù �������� ��
        for (int v = 0; v < V; v++) {
            if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
                u = v;
        }

        if (parent[u] != u)
            // selected�� ����
            selected.push_back(make_pair(parent[u], u));

        ret += minWeight[u];
        added[u] = true; // �湮�Ͽ���

        for (int i = 0; i < adj[u].size(); i++) {
            // v: u�� ������ ����
            // weight: ����ġ
            int v = adj[u][i].first, weight = adj[u][i].second;
            if (!added[v] && minWeight[v] > weight) {
                parent[v] = u;
                minWeight[v] = weight; // ������ �����ϱ�
            }
        }
    }
    return ret; // ret �� ��ȯ
}

int main() {
    ifstream fp("FIN_1.txt"); // Input�� ����
    char line[100];
    int n = 0; // �ش� ������ ���� ��
    while (!fp.eof()) {
        fp >> line;
        n++;
    }
    fp.close();

    ifstream fp2("FIN_1.txt"); // ���� ����
    if (fp2.is_open()) {
        // �ش� ������ ���� �� ��ŭ �ݺ�
        for (int i = 0; i < n; i++) {
            // ���� ���, �̿� ���, ����ġ
            int u, v, w;
            fp2 >> u >> v >> w;
            // �����ϱ�
            adj[v].push_back(make_pair(v, w));
        }
    }
    else cout << "������ �������� �ʽ��ϴ�." << endl;
    fp2.close();

    vector<pair<int, int> > selected;
    int mst = prim(selected);
    cout << "mst: " << mst << endl;

    for (int i = 0; i < selected.size(); i++) {
        cout << selected[i].first << "-" << selected[i].second << endl;
    }
    cout << endl;
}