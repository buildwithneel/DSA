class Solution {
public:
    string reverseParentheses(string s) {
        while (s.find('(') != string::npos) {
            int r = s.find(')');
            int l = s.rfind('(', r);
            reverse(s.begin() + l + 1, s.begin() + r);
            s.erase(r, 1);
            s.erase(l, 1);
        }return s;
    }
};