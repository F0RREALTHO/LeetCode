class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0, r = nums[n-1]-nums[0] , ans = -1;

        while(l<=r){
            int m = (l+r)/2 , pa = 0;
            for(int i =0; i<n-1; i++){
                if(m>=nums[i+1]-nums[i]){
                    pa++;
                    i++;
                }
            }
            if(pa>=p) {
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};