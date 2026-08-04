class Solution {
public:

    int timer = 0;

    void dfs(int node,
             int parent,
             vector<int> adj[],
             vector<int>& disc,
             vector<int>& low,
             vector<int>& vis,
             vector<vector<int>>& ans){

        vis[node] = 1;

        disc[node] = low[node] = timer++;

        for(int neigh : adj[node]){

            if(neigh == parent)
                continue;

            if(!vis[neigh]){

                dfs(neigh,node,adj,disc,low,vis,ans);

                low[node] = min(low[node],low[neigh]);

                if(low[neigh] > disc[node]){

                    ans.push_back({node,neigh});
                }
            }
            else{

                low[node] = min(low[node],disc[neigh]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {

        vector<int> adj[n];

        for(auto edge : connections){

            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);

        vector<vector<int>> ans;

        dfs(0,-1,adj,disc,low,vis,ans);

        return ans;
    }
};