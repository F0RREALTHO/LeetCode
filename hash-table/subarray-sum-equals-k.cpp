class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n+2,0);

        for(int i =1; i<=n; i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        unordered_map<int,int> mp;
        int cnt = 0;
        for(int i =1; i<=n; i++){
            if(pre[i]==k) cnt++;
            if(mp.find(pre[i]-k)!=mp.end()) cnt+=mp[pre[i]-k];
            mp[pre[i]]++;
        }


        return cnt;
    }
};