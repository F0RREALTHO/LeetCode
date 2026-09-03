class Solution {
public:
    void f(int n, int k, int num, vector<int>& sbq, vector<vector<int>>& ans){
        if(sbq.size()==k){
            ans.push_back(sbq);
            return;
        }
        if(num<=n){
            sbq.push_back(num);
            f(n,k,num+1,sbq,ans);
            sbq.pop_back();
            f(n,k,num+1,sbq,ans);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> sbq;
        vector<vector<int>> ans;
        f(n,k,1,sbq,ans);
        return ans;
    }
};