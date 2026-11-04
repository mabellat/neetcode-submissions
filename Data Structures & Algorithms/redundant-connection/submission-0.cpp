class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0;i<n;i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> vis(edges.size()+1);
        for(int i = 1;i<=n;i++){
            if(!vis[edges[i-1][0]] or !vis[edges[i-1][1]]){
                vis[edges[i-1][0]] = true;
                vis[edges[i-1][1]] = true;
            }else return edges[i-1];
        }
        return {};
    }
};
