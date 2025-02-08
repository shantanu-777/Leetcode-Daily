class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            int temp = nums[i]+nums[j];
            if(temp==k){
                i++;
                j--;
                ans++;
            }else if(temp>k){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};