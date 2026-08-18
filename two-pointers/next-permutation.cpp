class Solution {
public:
    void f(vector<int>& nums, int n, set<vector<int>>& ans, vector<int>& cur, vector<bool>& vis){
        if(cur.size()==n){
            ans.insert(cur);
            return;
        }
        for(int i=0; i<n; i++){
            if(vis[i]) continue;
            vis[i]=true;
            cur.push_back(nums[i]);

            f(nums,n,ans,cur,vis);
            vis[i]=false;
            cur.pop_back();
        }
    }
    void nextPermutation(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();

        vector<bool> vis(n, false);
        vector<int> cur;
        f(nums,n,ans,cur,vis);

        auto it = ans.find(nums);
        it++;

        if(it==ans.end())
            nums = *ans.begin();
        else
            nums = *it;
    }
};