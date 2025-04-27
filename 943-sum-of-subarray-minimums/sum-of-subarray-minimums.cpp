class Solution {
public:
    vector<int> previousSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        return prev;
    }

    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> next(n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        return next;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev = previousSmaller(arr);
        vector<int> next = nextSmaller(arr);
        
        long long sum = 0;
        int mod = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            sum = (sum + (arr[i] * left * right) % mod) % mod;
        }
        
        return (int)sum;
    }
};
