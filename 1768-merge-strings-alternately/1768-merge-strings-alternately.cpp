class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string ans = "";
        int i=0;
        while(i<n && i<m){
            ans = ans + word1[i] + word2[i];
            i++;
        }
        while(i< n){
            ans = ans + word1[i];
            i++;
        }
        while(i < m){
            ans = ans + word2[i];
            i++;
        }
        return ans;
    }
};