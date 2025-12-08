class Solution {
private:
    int checkPalinLen(const string &s, int left, int right){ // A function to check the length of limit of Palindrome
        int n = s.size();
        while(left >= 0 && right < n && s[left]==s[right]){ // Starts from middle and then expands towards both sides
        left--; // Sliding towards left
        right++; // Sliding towards right
    } // The loop exits when the left right doesnot match for the first time.
    // Left right are now 1 element extra towards both side outside than the actual left right
    /*
    assume right now left,right are at (1,4)
    It means actual LEFT,RIGHT are at (2,3)
    This function's main focus it to find out the length of the palindrome
    So, length of palindrome = RIGHT - LEFT + 1
    actual RIGHT right er theke 1 kom
    actual LEFT left er theke 1 beshi
                             = (right - 1) - (left + 1) + 1
                             = right - left - 1
    */
    return right - left - 1; 
};
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n < 2) return s; // When there is a single character palindrome
        int start = 0, maxLen = 0;  // In initialize form
        for(int i=0; i < n; i++){
            int len1 = checkPalinLen(s, i, i); // Odd palindrome length check
            int len2 = checkPalinLen(s, i, i+1); // Even palindrome length check
            int Len = max(len1, len2); // We need the maximum one
            if(maxLen < Len){
                maxLen = Len;
                start = i - (Len-1)/2; 
                // Len -1, to handle odd and even, then half for half of the element. then that much elements backwards for starting point.
            }
        }

        return s.substr(start, maxLen); // Substring of s from start to maximum length.
    }
};
