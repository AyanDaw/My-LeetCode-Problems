class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()){ // Checking if empty
            return 0;
        }
        int n = nums.size();
        int prev = nums[0];  // Taking the first element
        int k = 1; // Unique value counter. First one will always be unique so 1
        int i = 1;  
        while (i < n){  // Taking values from 1 index, not 0.

            if (prev != nums[i]){  // If value doesnot match with previous element, then it means it's unique
                prev = nums[i];  // Updating the previous value variable
                // Inserting the current element after the last unique value
                nums[k] = nums[i];
                k++;
                }  // Increasing unique counter by 1.
            i++;
        }
        return k; // Returning the unique counter value.
    }
};