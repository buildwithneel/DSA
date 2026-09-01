class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
 {
    return 0;
 }  
 
 long long total=0;
 long long current=0;
 int i;
 for(int i=2;i<n;i++){
    if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
        current++;
        total+=current;
    }else{
        current=0;
    }
 }return total;
  }
};