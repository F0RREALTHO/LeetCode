class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(q.size()){
            auto [x,y] = q.front();
            q.pop();
            if(x==endWord){
                return y;
            }
            for(int i = 0; i<x.size(); i++){
                char ori = x[i];
                for(char s = 'a'; s<='z';s++){
                    x[i]=s;
                    auto it = st.find(x);
                    if(it!=st.end()){
                        st.erase(x);
                        q.push({x,y+1});
                    }
                }
                x[i]=ori;
            }
        }
        return 0;
    }
};