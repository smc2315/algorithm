class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> v;
        v.push_back(0);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= target) {
                return 1;
            }
            v.push_back(v[i] + nums[i]);
        }

        int l = 0;
        int r = 2;
        int answer = 1e9;
        while(l < v.size() && r < v.size()) {
            if(v[r] - v[l] >= target) {
                if(answer > r - l) {
                    answer = r - l;
                }
                l++;
            }
            else {
                r++;
            }
        }
        return answer == 1e9 ? 0 : answer;
    }
};