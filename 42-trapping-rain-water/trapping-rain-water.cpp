class Solution {
public:
    vector<int> suffixMax(vector<int>& height) {
        int n = height.size();
        vector<int> suffix(n);
        suffix[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffix[i] = max(suffix[i+1], height[i]);
        }
        return suffix;
    }

    vector<int> prefixMax(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n);
        prefix[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i-1], height[i]);
        }
        return prefix;
    }

    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }

        vector<int> left = prefixMax(height);
        vector<int> right = suffixMax(height);
        
        int total = 0;
        for (int i = 0; i < height.size(); i++) {
            int waterHeight = min(left[i], right[i]) - height[i];
            if (waterHeight > 0) {
                total += waterHeight;
            }
        }
        return total;
    }
};
