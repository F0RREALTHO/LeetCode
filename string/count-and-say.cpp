class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        for(int i =1; i<n;i++){
            char ch;
            string temp="";
            for(int j=0; j<cur.size();){
                int k=j;
                ch = cur[j];
                while(k<cur.size() && cur[k]==ch) k++;
                temp+=to_string(k - j);
                temp+=cur[j];
                j=k; 
            }
            cur =temp;
        }
        return cur;
    }
};