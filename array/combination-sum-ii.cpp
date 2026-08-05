class Solution {
public:

    void f(vector<int>& a, int k, int idx, int n, vector<int>& sbq, vector<vector<int>>& ans){
        if(k==0){
            ans.push_back(sbq);
            return;
        }
        if(idx==n){
            return;
        }

        if(a[idx]<=k){
            sbq.push_back(a[idx]);
            f(a,k-a[idx],idx+1,n,sbq,ans);
            sbq.pop_back();
        }

        while(idx+1<n && a[idx]==a[idx+1]) idx++;
        f(a,k,idx+1,n,sbq,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> sbq;
        f(candidates,target,0,n,sbq,ans);

        return ans;
    }
};