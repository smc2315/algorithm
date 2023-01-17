#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 1e9 


int arr[501][501];
int dist[501];

void bellmanford(int n) {
    
    dist[1] = 0;
    for (int i = 1; i < n; i++) {
        for (int from = 1; from <= n; from++) {
            for (int to = 1; to <= n; to++) {
                
                int d = arr[from][to] + dist[from];
                if (dist[to] > d) dist[to] = d;
            }
        }
    }


}
bool bellmanford2(int n) {
  
   
    for (int from = 1; from <= n; from++) {
        for (int to = 1; to <= n; to++) {

            int d = arr[from][to] + dist[from];
            if (dist[to] > d) 
                return true;
        }
    }
    
    return false;


}
bool comp(int* arr1,int*arr2,int n) {
    for (int i = 0; i <n; i++) {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;

}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;
    while(num--) {
        fill(dist, dist + 501, INF);
       
 
        int n, m, w;
        cin >> n >> m >> w;
        for (int i = 0; i <=n; i++) {
            for (int j = 0; j <= n; j++)
                arr[i][j] = INF;
        }
        for (int i = 0; i < m; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            if (arr[s][e] > t) {
                arr[s][e] = t;
            }
            if (arr[e][s] > t) {
                arr[e][s] = t;
            }


        }
        for (int i = 0; i < w; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            if (arr[s][e] > -t) {
                arr[s][e] = -t;
            }
        }
        
        bellmanford(n);
      
        bool check = bellmanford2(n);
        if (!check ){
            cout << "NO" << "\n";
        }
        else
            cout << "YES" << "\n";
    }
   
}