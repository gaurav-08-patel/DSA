class Solution {
public:
    void dfs(vector<vector<int>> &adjList ,int start, vector<int> &vis ){
        vis[start]=1;

        for(auto n : adjList[start]){
            if(!vis[n]) dfs(adjList , n , vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adjList(n);
        vector<int> vis(n);
        int count=0;
        //to convert adj matrix to adj list 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i !=j ) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(adjList,i,vis);
            }
        }

        return count;
    }
};