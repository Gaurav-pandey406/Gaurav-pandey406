class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        unordered_map<int, int> m;
        int maxlen = 0;
        while(right < fruits.size()){
            m[fruits[right]]++;
            if(m.size() > 2){
                m[fruits[left]]--;
                if(m[fruits[left]] == 0){
                    m.erase(fruits[left]);
                }
                left++;
            }
            if(m.size() <= 2){
                maxlen = max(maxlen, right - left + 1);
            }
            right++;
        }
        return maxlen;
    }
};
