// Check Py file for explaining comments

class Solution {
public:
    long long comb(int n, int k) { // Doing the math.comb() function
    k = min(k, n - k); // main focus factorial ta komano
    long long res = 1;

    for (int i = 1; i <= k; i++) {
        res = res * (n - k + i) / i;
    }
    return res;
}
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        return comb(N, m-1);
    }
};