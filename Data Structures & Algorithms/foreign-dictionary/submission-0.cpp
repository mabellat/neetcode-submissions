class Solution {
public:
    vector<int> topoSort(unordered_map<int, vector<int>> &mp){
        int n = mp.size();
        vector<int> indegree(n, 0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<mp[i].size();j++){
                indegree[mp[i][j]]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: mp[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }

    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        // first we need to initialize the indegree vector to 0, in order to ensure we have all the letters in the map
        for(auto it: words){
            for(char c: it){
                if(!indegree.count(c)){
                    indegree[c] = 0;
                }
            }
        }
        for(int i = 0;i<n-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.length(), s2.length());
            if(s1.size() > s2.size() && s1.substr(0, len) == s2.substr(0, len)) return "";
            for(int j = 0;j<len;j++){
                if(s1[j]!=s2[j]){
                    if(!adj[s1[j]].count(s2[j])){
                        adj[s1[j]].insert(s2[j]);
                        indegree[s2[j]]++;
                    }
                    break;
                }
            }
        }
        queue<char> q;
        string ans = "";
        for(auto it: indegree){
            if(it.second == 0){
                q.push(it.first);
                ans+=it.first;
            }
        }
        while(!q.empty()){
            char c = q.front();
            q.pop();
            for(auto it: adj[c]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    ans+=it;
                }
            }
        }
        if(ans.size() < indegree.size()) return "";
        return ans;
    }
};