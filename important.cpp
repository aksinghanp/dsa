//All path from source to target

class Solution {
public:
    void solve(vector<vector<int>>&graph, vector<vector<int>>& ans, vector<int>&path, vector<int>&visited, int vert){
        
        if( vert == graph.size()-1){
            ans.push_back(path);
            return;
        }
        
        for(auto it:graph[vert]){
            if( !visited[it] ){
                visited[it] =1;
                path.push_back(it);
                solve(graph, ans, path, visited,it);
                path.pop_back();
                visited[it] = 0;
            }
        }
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        
        vector<int> path;
        
        vector<int> visited (graph.size(), 0);
        
        visited[0] = 1;
        path.push_back(0);
        
        solve(graph, ans, path, visited, 0);
        
        return ans;
    }
};