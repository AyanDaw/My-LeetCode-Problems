class Solution {
public:
    int longestValidParentheses(string s) {

        // We store indices of characters of s in this vector stack.
        // Start with -1 as a "base boundary" to mark the position
        // before the beginning of any valid substring.
        vector<int> stack = {-1};

        int maxlen = 0;

        for (int i = 0; i < s.size(); i++) {

            // If we see an opening bracket, it may start a future pair.
            // So we store its index.
            if (s[i] == '(') {
                stack.push_back(i);
            }

            // If we see a closing bracket:
            else {

                // Try to match it with the most recent '('.
                // Pop the last stored index.
                stack.pop_back();

                // Case 1: stack becomes empty after popping —
                // This means the ')' had no matching '('.
                //
                // So this index becomes the new "boundary".
                // No valid substring can cross this point.
                if (stack.empty()) {
                    stack.push_back(i);
                }

                // Case 2: stack is NOT empty —
                // This means the current ')' has a matching '('.
                //
                // The length of the current valid substring is:
                // current index - index of the last unmatched bracket/boundary.
                else {
                    int currlen = i - stack.back();
                    maxlen = max(maxlen, currlen);
                }
            }
        }

        return maxlen;
    }
};
