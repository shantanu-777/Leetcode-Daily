class Solution {
public:

void dfs(int num,vector<int>&ans,int n)
{
    if(num>n)
    return ;
    ans.push_back(num);
    num*=10;
    for(int i=0;i<=9;i++)
    {
        dfs(num+i,ans,n);
    }
}
    vector<int> lexicalOrder(int n) {

        vector<int>ans;
        for(int i=1;i<=9;i++)
        {
            dfs(i,ans,n);
        }
        return ans;
        
    }
};