class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        int n=digits.size()-1;
        for (i=n;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
           digits[i]=0; 
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};