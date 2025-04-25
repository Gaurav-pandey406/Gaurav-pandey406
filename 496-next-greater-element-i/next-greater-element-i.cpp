class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for (int i = 0; i < nums1.size(); ++i) {
            int num = nums1[i];
            int indexInNums2 = -1;

        
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums2[j] == num) {
                    indexInNums2 = j;
                    break;
                }
            }

            
            int nextGreater = -1;
            for (int j = indexInNums2 + 1; j < nums2.size(); ++j) {
                if (nums2[j] > num) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            result.push_back(nextGreater);
        }

        return result; 
    }
};
