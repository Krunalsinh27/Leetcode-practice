class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (words.empty() || s.empty()) return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen) return ans;

        unordered_map<string, int> target;

        for (string word : words) {
            target[word]++;
        }

        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int count = 0;
            unordered_map<string, int> seen;

            for (int right = offset;
                 right + wordLen <= s.size();
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                if (target.find(word) == target.end()) {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                seen[word]++;
                count++;

                while (seen[word] > target[word]) {
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    left += wordLen;
                    count--;
                }

                if (count == wordCount) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};