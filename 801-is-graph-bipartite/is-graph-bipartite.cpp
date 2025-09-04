class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(graph, i, 0, color)) {
                    return false;
                }
            }
        }
        return true;
    }
    
private:
    bool dfs(vector<vector<int>>& graph, int node, int currentColor, vector<int>& color) {
        color[node] = currentColor; 
        
        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) { 
                
                if (!dfs(graph, neighbor, 1 - currentColor, color)) {
                    return false;
                }
            } else if (color[neighbor] == currentColor) {
                return false;
            }
        }
        return true;
    }
};