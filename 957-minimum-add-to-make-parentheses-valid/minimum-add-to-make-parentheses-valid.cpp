class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                if(st.empty())ans++;
                else st.pop();
            }
            else st.push(s[i]);
        }
        ans+=st.size();
        return ans;
    }
};