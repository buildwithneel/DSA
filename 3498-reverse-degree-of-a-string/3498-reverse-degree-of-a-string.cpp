class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        int i;
        for(i=0;i<s.size();i++){
            int rev='z'-s[i]+1;
            ans+=rev*(i+1);
        }return ans;
    }
};