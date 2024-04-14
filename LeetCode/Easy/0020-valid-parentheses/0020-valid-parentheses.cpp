class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> matching = {{')', '('}, {'}', '{'}, {']', '['}};
        
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                stk.push(c);
            }
            else {
                if(stk.empty() || stk.top() != matching[c]) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};