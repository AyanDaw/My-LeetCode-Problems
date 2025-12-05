class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for (int i=0; i<n; i++){
            
            if (i>0 && nums[i]==nums[i-1]) continue;
            
            int j = i+1;
            int k = n-1;
            while(j < k){
                int zero = nums[i] + nums[j] + nums[k];
                if(zero < 0){
                    //tor ans negative beroche mane toke ans take ektu kom negative banate hobe so amra dandike jabo, j++
                    j++;
                    // ans negative berolo
                }
                else if(zero > 0){
                    //tor ans positive beroche mane toke ans take ektu kom positive banate hobe so amra baike jabo, k--
                    k--;
                    // ans positive berolo
                }
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};// ans 0 holo
                    //Already sorted r duplicate check hoye ache so chinta nei
                    ans.push_back(temp); // Pechon theke push hoche
                    j++;
                    k--; // porer ta check korar jonno ready
                    // But eki values abar ele tokhun duplicate hobe, so jotokhun na value change hoche barate thakbo, And until they cross each other
                    // mind it i am talking about same value not same element
                    while((j < k) && nums[j]==nums[j-1]) j++;
                    while((j < k) && nums[k]==nums[k+1]) k--;

                }
            }
        }

        return ans;
    }
};