class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>countT;
        unordered_map<char, int>window;

        for(char ch: t){
            countT[ch]++;
        }

        int have = 0;
        int minLen = INT_MAX;
        int need = countT.size();

        int left = 0;
        int startIndex = 0;

        for(int right = 0; right < s.size(); right++){
            char ch = s[right];
            window[ch]++;

            if(countT.count(ch) && window[ch] == countT[ch]){
                have++;
            }

            while(have == need){
                int windowLen = right - left + 1;
                if(windowLen < minLen){
                    minLen = windowLen;
                    startIndex = left;
                }
                window[s[left]]--;

                if(countT.count(s[left]) && window[s[left]] < countT[s[left]]){
                    have--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};