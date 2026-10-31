class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD=1e9+7;
        int m=grid.size(),n=grid[0].size();
        vector<int>down(n,0),nextDown(n,0);
        int ans=0;
        int i,j;
        for(i=0;i<m;i++){
            int right=0;
            fill(nextDown.begin(),nextDown.end(),0);
            for(j=0;j<n;j++){
                int r=right,d=down[j];
                if(grid[i][j]==0){
                    int w=(i==0 && j==0)?1:(r+d)%MOD;
                    if(i==m-1 && j==n-1) ans=w;
                    right=w;
                    nextDown[j]=w;
                }else{
                    right=d;
                    nextDown[j]=r;
                }
            }
            swap(down,nextDown);
        }return ans;
    }
};