class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            if(i>=1&&nums[i]==nums[i-1])
            continue;
            int l=i+1;
            int r=nums.size()-1;
            int s=-1*nums[i];

            while(l<r){
                if((nums[l]+nums[r])<s){
                    l++;
                }
                else if((nums[l]+nums[r])>s){
                    r--;
                }
                else{
                    ans.push_back({nums[i],nums[l],nums[r]});
                    int x=nums[l];
                    l++;
                    r--;
                    while(l<r && nums[l]==x){
                        l++;
                    }
                    while(l<r && nums[r]==x){
                        r--;
                    }
                }

            }
        }
        return ans;
    }
        
};