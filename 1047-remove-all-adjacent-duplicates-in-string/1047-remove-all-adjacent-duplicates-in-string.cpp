class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char>st;
        for(int i = 0;i<n;i++){
           
            
            if(!st.empty() && st.top() == s[i]){
                st.pop();
                continue;
            }
            st.push(s[i]);


        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin() , res.end());

        return res;
    }
};