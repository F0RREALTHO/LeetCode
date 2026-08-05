class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int n = answers.size();

        for(int i = 0; i < n ; i++){
            if(mp[answers[i]]){
                mp[answers[i]]--;
                continue;
            }
            mp[answers[i]] = answers[i];
        }

        int ans = n;
        for(auto [num,cnt]:mp){
            ans+=cnt;
        }

        return ans;
    }
};