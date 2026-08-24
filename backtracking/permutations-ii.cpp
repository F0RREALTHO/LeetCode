class Solution {
public:
    void f(vector<int>& a, vector<vector<int>>& ans, int idx, int n){
        if(idx==n){
            ans.push_back(a);
            return;
        }

        for(int j=idx; j<n; j++){
            if(j>idx && a[j]==a[idx]) continue;
            swap(a[idx],a[j]);

            f(a,ans,idx+1,n);

            swap(a[idx],a[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());    
        vector<vector<int>> ans;


        f(nums,ans,0,n);

        return ans;
    }
};