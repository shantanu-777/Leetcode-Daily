class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int ans=0;
        int l=0, r=k;
        int vowels=0;
        if(n==k){
            for(int i=0; i<k; i++){
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                    vowels++;
                }
            }
            return vowels;
        }
        for(int i=0; i<k; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                vowels++;
            }
        }
        ans=vowels;
        int i=0;
        while(r<n){
            if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u'){
                vowels--;
            }
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u'){
                vowels++;
            }
            ans=max(ans, vowels);
            l++;
            r++;
        }
        return ans;
    }
};