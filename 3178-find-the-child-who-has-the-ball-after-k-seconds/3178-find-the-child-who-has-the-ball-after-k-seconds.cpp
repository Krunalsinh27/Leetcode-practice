class Solution {
public:
    int numberOfChild(int n, int k) {
        int child = 0;
        int direction = 1;

        for(int i=0; i<k; i++){
            child += direction;

            if(child == n-1){
                direction = -1;
            }else if(child == 0){
                direction = 1;
            }
        }
        return child;
    }
};