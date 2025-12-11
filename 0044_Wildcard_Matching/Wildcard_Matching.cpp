// Hard?? It was far easier than 10._regular_expression_Matching/

class Solution {
public:
    bool f(vector<vector<int>> &dp, int i, int j, string &p, string &s){
        // Base cases
        if(i<0 && j<0) return true;  // Duto string e jokhun sesh
        if(i<0 && j>=0) return false; // Pattern sesh hoye geche but not text
        if(i>=0 && j<0){
            for(int ii=i; ii>=0; ii--){
                // Jotokhun na non '*' asche check korbe. Ei conditions er under e * asa manei false.
                if(p[ii] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];

        // direct match or '?'
        if (p[i] == s[j] || p[i] == '?') {
            return dp[i][j] = f(dp, i-1, j-1, p, s);
        }
        if(p[i] == '*'){
            return dp[i][j] = f(dp, i-1, j, p, s) || f(dp, i, j-1, p, s);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        if(m == 0 && n == 0) return true; 
        // Dutoi faka.
        
        if(n==0) return false; 
        // Text ache but pattern e kichu nei
        
        vector<vector<int>> dp(n, vector<int>(m, -1)); 
        // Similar to 2D array. Every room is initialized with -1.

        return f(dp, n-1, m-1, p, s);
    }
};