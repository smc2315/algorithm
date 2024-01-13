#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> edge_info(101);
int visited[101];
int targets[101];
vector<int> order;

void drop() {
    int node = 1;
    while(true) {
        if(edge_info[node].size()) {  
            int prev = node;
            node = edge_info[node][visited[node] % edge_info[node].size()];
            visited[prev]++;
        }
        else {
            targets[node]++;
            order.push_back(node);
            
            return;
        }
    }
}

bool check(vector<int> &target) {
    for(int i = 0; i < target.size(); i++) {
        if(targets[i + 1] > target[i] || target[i] > targets[i + 1] * 3) {
            return false;
        }
    }
    return true;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    for(int i = 0; i < edges.size(); i++) {
        edge_info[edges[i][0]].push_back(edges[i][1]);
    }
    
    for(int i = 0; i < edge_info.size(); i++) {
        sort(edge_info[i].begin(), edge_info[i].end());
    }
    int cnt = 0;
    while(cnt++ <= 1000) {
        drop();
        bool chk = check(target);
        if(chk) {
            for(int i = order.size() - 1; i >= 0; i--) {
                int tmp = targets[order[i]] - 1;
                if(target[order[i] - 1] >= 3 && target[order[i] - 1] - 3 >= tmp && target[order[i] - 1] - 3 <= tmp * 3) {
                    target[order[i] - 1] -= 3;
                    targets[order[i]]--;
                    answer.push_back(3);
                }
                else if(target[order[i] - 1] >= 2 &&target[order[i] - 1] - 2 >= tmp && target[order[i] - 1] - 2 <= tmp * 3) {
                    target[order[i] - 1] -= 2;
                    targets[order[i]]--;
                    answer.push_back(2);
                }
                else if(target[order[i] - 1] > 0) {
                    target[order[i] - 1]--;
                    targets[order[i]]--;
                    answer.push_back(1);
                }
            }
            break;
        }
    }
    for(int i = 0; i < order.size(); i++) {
        cout<<order[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < 11; i++) {
        cout << target[i] << " ";
    }
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}