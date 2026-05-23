class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }

        vector<int> s1Count(26,0);
        vector<int>windowCount(26,0);

        for(char ch : s1){
            s1Count[ch - 'a']++;
        }

        int left = 0;
        for(int right=0; right<s2.size(); right++){
            windowCount[s2[right] - 'a']++;

            if(right-left+1 > s1.size()){
                windowCount[s2[left] - 'a']--;
                left++;
            }

            if(s1Count == windowCount){
                return true;
            }
        }
        return false;
    }
};