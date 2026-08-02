class Solution {
public:
    string maskPII(string s) {
        if (s.find('@') != string::npos) {
            for (char &c : s) c = tolower(c);

            int p = s.find('@');
            return s[0] + string("*****") + s[p - 1] + s.substr(p);
        }

        string d;
        for (char c : s)
            if (isdigit(c)) d += c;

        int n = d.size();
        string a;

        if (n > 10) {
            a = "+";
            for (int i = 0; i < n - 10; i++) a += "*";
            a += "-";
        }

        a += "***-***-";
        a += d.substr(n - 4);

        return a;
    }
};