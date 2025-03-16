class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans =0 ;
        unordered_map<int,int> tell;

        for(int i=0 ; i<answers.size(); i++){
            int x = answers[i];
            if(x == 0) ans++;
            else if(tell.count(x + 1)){
                tell[ x +1 ]++;
                if( x+1 == tell[x+1])  tell.erase(x+1);
            }
            else{
                tell[ x +1 ]++;
                ans += x+1;
            }
        }

        return ans;
        
    }
};