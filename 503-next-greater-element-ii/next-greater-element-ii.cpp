class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); 
    
        for (int i = 0; i < n; i++) {
            
            for (int j = i + 1; j < i + 1 + n; j++) {
                int index = j % n;  
                if (nums[index] > nums[i]) {
                    ans[i] = nums[index];
                    break;  
                }
            }
        }
        return ans;
    }
};
