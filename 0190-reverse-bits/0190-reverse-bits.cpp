class Solution {
public:
    int reverseBits(int n) {
        unsigned int ans=0;
        int  i;
        for(i=0;i<32;i++){
            ans=(ans<<1)|(n&1);
            n=n>>1;
        }
        return ans;
    }
};