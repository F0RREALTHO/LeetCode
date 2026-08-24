class Solution {
public:
    void f(vector<int>& a, vector<vector<int>>& ans, int idx, int n){
        if(idx==n){
            ans.push_back(a);
            return;
        }

        unordered_set<int> st;
        for(int j=idx; j<n; j++){
            if(st.count(a[j])) continue;
            st.insert(a[j]);

            swap(a[idx],a[j]);

            f(a,ans,idx+1,n);

            swap(a[idx],a[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();  
        vector<vector<int>> ans;


        f(nums,ans,0,n);

        return ans;
    }
};