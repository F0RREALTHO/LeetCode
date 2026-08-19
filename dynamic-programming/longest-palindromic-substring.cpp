class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // if(n==2 && s[0]==s[1]) return s;
        if(n<=1) return s;
        int st = 0, maxi =1;
        for(int i =0; i<n;){
            int l = i , r=i;
            while(r<n && s[i]==s[r]) r++;
            i=r;
            l--;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            int len = r-l-1;
            if(len>maxi){
                maxi = len;
                st = l+1;
            }
        }
        return s.substr(st,maxi);
    }
};

// a b b a
// a b a
// a a a
// a a - done