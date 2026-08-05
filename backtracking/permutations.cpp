class Solution {
public:
    void f(vector<int>& a, vector<vector<int>>& ans, int idx, int n){
        if(idx==n){
            ans.push_back(a);
            return;
        }

        for(int j=idx; j<n; j++){
            swap(a[idx],a[j]);

            f(a,ans,idx+1,n);

            swap(a[idx],a[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();    
        vector<vector<int>> ans;


        f(nums,ans,0,n);

        return ans;
    }
};