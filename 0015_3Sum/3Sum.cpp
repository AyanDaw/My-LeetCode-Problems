class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;     // List of Lists er variable, which will be returned
        int n = nums.size();

        // Sorting the array so we can implement teo pointers and it will reduce the time if we use sort for every possible triplets and create duplicates too
        sort(nums.begin(),nums.end());   
        for (int i=0; i<n; i++){
            
            if (i>0 && nums[i]==nums[i-1]) continue; // If the next element's value is the same as previous element then we will skip cause the list is already sorted.
            
            int j = i+1; // next element of i. So ith index can stay != j
            int k = n-1; // end point of the array
            while(j < k){ // Until the j and k clashes
                int zero = nums[i] + nums[j] + nums[k];
                if(zero < 0){ // If the ans becomes -ve
                    // Your ans is negative that means we have to make the ans less negative so we will move the j towards right means j++
                    j++;
                }
                else if(zero > 0){ // If the ans is +ve
                    // Your ans is positive that means we have to make the ans less positive so we will move the k towards left means k--
                    k--;
                }
                else{ // If the ans gives 0
                    vector<int> temp = {nums[i], nums[j], nums[k]}; // saving the elements in array form in a array.
                    // This list is already sorted and no duplicate so no overthink
                    ans.push_back(temp); // Enters new triplets at the end
                    j++; 
                    k--; // Readying them for next element
                    // But if the same values comes again this will make duplicates. so untill the value changes we will keep increasing it, And until they cross each other
                    // mind it i am talking about same value not same element
                    while((j < k) && nums[j]==nums[j-1]) j++;
                    while((j < k) && nums[k]==nums[k+1]) k--;

                }
            }
        }

        return ans;
    }
};