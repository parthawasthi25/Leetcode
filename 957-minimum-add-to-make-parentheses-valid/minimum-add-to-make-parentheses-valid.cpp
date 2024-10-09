class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int c=0;
        for(char ch:s)
        {
            if(ch == '(')
                st.push(ch);
            if(ch == ')')
            {
                if(!st.empty())
                    st.pop();
                else 
                    c++;
            }
        }
        return c+st.size();
    }
};
