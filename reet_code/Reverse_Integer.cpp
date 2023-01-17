class Solution {
public:
    int reverse(int x) {
        int res=0;
        
        while(x!=0){
            int tmp = x%10;
            if(res> INT_MAX/10 || (res == INT_MAX/10 && tmp>7))
                return 0;
            if(res<INT_MIN/10 || (res == INT_MIN/10 && tmp<-8))
                return 0;
            res = res*10 + tmp;
            x/=10;
        }
       
        return res;
    }
};
