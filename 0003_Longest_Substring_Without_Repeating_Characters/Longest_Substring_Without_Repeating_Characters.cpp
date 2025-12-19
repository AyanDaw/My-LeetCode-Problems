// Check py file for the explaining comments

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0;
        int l = 0;
        int maxlen = 0;
        unordered_map<char, int> dc = {};
        for(r; r < s.size(); r++){
            char ch = s[r];
            if (dc.count(ch)){
                if (l <= dc[ch]){         
                    l = dc[ch] + 1;
                }   
            }

            dc[ch] = r;
            int rllength = r - l + 1;
            maxlen = max(rllength, maxlen);
        }

        return maxlen;
    }
};