class Solution {
public:
    int maxArea(vector<int>& height) {
       int left=0;
       int right=height.size()-1;
       int MaxVol=0;
       while(left<right){
        int width= right-left;
        int ht=min(height[left],height[right]);
        int currVol = ht*width;
        MaxVol = max(MaxVol,currVol);
        height[left]<height[right] ? left++:right--;
       }
       return MaxVol;
    }
};