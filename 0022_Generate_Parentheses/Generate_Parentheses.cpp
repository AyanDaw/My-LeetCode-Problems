class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res; // Declaring result string
        if (n == 0)
            return res; // Impossible case according to the question
        string current = "";
        paras(res, n, current, 0, 0); // Calling the function
        return res; // After the function done its job we can return res
    }

    void paras(vector<string> &res, int n, string current, int o, int c){
        // o for Open brackets and c for Close brackets
        if (current.size() == 2 * n){
            res.push_back(current);
            return; // We have done the operation on the memory of res, so nothing to return thats why its void function
        } // Last check when all brackets are used

        // We will call both below cases, to make sure all possible patterns are generated
        if (o < n)
            paras(res, n, current + "(", o + 1, c);

        if (c < o)
            paras(res, n, current + ")", o, c + 1);

        // In both cases we are not creating any copy of res, instead we are editing directly at the memory location.
    }
};