class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int countOnes = 0;

        string ans = "";

        for(int right=0; right < s.size(); right++){
            if(s[right] == '1'){
                countOnes++;
            }

            if(countOnes == k){
                while(left < right && s[left] == '0'){
                    left++;
                }

                string current = s.substr(left, right-left+1);

                if(ans == "" || current.size() < ans.size() || (current.size() == ans.size() && current < ans)){
                    ans = current;
                }

                if(s[left] == '1'){
                    countOnes--;
                }

                left++;
            }
        }
        return ans;
    }
};