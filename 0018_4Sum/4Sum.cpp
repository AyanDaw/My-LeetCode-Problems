// 3Sum er opor arek ta for loop kora hoyeche
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-3; i++){
            if (i > 0 && nums[i]==nums[i-1]) continue;  // Most outer loop.

            for(int j = i+1; j < n-2; j++){
                if (j > (i+1) && nums[j]==nums[j-1]) continue;  // Second loop. If confused about j>i+1, then compare it with i's loop's one

                // Two pointers
                int k = j+1;        
                int l = n-1;
                while (k < l){
                    // Input maybe very large so Long Long
                    // Expressions like (nums[i] + nums[j] + nums[k] + nums[l]) are evaluated in int and can overflow before you compare to target.
                    long long sum = nums[i];  
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    // Some SOAB inputs can be like this, [1000000000,1000000000,1000000000,1000000000]. thats why i used 1 by 1 summation method
                    if (sum < target){
                        k++;
                        //negative condition
                    }
                    else if(sum > target){
                        l--;// positive condition
                    }
                    else{
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        //zero condition
                        k++;
                        l--;
                        while((k < l) && nums[k] == nums[k-1]) k++;
                        while ((k < l) && nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};