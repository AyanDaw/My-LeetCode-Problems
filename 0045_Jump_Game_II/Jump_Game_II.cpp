class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0, curend = 0, steps = 0;
        for (int i = 0; i < n-1; i++){
            farthest = max(farthest, i + nums[i]);
            if (i == curend){
                steps++;
                curend = farthest;
            }
        }
        return steps;
    }
};