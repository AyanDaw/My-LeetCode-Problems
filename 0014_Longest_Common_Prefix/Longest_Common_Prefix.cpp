class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()){      // Checking if even there is a string or not
            return "";
        }

        string prefix = strs[0];        // Saving first element in string type variable

        for(int i = 0; i < strs.size(); i++){       // Looping through each element

            while (strs[i].compare(0, prefix.size(), prefix) != 0 && !prefix.empty()){      // !prefix.empty() is not needed. the previous condition is sufficient but i still added it 😁. What it does is compare prefix with string until it matches
                prefix.pop_back();          // If not matches then removes the last element of the prefix. No need to re-assign. works directly at the memory.
                
                if(prefix.empty())              // Returns in boolean
                    return "";      // Eventually if the string goes empty then return ""
            }
        }
        return prefix;          // if something is left then that is returned
    }
};