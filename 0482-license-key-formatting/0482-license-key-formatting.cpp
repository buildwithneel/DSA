class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string a;
        for(int i=s.size()-1,c=0;i>=0;i--){
            if(s[i]=='-')
            continue;
            if(c==k){
                a+='-';
                c=0;
            }
            a+=toupper(s[i]);
            c++;
        }
        reverse(a.begin(),a.end());
        return a;
    }
};