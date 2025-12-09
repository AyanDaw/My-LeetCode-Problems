// TODO: Solve this problem again. Without the help of AI. 

class Solution {
public:
    bool f(int i, int j, string &p, string &s, vector<vector<int>> &dp){
        // base cases
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;

        // If pattern left but string is empty -> pattern must be x* x* x* ...
        if (i >= 0 && j < 0) {
            while (i >= 0) {
                // '*' must be at i and it must have a preceding char at i-1
                if (p[i] != '*') return false;
                i -= 2;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        // direct match or '.'
        if (p[i] == s[j] || p[i] == '.') {
            return dp[i][j] = f(i-1, j-1, p, s, dp);
        }

        // star handling: p[i] == '*'
        if (p[i] == '*') {
            // '*' cannot be standalone: need a preceding char at i-1
            // Option 1: zero occurrences of preceding char => skip preceding char and '*'
            bool zero = false;
            if (i - 2 >= -1) // safe to call f(i-2,...); base handles i<0
                zero = f(i - 2, j, p, s, dp);

            // Option 2: one or more occurrences => preceding char must match s[j]
            bool oneOrMore = false;
            if (i - 1 >= 0 && j >= 0 && (p[i-1] == s[j] || p[i-1] == '.')) {
                oneOrMore = f(i, j - 1, p, s, dp);
            }

            return dp[i][j] = zero || oneOrMore;
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        if (n == 0 && m == 0) return true;
        if (n == 0) return false;

        // If either is zero-length, dp vector dimensioning below must be safe.
        // We'll only index dp[i][j] when i>=0 and j>=0, so vector sizes of n x m are fine.
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, p, s, dp);
    }
};
