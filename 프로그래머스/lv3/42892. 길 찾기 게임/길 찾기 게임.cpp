#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

pair<int,int> tree[10001];
map<int,pair<int,int>> m;

vector<int> frontpath; 
vector<int> endpath;

struct edge { 
    int idx, x, y;
};

bool cmp(edge a, edge b) {
    if(a.y == b.y) {
        return a.x < b.x;
    }
    else
        return a.y > b.y;
}

void find(int now, edge e) { 
    pair<int,int> nowpos = m[now];
    if(nowpos.first > e.x) { 
        if(tree[now].first == now) { 
            tree[now].first = e.idx;
            return;
        }
        else {
            find(tree[now].first, e);
        }
    }
    else {
        if(tree[now].second == now) {
            tree[now].second = e.idx;
            return;
        }
        else {
            find(tree[now].second, e);
        }
    }
    return;
}

void front(int now) { 
    frontpath.push_back(now);
    if(tree[now].first != now) { 
        front(tree[now].first);
    }
    if(tree[now].second != now) {
        front(tree[now].second);
    }
}

void end(int now) { 
    if(tree[now].first != now) { 
        end(tree[now].first);
    }
    if(tree[now].second != now) {
        end(tree[now].second); 
    }
    endpath.push_back(now);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<edge> node;
    
    for(int i = 1; i <= nodeinfo.size(); i++) { 
        tree[i].first = i; 
        tree[i].second = i; 
    }
    
    for(int i = 0;i < nodeinfo.size(); i++) { 
        node.push_back({i+1, nodeinfo[i][0], nodeinfo[i][1]}); 
        m[i+1] = {nodeinfo[i][0], nodeinfo[i][1]}; 
    }
    sort(node.begin(), node.end(), cmp);
    
    int root = node[0].idx; 
    
    for(int i = 1; i < node.size(); i++) {
        edge now = node[i]; 
        find(root, now);
    }
    
    front(root);
    end(root);
    
    
    answer.push_back(frontpath);
    answer.push_back(endpath);
    
    return answer;
}