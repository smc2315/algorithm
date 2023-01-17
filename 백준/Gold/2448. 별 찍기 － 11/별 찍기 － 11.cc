#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

char arr[7000][7000];
int n;
void printstar(int n) {

}

void star(int num) {

    if (num <= 3) {
        return;
    }
    star(num / 2);

    for (int i = num / 2; i < num; i++) {
        for (int j = n-num; j < n; j++) {
            arr[i][j] = arr[i - num / 2][j + num / 2];
            arr[i][j + num] = arr[i - num / 2][j + num / 2];
        }
    }

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2; j++) {
            arr[i][j] = ' ';
        }
    }
    arr[0][n - 1] = '*';
    arr[1][ n - 2] = '*';
    arr[1][ n] = '*';
    arr[2][ n - 3] = '*';
    arr[2][n - 2] = '*';
    arr[2][n - 1] = '*';
    arr[2][n ] = '*';
    arr[2][ n +1] = '*';
    
    /*for (int i = 3; i <6; i++) {
        for (int j = 18; j < 24; j++) {
            arr[i][j] = arr[i - 3][j + 3];
            arr[i][j + 6] = arr[i - 3][j + 3];
        }
    }*/
    star(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
  

    return 0;

   
}