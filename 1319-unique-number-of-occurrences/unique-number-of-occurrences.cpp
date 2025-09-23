class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int num : arr){
            m[num]++;
        }
        unordered_set<int> s;
        for(auto& num1 : m){
            int count = num1.second;            
            if(s.find(count) != s.end()){
                return false;
            }            
            s.insert(count);
        }
        return true;
    }
};