class Solution {
public:
    bool isPalindrome(int x) {
        int save = x;
        if(x<0)
            return false;
        long tmp=0;
        while(x>0){
            tmp = tmp*10+x%10;
            x/=10;
        }
        cout<<tmp;
        if(tmp == save)
            return true;
    return false;
    }
};