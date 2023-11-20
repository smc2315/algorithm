#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    deque<int> first_column;
    deque<int> last_column;
    vector<deque<int>> rows;
    int row_idx = 0;
    
    for(int i = 0; i < rc.size(); i++) {
        first_column.push_back(rc[i][0]);
        last_column.push_back(rc[i][rc[0].size() - 1]);
        deque<int> row;
        for(int j = 1; j < rc[0].size()-1; j++) {
            row.push_back(rc[i][j]);
        }
        rows.push_back(row);
    }
    
    for(int i = 0; i < operations.size(); i++) {
        if(operations[i] == "ShiftRow") {
            row_idx--;
            if(row_idx == -1) {
                row_idx = rc.size() - 1;
            }
            int tmp;
            tmp = first_column.back();
            first_column.pop_back();
            first_column.push_front(tmp);
            
            tmp = last_column.back();
            last_column.pop_back();
            last_column.push_front(tmp);
        }
        else if(operations[i] == "Rotate") {
            int tmp;
            tmp = first_column.front();
            first_column.pop_front();
            rows[row_idx].push_front(tmp);
            
            tmp = rows[row_idx].back();
            rows[row_idx].pop_back();
            last_column.push_front(tmp);
            
            tmp = last_column.back();
            last_column.pop_back();
            rows[(row_idx + rc.size() - 1) % rc.size()].push_back(tmp);
            
            tmp = rows[(row_idx + rc.size() - 1) % rc.size()].front();
            rows[(row_idx + rc.size() - 1) % rc.size()].pop_front();
            first_column.push_back(tmp);
        }
    }
    for(int i = 0; i < rc.size(); i++) {
        vector<int> row;
        int tmp;
        tmp = first_column.front();
        first_column.pop_front();
        row.push_back(tmp);
        
        int idx = i + row_idx;
        idx %= rc.size();
        while(!rows[idx].empty()) {
            tmp = rows[idx].front();
            rows[idx].pop_front();
            row.push_back(tmp);
        }
        tmp = last_column.front();
        last_column.pop_front();
        row.push_back(tmp);
        answer.push_back(row);
    }
    return answer;
}