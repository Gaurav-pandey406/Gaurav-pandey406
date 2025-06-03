class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0;
        int e = height.size()-1;
        int maximum = 0;
        while(s<e){
            int l = e-s;
            int b = min(height[s], height[e]);
            int area = l*b;
            maximum = max(area,maximum);
            if(height[s]<height[e]){
                s++;
            }
            else{
                e--;
            }
        }
    return maximum;
    }
};