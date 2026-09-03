class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestOdd = INT_MAX;
        int smallestEven = INT_MAX;

        for(int x : nums1){
            if(x%2 == 0){
                smallestEven = min(smallestEven, x);
            }else{
                smallestOdd = min(smallestOdd, x);
            }
        }

        if(smallestOdd == INT_MAX){
            return true;
        }

        if(smallestEven == INT_MAX){
            return true;
        }

        if(smallestOdd < smallestEven){
            return true;
        }
        
    return false; 
    }
};