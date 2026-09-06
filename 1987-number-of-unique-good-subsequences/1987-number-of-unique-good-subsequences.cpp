class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const long long MOD = 1e9 + 7;

        long long one = 0;
        long long zero = 0;
        long long hasZero = 0;

        for(char c : binary){
            if(c == '1'){
                one = (one + zero + 1) % MOD;
            }else{
                zero = (zero + one) % MOD;
                hasZero = 1;
            }
        }
        return (one + zero + hasZero) % MOD;
    }
};