class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 1){
            return true;
        }
        int start = 1, end = num;
        while(end >= start){
            unsigned long long mid = start + (end-start)/2;
            unsigned long long sqrt = mid*mid;
            if(sqrt == num){
                return true;
            }else if(sqrt < num){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return false;
    }
};