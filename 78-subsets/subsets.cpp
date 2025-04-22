class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsetCount = 1 << nums.size();  
        vector<vector<int>> ans;

        for (int num = 0; num < subsetCount; num++) {
            vector<int> res;
            for (int i = 0; i < nums.size(); i++) {
                if (num & (1 << i)) {  
                    res.push_back(nums[i]);
                }
            }
            ans.push_back(res);
        }  

        return ans;
    }
};
