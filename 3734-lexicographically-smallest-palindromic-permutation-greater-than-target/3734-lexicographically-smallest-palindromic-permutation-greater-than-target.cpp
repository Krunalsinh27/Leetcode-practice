class Solution {
public:

    string makePalindrome(string left, char middle){
        string right = left;

        reverse(right.begin(), right.end());

        if(middle != 0){
            return left + string(1,middle) + right;
        }

        return left + right;
    }

    bool canMakeGreater(string prefix, vector<int>& cnt, char middle, string target){

        string left = prefix;

        for(int c=25; c>=0; c--){
            for(int j=0; j<cnt[c]; j++){
                left += char('a'+c);
            }
        }
        string candidate = makePalindrome(left, middle);

        return candidate > target;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int>freq(26,0);

        for(char c : s){
            freq[c - 'a']++;
        }

        int oddCount = 0;
        char middle = 0;

        for(int i=0; i<26; i++){

            if(freq[i] % 2 == 1){

                oddCount++;
                middle = char('a' + i);
            }
        }

        if(oddCount > 1){
            return "";
        }

        vector<int>half(26,0);

        for(int i = 0; i < 26; i++){
            half[i] = freq[i] / 2;
        }

        int halfLen = n/2;

        string prefix = "";

        for(int pos = 0; pos < halfLen; pos++){
            bool found = false;

            for(int c = 0; c < 26; c++){

                if(half[c] == 0)
                    continue;
                
                half[c]--;
                prefix.push_back(char('a' + c));

                if(canMakeGreater(prefix, half, middle, target)){
                    found = true;
                    break;
                }

                prefix.pop_back();
                half[c]++;
                }

                if(!found){
                    return "";
                }
            }

            string answer = makePalindrome(prefix, middle);

            if(answer > target)
                return answer;
            
        return "";
    }
};