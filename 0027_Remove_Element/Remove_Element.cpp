class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = 0;
        
        for (int x : nums) {      // x is values here
            if (x != val) {
                nums[pos++] = x;
            }
        }
        
        return pos;
    }
};