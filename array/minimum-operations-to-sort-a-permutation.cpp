class Solution {
public:
    int minOperations(vector<int>& nums) {
        int smol_idx = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]==0) {smol_idx =i; break;}
        }
        bool inc = true, dec = true;
        
        for(int i =0;i<n;i++){
            if(nums[(i+1)%n]!=(nums[i]+1)%n) inc = false;
            if(nums[(i+1)%n]!=(nums[i]-1+n)%n) dec = false;
        }
        if(inc) return min(smol_idx,n-smol_idx+2);
        if(dec){
            return min(n - smol_idx, smol_idx + 2);
        }
        return -1;
    }
};