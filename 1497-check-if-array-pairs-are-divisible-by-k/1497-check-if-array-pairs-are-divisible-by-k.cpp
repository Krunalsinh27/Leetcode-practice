class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();

        if(n%2 != 0){
            return false;
        }

        unordered_map<long long, long long> freq;

        for(long long x : arr){
            long long rem = ((x%k) + k) % k;
            freq[rem]++;
        }

        for(auto it : freq){
            long long rem = it.first;
            long long complement = (k - rem) % k;

            if(rem == complement){
                if(freq[rem]%2 != 0){
                    return false;
                }
            }else{
                if(freq[rem] != freq[complement]){
                    return false;
                }
            }
        }
        return true;
    }
};