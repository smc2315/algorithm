
#include<iostream>
#include <vector>
#include <queue>
#define MAX 10002
using namespace std;
int V, E;
int snode[2];
vector<int> tree[MAX];
int depth[MAX];

int parents[MAX];
int sn[MAX];

void DFS(int node, int dep) {

    depth[node] = dep;
    sn[node] = 1;
    for (int i = 0; i < tree[node].size(); i++) {
        int next_node = tree[node][i];
        parents[next_node] = node;
       
        DFS(next_node, dep + 1);
        sn[node] +=sn[next_node];
    }
}

int LCA(int node_a, int node_b) {
    //cout << "LCA" << endl;
    if (node_a == node_b)
        return node_a;
    if (depth[node_a] == depth[node_b])
        return LCA(parents[node_a], parents[node_b]);
    else if (depth[node_a] > depth[node_b])
        return LCA(parents[node_a], node_b);
    else
        return LCA(node_a, parents[node_b]);
}


int main(int argc, char** argv)
{
    int test_case;
    int T;


    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        
        
        cin >> V >> E >> snode[0] >> snode[1];
        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
           // tree[b].push_back(a);
        }
        DFS(1, 0);
        int tmp = LCA(snode[0], snode[1]);
        //cout << tmp << endl;
        cout << "#" << test_case << " " << tmp << " " <<sn[tmp] << "\n";
        for (int i=1; i<=V; ++i) 
            if (!tree[i].empty())
               tree[i].clear();

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
