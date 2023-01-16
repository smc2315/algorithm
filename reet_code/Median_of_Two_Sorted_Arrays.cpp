class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int i=0,j=0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        while(i<size1&&j<size2){
            if(nums1[i]>=nums2[j]){
                v.push_back(nums2[j++]);
            }
            else{
                v.push_back(nums1[i++]);
            }
        }
        while(i<nums1.size()){
            v.push_back(nums1[i++]);
        }
        while(j<nums2.size()){
            v.push_back(nums2[j++]);
        }
        int n = size1+size2;
        if(n%2==0){
            return (v[n/2]+v[n/2-1])/2.0;
        }
        return v[n/2];
    }
};
