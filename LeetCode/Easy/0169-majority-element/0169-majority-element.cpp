class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int cur = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                cur = nums[i];
            }
            if(nums[i] == cur) {
                count++;
            }
            else {
                count--;
            }
        }
        return cur;
    }
};