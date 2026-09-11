class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int>st;

        int n = digits.size();

        for(int i=0; i<n; i++){
            if(digits[i] == 0)
                continue;
            
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i==j || i == k || j == k)
                        continue;
                    
                    if(digits[k] % 2 != 0)
                        continue;
                    
                    int num = digits[i]*100 + digits[j]*10 + digits[k];

                    st.insert(num);
                }
            }
        }
        return vector<int>(st.begin(), st.end());
    }
};