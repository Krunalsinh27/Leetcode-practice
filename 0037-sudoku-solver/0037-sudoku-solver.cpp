bool isSafe(int row, int col, vector<vector<char>>& boards, int val){
    for(int i=0; i<9; i++){
        if(boards[row][i] == val){
            return false;
        }

        if(boards[i][col] == val){
            return false;
        }

        if(boards[3*(row/3) + i/3][3*(col/3) + i%3] == val){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>>& boards){

    for(int row=0; row<9; row++){
        for(int col=0; col<9; col++){
            if(boards[row][col] == '.'){
                for(int val='1'; val<='9'; val++){
                    if(isSafe(row, col, boards, val)){
                        boards[row][col] = val;
                        bool possibleSolution = solve(boards);
                        if(possibleSolution){
                            return true;
                        }else{
                            boards[row][col] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};