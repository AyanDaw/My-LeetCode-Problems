class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp; // Creates a Map

        int i, need;
        for (i = 0; i < nums.size(); i++)
        {
            need = target - nums[i]; // What we need to look, stores in 'need'
            if (mp.count(need))      // Searches for the 'need' in the Map
            {
                return {mp[need], i}; // Returns 'need' key's value and current index
            }
            mp[nums[i]] = i; // If 'need' isnt available in the Map then it stores the index as value of Key as 'need'
        }
        return {}; // If cant get any answer. Given that a unique answer exists
    }
};