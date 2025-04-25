class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nextGreater(n, -1);  
        stack<int> st;

        // Traverse nums2 from right to left
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nextGreater[i] = st.top();
            }

            st.push(nums2[i]);
        }

        
        vector<int> result;
        for (int num : nums1) {
            
            for (int i = 0; i < n; ++i) {
                if (nums2[i] == num) {
                    result.push_back(nextGreater[i]);
                    break;
                }
            }
        }

        return result;
    }
};
