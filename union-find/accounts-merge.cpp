class DisjointSet{
    public:
    vector<int> parent , rank;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i =0; i<=n; i++) parent[i]=i;
    }

    int findUpar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
    }

    void UnionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_v == ulp_u) return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mailToNode;
        for(int i =0; i<n;i++){
            for(int j=1; j<accounts[i].size();j++){
                string name = accounts[i][j];
                if(mailToNode.find(name)==mailToNode.end()){
                    mailToNode[name]=i;
                }else{
                    ds.UnionByRank(i,mailToNode[name]);
                }
            }
        }

        unordered_map<int,vector<string>> merged;
        for(auto &[mail,i]:mailToNode){
            merged[ds.findUpar(i)].push_back(mail);
        }

        vector<vector<string>> res;
        for(auto &[i,mails]:merged){
            sort(mails.begin(),mails.end());
            string name = accounts[i][0];
            mails.insert(mails.begin(),name);
            res.push_back(mails);
        }

        return res;
    }
};