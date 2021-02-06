/**
 * 71. Simplify Path 
 *
 */



class Solution {
public:
    string simplifyPath(string path) {   
        size_t i = 0;
        size_t l;
        size_t r;
        
        stack<string> st;
        stack<string> st2;
        string res = "";
        
        while (i < path.size()) {
            l = path.find_first_not_of("/", i);
            r = path.find_first_of("/", l);
            i = r;
            if (l < r) {
                string curr = path.substr(l, r - l);
                if (curr == ".") {
                    continue;
                }
                if (curr == "..") {
                    if (!st.empty()) { 
                        st.pop();
                    }
                    continue;
                }
                st.push(curr);
            }
        }
        
        while (!st.empty()) {
            string curr = st.top();
            st2.push(curr);
            st.pop();
        }

        while (!st2.empty()) {
            res += "/" + st2.top();
            st2.pop();
        }
        
        return res.empty() ? "/" : res;
    }
};