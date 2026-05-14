class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>rows(9);
        vector<unordered_set<char>>cols(9);
        vector<unordered_set<char>>boxes(9);

        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                char val = board[row][col];

                if(val == '.'){
                    continue;
                }

                int boxIndex = (row/3)*3 + (col/3);

                if(rows[row].count(val) || cols[col].count(val) || boxes[boxIndex].count(val)){
                    return false;
                }

                rows[row].insert(val);
                cols[col].insert(val);
                boxes[boxIndex].insert(val);
            }
        }
        return true;
    }
};