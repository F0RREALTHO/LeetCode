class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1;
            int k = n-1;
            while(l<k){
                int sum = nums[i]+nums[l]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[l],nums[k]});
                    if(l<k && nums[l]==nums[l+1]) l++;
                    if(l<k && nums[k]==nums[k-1]) k--; 
                    l++;
                    k--;
                }
                else if(sum<0) l++;
                else k--;
            }
        }
        return ans;
    }
};