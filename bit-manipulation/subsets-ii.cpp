class Solution {
public:
    void f(vector<int>& a, int n, int idx, vector<int>& sbq, vector<vector<int>> &ans){
        if(idx==n){
            ans.push_back(sbq);
            return;
        }

        sbq.push_back(a[idx]);
        f(a,n,idx+1,sbq,ans);
        sbq.pop_back();

        while(idx+1<n && a[idx]==a[idx+1]) idx++;
        f(a,n,idx+1,sbq,ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> sbq;
        vector<vector<int>> ans;

        int n = nums.size();
        f(nums,n,0,sbq,ans);
        
        return ans;
    }
};