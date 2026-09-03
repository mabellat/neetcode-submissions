class Solution {
public:

    void bfs(int node, int n, vector<bool> &vis, unordered_map<int, vector<int>> &mp){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            vis[x] = true;
            for(auto it: mp[x]){
                if(!vis[it]){
                    q.push(it);
                }
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // we write the traversal over all the unvisited nodes

        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> mp(n);
        for(int i = 0;i < edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        // now we have the adjacency list as well as the vis
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans++;
                bfs(i, n, vis, mp);
            }   
        }
        return ans;
    }
};
