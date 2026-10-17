class Solution {
public:
    string removeDuplicates(string s) {
        int i;
        string ans;
        for(i=0;i<s.size();i++){ if(ans.size()>0&&ans.back()==s[i]) ans.pop_back();
            else ans+=s[i];
        }return ans;
    }
};