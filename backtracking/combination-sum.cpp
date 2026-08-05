class Solution {
public:
    void f(vector<int>& a, int k, int idx, int n, vector<int>& sbq, vector<vector<int>>& ans){
        if(idx==n){
            if(k==0){
                ans.push_back(sbq);
            }
            return;
        }
        
        f(a,k,idx+1,n,sbq,ans);

        if(a[idx]<=k){
            sbq.push_back(a[idx]);
            f(a,k-a[idx],idx,n,sbq,ans);
            sbq.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> sbq;
        vector<vector<int>> ans;
        f(candidates,target,0,n,sbq,ans);
        return ans;
    }
};