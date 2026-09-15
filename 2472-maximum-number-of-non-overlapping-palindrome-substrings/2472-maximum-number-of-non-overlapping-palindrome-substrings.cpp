class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                if (s[l] == s[r] &&
                    (len <= 2 || pal[l + 1][r - 1])) {
                    pal[l][r] = true;
                }
            }
        }

        int ans = 0;
        int lastEnd = -1;

        for (int r = 0; r < n; r++) {

            for (int l = lastEnd + 1; l <= r; l++) {

                int len = r - l + 1;

                if (len >= k && pal[l][r]) {
                    ans++;
                    lastEnd = r;

                    break;
                }
            }
        }

        return ans;
    }
};