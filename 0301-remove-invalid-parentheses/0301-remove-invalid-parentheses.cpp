class Solution {
public:
    unordered_set<string>result;

    void dfs(string s, int start, int leftRemove, int rightRemove){
        if(leftRemove == 0 && rightRemove == 0){
            int balance = 0;

            for(char c : s){
                if(c == '('){
                    balance++;
                }else if(c == ')'){
                    balance--;

                    if(balance < 0)
                        return;
                }
            }

            if(balance == 0){
                result.insert(s);
            }
            return;
        }

        for(int i=start; i<s.size(); i++){
            if(i > start && s[i] == s[i-1])
                continue;

            if(leftRemove > 0 && s[i] == '('){
                string next = s.substr(0, i) + s.substr(i + 1);
                dfs(next, i, leftRemove-1, rightRemove);
            }

            if(rightRemove > 0 && s[i] == ')'){
                string next = s.substr(0, i) + s.substr(i + 1);
                dfs(next, i, leftRemove, rightRemove-1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;

        for(char c : s){
            if(c == '('){
                leftRemove++;
            }else if(c == ')'){
                if(leftRemove > 0){
                    leftRemove--;
                }else{
                    rightRemove++; 
                }
            }
        }

        dfs(s, 0, leftRemove, rightRemove);

        return vector<string>(result.begin(), result.end());
    }
};