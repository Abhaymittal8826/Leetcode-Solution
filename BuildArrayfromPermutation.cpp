class Solution {
    public:
      // This is Brute Force Approach
      //Time Complexicity  - O(N)
      //Space Complexicity - O(N)
    
        vector<int> buildArray(vector<int>& nums) {
            vector<int>ans(nums.size());
            
            for(int i=0;i<nums.size();i++){
                ans[i]=nums[nums[i]];
            }
            return ans;
        }
    };