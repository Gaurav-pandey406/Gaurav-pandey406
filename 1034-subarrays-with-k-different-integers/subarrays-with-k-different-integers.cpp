class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    
    int atMostK(vector<int>& nums, int k) {
        int left = 0, count = 0;
        unordered_map<int, int> m;
        
        for (int right = 0; right < nums.size(); right++) {
            if (m[nums[right]] == 0) {
                k--;
            }
            m[nums[right]]++;

            while (k < 0) {
                m[nums[left]]--;
                if (m[nums[left]] == 0) {
                    k++;
                }
                left++;
            }

            count += (right - left + 1);
        }
        
        return count;
    }
};
