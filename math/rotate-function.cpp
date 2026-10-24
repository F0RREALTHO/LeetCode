class Solution {
public:
    #define ll long long
    int score(vector<int>& nums, ll &n){
        ll s = 0;
        for(int i=0;i<n;i++){
            s+= i*nums[i];
        }
        return s;
    }
    int maxRotateFunction(vector<int>& nums) {
        ll n = nums.size();
        ll maxi = score(nums,n);
        ll prev= maxi;
        ll curr;
        ll sumy = accumulate(nums.begin(),nums.end(),0);
        for(int i=1; i<n; i++){
            curr = prev + sumy - n*nums[n-i];
            prev = curr;
            if(curr>maxi) maxi = curr;
        }
        return maxi;
    }
};