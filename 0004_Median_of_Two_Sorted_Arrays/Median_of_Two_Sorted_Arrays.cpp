class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // We will always work on nums1 as shorter one. So even if nums1 becomes bigger, will just swap it by recalling the with swap positions
        if (nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }

        int m = nums1.size(), n = nums2.size(); // m & n are the sizes of the arrays
        // We will take the size of nums1 as it is the shorter one also cant overflow conditioned while checking on nums2
        int low = 0, high = m; 
        // Median will either always be on the left or both side nearest element of the partition, thats why we are finding out how much there will be elements in left if we combine the arrays.
        int left = (m + n + 1) / 2; 
        int total = m + n; // Getting the combine length of two arrays
        // If median doesnt exist then the condition eventually turn out false and we will be out of loop. So for those cases we just cant write straigt True. or it will be always true.
        while (low <= high){  
            int mid1 = (low + high)/2; // Setting the partition of shorter array. Deciding how many elements we will took from shorter array
            int mid2 = left - mid1; // then rest of the remaining element of left will be taken from bigger array
            int r1 = (mid1 < m)? nums1[mid1] : INT_MAX; // right side element of the total_partition of shorter array. (If doesnt exists then the max value. think about taking 6th index element from an array of size 6.)
            int r2 = (mid2 < n)? nums2[mid2] : INT_MAX; // Same here but for bigger array
            int l1 = (mid1 - 1 >= 0)? nums1[mid1-1] : INT_MIN; // Same but for left element of total_partition of shorter array. (this time if not exist then the minimum value)
            int l2 = (mid2 - 1 >= 0)? nums2[mid2-1] : INT_MIN; // same
            if (l1 <= r2 && l2 <= r1){  // This is the solution condition
                if (total % 2 == 0) {  // If its even then we have to took nearest element of both side of partition. means max of left and min of right
                    return ((double)(max(l1, l2) + min(r1, r2)) / 2.0);
                }
                else {  // If its Odd then the median always exists in left, as we make sured by (m+n+1)/2. so the maximum of leftest ones of partition will be median
                    return max(l1, l2);
                }
            }
            else if (l1>r2){
                high = mid1 - 1; // This means we are ignoring the elements after mid and mid of shorter array, moving mid partition towards left. IN NUTS: decreasing one element from shorter array 
            } // Note: Total Left elements stays constant
            else{
                low = mid1 + 1; // This means we are ignoring the elements before mid and mid of shorter array, moving mid partition towards right. IN NUTS: Increasing one element from shorter array
            }
        }
        return 0; // If we could not find out the value of median
    }
};