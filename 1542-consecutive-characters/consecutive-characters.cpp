class Solution {
public:
    int maxPower(string s) {
        int maxi = 1;
        int count = 1;
        for(int i = 1; i<s.length();i++){
            if(s[i] == s[i-1]){
                count++;
            }
            else{
                count = 1;
            }
            maxi = max(count , maxi);

        }
        return maxi;
        
    }
};