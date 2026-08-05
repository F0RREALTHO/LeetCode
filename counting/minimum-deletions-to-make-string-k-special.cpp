class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> mp;
        for(char c: word) mp[c]++;
        
        vector<int> freq;
        for(auto &[ch,f]:mp) freq.push_back(f);
        sort(freq.begin(),freq.end());

        int n = freq.size();
        int ans = INT_MAX;

        for(int i = 0; i<n; i++){
            int del = 0;
            int target = freq[i];
            for(int j =0; j<n ; j++){
                if(freq[j]>target+k) del+=freq[j]-(target+k);
                else if (target>freq[j]) del+=freq[j];
            }
            ans = min(ans,del);
        }

        
        return ans;
    }
};