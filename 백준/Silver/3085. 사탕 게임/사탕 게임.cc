#include <iostream>
#include <algorithm>

using namespace std;

int N;
char board[51][51];
int maxCandies = 0;
void count_max() {
    for (int i = 0; i < N; i++) {
        int count = 1;
        for (int j = 1; j < N; j++) {
            if (board[i][j] == board[i][j - 1]) {
                count++;
            } else {
                maxCandies = max(maxCandies, count);
                count = 1;
            }
        }
        maxCandies = max(maxCandies, count);
    }
    for (int i = 0; i < N; i++) {
        int count = 1;
        for (int j = 1; j < N; j++) {
            if (board[j][i] == board[j - 1][i]) {
                count++;
            } else {
                maxCandies = max(maxCandies, count);
                count = 1;
            }
        }
        maxCandies = max(maxCandies, count);
    }

}

int main() {
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin>>s;
        for (int j = 0; j < N; j++) {
            board[i][j] = s[j];
        }
    }

    

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            swap(board[i][j], board[i][j + 1]);
            count_max();
            swap(board[i][j], board[i][j + 1]);
        }
    }

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N - 1; i++) {
            swap(board[i][j], board[i + 1][j]);
            count_max();
            swap(board[i][j], board[i + 1][j]);
        }
    }

    cout << maxCandies << endl;

    return 0;
}