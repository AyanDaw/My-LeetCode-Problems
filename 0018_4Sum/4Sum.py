# Check Cpp file for explaining comments

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:

        n = len(nums)
        ans = []
        nums.sort()
        for i in range(0 , n-3):
            if (i > 0 and nums[i]==nums[i-1]): 
                continue

            for j in range(i+1 , n-2):
                if (j > (i+1) and nums[j]==nums[j-1]): 
                    continue

                k = j+1
                l = n-1
                while (k < l):
                    sum = nums[i] + nums[j] + nums[k] + nums[l]

                    if (sum < target): 
                        k+= 1
                        #negative condition
                    elif (sum > target):
                        l-= 1 # positive condition
                    else:
                        temp = [nums[i], nums[j], nums[k], nums[l]]
                        ans.append(temp)
                        #zero condition
                        k+=1
                        l-=1
                        while((k < l) and nums[k] == nums[k-1]):
                            k+=1
                        while ((k < l) and nums[l] == nums[l+1]):
                            l-=1
                            
        return ans