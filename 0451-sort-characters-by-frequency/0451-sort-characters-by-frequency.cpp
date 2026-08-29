class Solution {
public:
    string frequencySort(string s) {
        int freq[256]={0};

        for (char c:s)
            freq[c]++;

        string ans="";

        for (int count=s.size();count>=1;count--) {
            for (int i=0;i<256;i++) {
                if (freq[i]==count) {
                    for (int j= 0;j<count;j++)
                        ans += (char)i;
               } } }
        return ans;
    }
};