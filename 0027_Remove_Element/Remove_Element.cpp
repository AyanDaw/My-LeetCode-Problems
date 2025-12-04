class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = 0;
        
        for (int x : nums) {      // x is values here
            if (x != val) {
                nums[pos++] = x;
            }
        }
        // Val bade jesob value asbe segulo ke allocate korbe r next tai ready hoye bose thakbe, val esegele skip kore jabe
        return pos; // Oitai abar return kore debe
    }
};