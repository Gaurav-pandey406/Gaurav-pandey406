class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> result;
        sort(arr.begin() , arr.end());
        int count = 1;

        for(int i = 1; i<arr.size(); i++){
            if(arr[i] == arr[i-1]){
                count++;
            }
            else{
                result.push_back(count);
                count = 1;
            }


        }
        result.push_back(count);

        sort(result.begin() , result.end());
        for(int i = 1;i<result.size();i++){
            if(result[i] == result[i-1]){
                return false;
            }
        }

        return true;
        

       
        
        
    }
};