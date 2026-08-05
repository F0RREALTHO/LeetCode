class Solution {
public:
    void f(int k, int n, int sum, int idx, vector<int>& sbq, vector<vector<int>>& ans){
        if(sbq.size()==k){
            if(sum==n){
                ans.push_back(sbq);
            }
            return;
        }
        if(idx>9 || sum>n){
            return;
        }
        sbq.push_back(idx);
        f(k,n,sum+idx,idx+1,sbq,ans);
        sbq.pop_back();

        f(k,n,sum,idx+1,sbq,ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> sbq;

        f(k,n,0,1,sbq,ans);
        return ans;
    }
};