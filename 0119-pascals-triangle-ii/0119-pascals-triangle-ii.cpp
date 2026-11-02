class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i,j;
        vector<int> row(rowIndex+1,1);
        for(i=2;i<=rowIndex;i++){
            for(j=i-1;j>0;j--){
                row[j]+=row[j-1];
            }
        }return row;
    }
};