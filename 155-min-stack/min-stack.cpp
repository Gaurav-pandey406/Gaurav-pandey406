class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {
    mini = 0;
}

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                // Encode the value
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long top = st.top();
        st.pop();

        if (top < mini) {
            // Decoding old minimum
            mini = 2 * mini - top;
        }
    }

    int top() {
        if (st.empty()){
            throw runtime_error("Stack is empty");

        }
    

        long long top = st.top();
        return (top >= mini) ? top : mini;
    }

    int getMin() {
        if (st.empty()){
            throw runtime_error("Stack is empty");

        }
    
        

        return mini;
    }
};