class Solution {
private:
    int checkPalinLen(const string &s, int left, int right){
        int n = s.size();
        while(left >= 0 && right < n && s[left]==s[right]){
        left--;
        right++;
    }
    return right - left - 1;
};
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n < 2) return s;
        int start = 0, maxLen = 0;
        for(int i=0; i < n; i++){
            int len1 = checkPalinLen(s, i, i);
            int len2 = checkPalinLen(s, i, i+1);
            int Len = max(len1, len2);
            if(maxLen < Len){
                maxLen = Len;
                start = i - (Len-1)/2;
            }
        }

        return s.substr(start, maxLen);
    }
};
