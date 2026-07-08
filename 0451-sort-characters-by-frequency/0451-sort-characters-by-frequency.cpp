class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for(char ch : s){
            mp[ch]++;
        }

        priority_queue<pair<int, char>>pq;

        for(auto x: mp){
            pq.push({x.second, x.first});
        }

        string ans = "";
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            ans.append(curr.first, curr.second);
        }
        return ans;
    }
};