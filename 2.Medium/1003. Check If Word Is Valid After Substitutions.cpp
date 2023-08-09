class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0;i < s.size();i ++)
        {
            char ch = s[i];
            if(ch == 'a') st.push(ch);
            else
            {
                if(st.empty()) return false;
                if((ch == 'b' && st.top() != 'a') || (ch == 'c' && st.top() != 'b')) return false;
                st.pop();
                if(ch == 'b')st.push(ch);
            }
        }
        return(st.empty());
    }
};
