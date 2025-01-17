class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        std::vector<int> vec;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++){
            while(vec.size()>0&&heights[i]<=heights[vec.back()]){
                int process=heights[vec.back()];
                vec.pop_back();

                int left=(!vec.size())?-1:vec.back();
                int tmp=(i-left-1)*process;
                ans=std::max(ans,tmp);
            }
            vec.push_back(i);
        }
        return ans;
            //save lowest on stack?
    }
};