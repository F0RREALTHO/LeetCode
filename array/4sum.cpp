class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i =0; i<=n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j =i+1; j<=n-1; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int l = j+1, k = n-1;
                while(l<k){
                    int sum = nums[i]+nums[j]+nums[l]+nums[k];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[k]});
                        while(l<k && nums[l]==nums[l+1]) l++;
                        while(l<k && nums[k]==nums[k-1]) k--;
                        l++; k--;
                    }else if(sum<target) l++;
                    else k--;
                }
            }
        }
        return ans;
    }
};