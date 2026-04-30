class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> result;
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for(int i=0; i<m; i++){
            if(i%2 == 0){
                for(int j=0; j<n; j++){
                    if(count%2 == 0){
                        result.push_back(grid[i][j]);
                    }
                    count++;
                }
            }else{
                for(int j=n-1;j >=0; j--){
                    if(count%2 == 0){
                        result.push_back(grid[i][j]);
                    }
                    count++;
                }
            }
        }
        return result;
    }
};