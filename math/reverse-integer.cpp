class Solution {
public:
    int reverse(int x) {
        int rev =0;
        while(x!=0){
            int dig = x%10;
            x/=10;
            rev = rev*10+dig; 
        }
        return rev;
    }
};