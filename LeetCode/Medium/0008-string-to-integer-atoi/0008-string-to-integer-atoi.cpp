class Solution {
public:
    int myAtoi(string s) {
        int res=0;
        int minus = 1;
        int i=0;
        while(s[i]==' ')
            i++;
        
        if(s[i] == '-'){
            minus = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        else{
            if(s[i]<'0'||s[i]>'9')
                return 0;
        }
        while(i<s.size()&&s[i]>='0'&&s[i]<='9'){
            int tmp = minus*(s[i] - '0');
            cout<<res<<" "<<tmp<<endl;
            if(res>INT_MAX/10 || res<INT_MIN/10 || (res==INT_MAX/10 && tmp > 7) || (res==INT_MIN/10 && tmp < -8)){
                if(minus == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            res=res*10+tmp;
            i++;
        }
        

        
        return res;
    }
};