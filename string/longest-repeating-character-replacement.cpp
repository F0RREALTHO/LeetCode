class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxlen = 0;
        int l = 0 , r = 0;
        int maxf = 0 , hash[26] = {0};
        while(r < n){
            hash[s[r] - 'A']++;
            maxf = max(maxf , hash[s[r] - 'A']);
            if((r - l + 1) - maxf > k){
                hash[s[l] - 'A']--;
                l = l + 1;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};