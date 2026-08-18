class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long cur = LLONG_MAX, ans = 0;
        for(int i = 0 ; i< n; i++){
            int l = i+1;
            int r = n-1;
            while(l<r){
                long long sum = (long long)nums[i]+nums[l]+nums[r];
                if (llabs(sum - target) <= cur){
                    cur = llabs(sum-target);
                    ans = sum;
                }
                if(sum<target) l++;
                else if(sum>target)r--;
                else return target;
            }
        }
        return ans;
    }
};