class Solution {
public:
    int minOperations(string s) {
        string a = s;
        sort(a.begin(),a.end());
        if(a==s) return 0;

        int n = s.size();
        char smol = 'z', bigg = ' '; int smol_idx = 0, big_idx = 0;
        for(int i =0;i<n;i++){
            if(s[i]<smol){
                smol = s[i];
                smol_idx= i;
            }if(s[i]>=bigg){
                bigg=s[i];
                big_idx = i;
            }
        }
        if(n==2 && smol_idx==1 && big_idx==0){
            return -1;
        }
        if(smol_idx ==0 || big_idx ==n-1){
            return 1;
        }
        if(smol_idx==n-1 && big_idx ==0){
            return 3;
        }
        return 2;

    }
};