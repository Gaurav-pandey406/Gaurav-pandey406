#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st; 

        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0 && st.back() > num[i]) {
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }

        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        
        int index = 0;
        while (index < st.size() && st[index] == '0') {
            index++;
        }

        string result = st.substr(index);

        if (result.empty()) {
            return "0";
        }

        return result;
    }
};
