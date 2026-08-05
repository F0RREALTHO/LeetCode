class Solution {
public:
    int numberOfMatches(int n) {
        // int p = 0;
        // while(n!=1){
        //     if(!(n&1)){
        //         p+=n/2;                
        //         n =n/2;
        //     }else{
        //         p+=(n-1)/2;                
        //         n = (n-1)/2 +1;
        //     }
        // }
        return n-1;
    }
};