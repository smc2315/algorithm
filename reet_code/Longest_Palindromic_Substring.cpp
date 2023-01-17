class Solution {
public:
    string longestPalindrome(string s) {

        if(s=="")
            return s;
        string res;
        int mmax = 0;
        for(int i=0;i<s.size();i++){
            int len1 =expand(s,i,i);
            int len2 = expand(s,i,i+1);
            if(len1>len2){
                if (len1 > mmax) {
                    mmax = len1;
                    res = s.substr(i-len1/2,len1);
                }
            }
            else{
                if(len2 > mmax){
                    mmax = len2;
                    res = s.substr(i-len2/2+1,len2);
                }
            }

        }
        cout<<mmax;
        return res;
    }
    int expand(string s,int left, int right){
        while(left>=0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right-left-1;
    } 
    
};
