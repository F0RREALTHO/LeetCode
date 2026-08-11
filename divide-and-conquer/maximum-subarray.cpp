class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=nums[0], cur=nums[0];
        for(int i=1;i<nums.size();i++){
            cur=max(nums[i],cur+nums[i]);
            maxi=max(maxi,cur);
        }
        return maxi;
    }
};