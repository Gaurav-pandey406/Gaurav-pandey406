class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs.back();
        int i = 0;
        int j = 0;
        while(i < first.size() && j < last.size() && first[i] == last[j]){
            i++;
            j++;
        }
        return first.substr(0 , i);
        
    }
};