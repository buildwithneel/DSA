class Solution {
public:
    int minChanges(string s) {
        int changes=0;
        int i;
        for(i=0;i<s.size();i+=2){
            if (s[i]!=s[i+1]) changes++;
        }return changes;
    }
};