class Solution {
private:
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis) {  
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(adj, it, vis); 
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {  
        int V = isConnected.size();
        vector<vector<int>> adj(V);  
        
        
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i); 
                }
            }
        }

        vector<int> vis(V, 0);  
        int count = 0;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                count++;
                dfs(adj, i, vis);  
            }
        }
        return count;
    }
};