class Solution {
public:
    int myAtoi(string s) {
        int caret = 0;
        int n = s.length();

        // Whitespace: Ignore any leading whitespace (" ").
        while (caret < n && s[caret] == ' ') {
            caret++;
        }

        // + & -
        int sign = 1;
        if (caret < n && (s[caret] == '+' || s[caret] == '-')) {
            if (s[caret] == '-') {
                sign = -1;
            }
            caret++;
        }

        long num = 0;   // long to safely detect overflow before clamping

        while (caret < n && isdigit(s[caret])) {
            int digit = s[caret] - '0';

            // Overflow check
            if (num > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            caret++;
        }

        return static_cast<int>(num * sign);
    }
};