class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = nums[0], maxsum = nums[0];
        for(int i=1; i < nums.size(); i++){
            currsum = max(nums[i], currsum+nums[i]);
            // What is the best subarray that ENDS at index i?
            // Start fresh at i → nums[i]
            // Extend previous subarray → currentSum + nums[i]
            maxsum = max(maxsum, currsum);
            // Have I ever seen a better subarray anywhere so far?
            // Best ending right now
            // Best seen at any earlier index
        }
        return maxsum;
    }
};