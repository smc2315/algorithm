#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool selected[10];
bool max_selected[10];
int mmax;

void select(vector<vector<int>>& dice, vector<int>& sum_a, int n, int s, int sum, bool is_a) {
    if(n == dice.size() / 2) {
        sum_a.push_back(sum);
        return;
    }
    if(selected[s] == is_a) {
        for(int i = 0; i < 6; i++) {
            select(dice, sum_a, n + 1, s + 1, sum + dice[s][i], is_a);
        }
    }
    else {
        select(dice, sum_a, n, s + 1, sum, is_a);
    }
}

void check_win_rate(vector<vector<int>>& dice) {
    vector<int> sum_a;
    vector<int> sum_b;
    select(dice, sum_a, 0, 0, 0, true);
    select(dice, sum_b, 0, 0, 0, false);
    sort(sum_a.begin(), sum_a.end());
    sort(sum_b.begin(), sum_b.end());
    int cnt = 0;
    
    for(int i = 0; i < sum_a.size(); i++) {
        cnt += lower_bound(sum_b.begin(), sum_b.end(), sum_a[i]) - sum_b.begin();
    }
    if(cnt > mmax) {
        mmax = cnt;
        for(int i = 0; i < dice.size(); i++) {
            max_selected[i] = selected[i];
        }
    }
}

void select_dice(vector<vector<int>>& dice, int n, int m, int s) {
    if(n == m) {
        check_win_rate(dice);
        return;
    }
    for(int i = s; i < 2 * n; i++) {
        selected[i] = true;
        select_dice(dice, n, m + 1, i + 1);
        selected[i] = false;
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int size = dice.size();
    select_dice(dice, size/2, 0, 0);
    
    for(int i = 0; i < size; i++) {
        if(max_selected[i]) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}