class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) {
            return {};
        }
        vector<string> v;
        int prev = nums[0];
        string s = to_string(prev);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != prev + 1) {
                if(stoi(s) != prev) {
                    s += "->" + to_string(prev);
                }
                v.push_back(s);
                s = to_string(nums[i]);
            }
            prev = nums[i];        
        }
        if(stoi(s) != prev) {
            s += "->" + to_string(prev);
        }
        v.push_back(s);
        return v;
    }
};