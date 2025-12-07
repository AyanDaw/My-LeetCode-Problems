// Check the Python file for explaining comments

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        int left = 0, right = (nums.size() - 1);
        
        while (left <= right){

            int mid = (left + right)/2;
            if(nums[mid] == target)
                return mid;
            else if (target < nums[mid])
                right = mid-1;
            else if (nums[mid] < target)
                left = mid + 1;
            }
        return left;
    }
};