#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int r1,c1,r2,c2;
int n,m;
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int point_to_value(int x, int y) {
    x = x-5000;
    y = y -5000;
    int ret = 1;
    if(abs(x) > abs(y)) {
        if(x<0){
            int tmp =abs(x);
            int cnt = 0;
            while(tmp--){
                ret+=3 + 8*cnt++;
            }
            return ret-y;
        }
        else{
            int tmp =abs(x);
            int cnt = 0;
            while(tmp--){
                ret+=7 + 8*cnt++;
            }
            return ret+y;
        }
        
    }
    else if(abs(x) <abs(y)){
        if(y<0){
            int tmp =abs(y);
            int cnt = 0;
            while(tmp--){
                ret+=5 + 8*cnt++;
            }
            return ret+x;
        }
        else{
            int tmp =abs(y);
            int cnt = 0;
            while(tmp--){
                ret+=1 + 8*cnt++;
            }
            return ret-x;
        }
        
    }
    else {
        if(x>0 && y>0){
            int tmp =abs(y);
            int cnt = 0;
            while(tmp--){
                ret += 8+ 8*cnt++;
            }
            return ret;
        }
        else if(x>0 && y<0){
            int tmp =abs(y);
            int cnt = 0;
            while(tmp--){
                ret += 6 + 8*cnt++;
            }
            return ret;
        }
        else if(x<0 && y> 0){
            int tmp =abs(y);
            int cnt = 0;
            while(tmp--){
                ret += 2 + 8*cnt++;
            }
            return ret;
        }
        else{
            int tmp =abs(y);
            int cnt = 0;
            while(tmp--){
                ret += 4 + 8*cnt++;
            }
            return ret;
        }
    }
}
int get_max_digit(int num) {
    int digits = 0;
    if (num == 0)
        return 1;

    while (num != 0) {
        num /= 10;
        digits++;
    }
    return digits;
}
int main() {
    cin>>r1>>c1>>r2>>c2;
    int mmax = 0;

    for(int i=r1+5000;i<r2+5000+1;i++){
        for(int j=c1+5000;j<c2+5000+1;j++){
            mmax = max(mmax, point_to_value(i, j));
        }
    }
    int max_digit = get_max_digit(mmax);
    for(int i=r1+5000;i<r2+5000+1;i++){
        for(int j=c1+5000;j<c2+5000+1;j++){
            printf("%*d ", max_digit, point_to_value(i,j));
        }
        printf("\n");
    }
    
}