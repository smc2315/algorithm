#include <iostream>

using namespace std;

int N,M,R;
int arr[101][101];

void oper1(){
    int tmp_arr[101][101];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            tmp_arr[N-i-1][j] = arr[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            arr[i][j] = tmp_arr[i][j];
        }
    }
}

void oper2(){
    int tmp_arr[101][101];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            tmp_arr[i][M-1-j] = arr[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            arr[i][j] = tmp_arr[i][j];
        }
    }
}
void oper3(){
    int tmp_arr[101][101];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            tmp_arr[j][N-1-i] = arr[i][j];
        }
    }
    int tmp = N;
    N = M;
    M = tmp;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            arr[i][j] = tmp_arr[i][j];
        }
    }
}

void oper4(){
    int tmp_arr[101][101];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            tmp_arr[M-1-j][i] = arr[i][j];
        }
    }
    int tmp = N;
    N = M;
    M = tmp;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            arr[i][j] = tmp_arr[i][j];
        }
    }
}

void oper5(){
    int tmp_arr[101][101];
    for(int i=0;i<N/2;i++){
        for(int j=0;j<M/2;j++){
            tmp_arr[i][j] = arr[i+N/2][j];
        }
    }
    
    for(int i=0;i<N/2;i++){
        for(int j=M/2;j<M;j++){
            tmp_arr[i][j] = arr[i][j-M/2];
        }
    }

    for(int i=N/2;i<N;i++){
        for(int j=M/2;j<M;j++){
            tmp_arr[i][j] = arr[i-N/2][j];
        }
    }

    for(int i=N/2;i<N;i++){
        for(int j=0;j<M/2;j++){
            tmp_arr[i][j] = arr[i][j+M/2];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            arr[i][j] = tmp_arr[i][j];
        }
    }
}
void oper6(){
    int tmp_arr[101][101];
    for(int i=0;i<N/2;i++){
        for(int j=0;j<M/2;j++){
            tmp_arr[i][j] = arr[i][j+M/2];
        }
    }
    
    for(int i=0;i<N/2;i++){
        for(int j=M/2;j<M;j++){
            tmp_arr[i][j] = arr[i+N/2][j];
        }
    }

    for(int i=N/2;i<N;i++){
        for(int j=M/2;j<M;j++){
            tmp_arr[i][j] = arr[i][j-M/2];
        }
    }

    for(int i=N/2;i<N;i++){
        for(int j=0;j<M/2;j++){
            tmp_arr[i][j] = arr[i-N/2][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            arr[i][j] = tmp_arr[i][j];
        }
    }
}

int main() {
    cin>>N>>M>>R;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<R;i++){
        int r;
        cin>>r;
        switch (r){
        case 1:
            oper1();
            break;
        case 2:
            oper2();
            break;
        case 3:
            oper3();
            break;
        case 4:
            oper4();
            break;
        case 5:
            oper5();
            break;
        case 6:
            oper6();
            break;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}