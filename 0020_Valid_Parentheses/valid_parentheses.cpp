// Check py file for explaining comments

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char, char> paras = {
            {')' , '('},
            {'}' , '{'},
            {']' , '['},
        };

        for (int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                stack.push_back(ch);
            }
            else{
                if(stack.empty() || paras[ch] != stack.back())
                    return false;
                stack.pop_back();
            }
        }
        if (stack.empty())
            return true;
        else
            return false;
    }
};