// Check Py file for the explaining comments

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxrange = 0;
        for(int i=0; i < n; i++){
            if (i > maxrange){
                return false;
            }
            maxrange = max(maxrange, i + nums[i]);
        }
        return true;
    }
};