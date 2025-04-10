class Solution {
public:
    int atmost(vector<int>&nums , int goal){
        int left = 0;
        int right = 0;
        long long sum = 0;
        int result =0;
        if(goal < 0){
            return 0;
        }

        while(right < nums.size()){
            sum += nums[right];
            while(sum > goal){
                sum -= nums[left];
                left++;
            }
            result += right - left + 1;
            right++;
            
        }
        return result;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      
      return atmost(nums, goal) - atmost(nums, goal -1);

        
    }
};