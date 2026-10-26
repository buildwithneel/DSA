class Solution {
public:
    int uniquePaths(int m, int n) {
       long long r=1;
        int i;
        for(i=1;i<m;i++){
            r=r*(n-1+i)/i;
        }
        return r;
    }
};