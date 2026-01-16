class Solution {

private:
    int sumDigitsSquare(int n){
        int sq = 0;
        while(n){
            int digit = n % 10;
            sq += digit * digit;
            n = n/10;
        }
        return sq;
    }

public:
    bool isHappy(int n) {
        while(1){
            if(n == 1)
                return true;
            n = sumDigitsSquare(n);
            if(n == 4)
                return false;
        }
        return false;
    }
};