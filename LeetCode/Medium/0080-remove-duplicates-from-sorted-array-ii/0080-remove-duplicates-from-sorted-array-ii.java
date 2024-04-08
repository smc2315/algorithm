class Solution {
    public int removeDuplicates(int[] nums) {
        int j = 1;
        int cnt = 1;
        for(int i = 1; i < nums.length; i++) {
            if(nums[i - 1] == nums[i]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            if(cnt <= 2) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
}