class Solution {
public:
    void f(vector<int>& a, int n, int idx,vector<int>& sbq,vector<vector<int>>& ans){
        if(idx==n){
            ans.push_back(sbq);
            return;
        }

        sbq.push_back(a[idx]);
        f(a,n,idx+1,sbq,ans);
        sbq.pop_back();
        f(a,n,idx+1,sbq,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sbq;
        vector<vector<int>> ans;
        int n = nums.size();

        f(nums,n,0,sbq,ans);

        return ans;
    }
};