class Solution {
public:
    void make_sbarry(vector<int>& nums, vector<int>& ans,int idx, int n, unordered_set<int>& a){
        if(idx==n) return;
        a.insert(nums[idx]);
        ans.push_back(a.size()*a.size());
        make_sbarry(nums,ans,idx+1,n,a);
    }
    int sumCounts(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i =0;i<n;i++){
            unordered_set<int> a;
            make_sbarry(nums,ans,i,n,a);
        }
        return accumulate(ans.begin(),ans.end(),0); 
    }
};