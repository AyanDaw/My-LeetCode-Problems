class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();        // Taking the size of the input

        int i = 0;                  // Counter
        while (i < n) {
            if (nums[i] > 0 && nums[i] < n + 1 && nums[i] != nums[nums[i] - 1]) { // Checking the range. Cause out of this range doesnt matter. Also checking if the correct value is in its correct position or it will loop infinitely.
                swap(nums[i], nums[nums[i] - 1]); // Swap
            } else {
                i++;        // Next element
            }
        }

        for (i = 0; i < n; i++) {                   // looking for wrong one
            if (nums[i] != i + 1)
                return i + 1;                       // Returning it
        }
        return n + 1;                               // If 1....n all are available then n+1 will be the missing one
    }
};