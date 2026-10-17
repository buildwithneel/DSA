class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<pair<int,int>> v;
        int i;
        for(i=0;i<n;i++) v.push_back({digitSum(nums[i]),nums[i]});
        sort(v.begin(),v.end());
        vector<int> pos(n);
        unordered_map<int,int> mp;
        for(i=0;i<n;i++) mp[nums[i]]=i;
        for(i=0;i<n;i++){
            if(nums[i]==v[i].second) continue;
            int j=mp[v[i].second];
            mp[nums[i]]=j;
            mp[v[i].second]=i;
            swap(nums[i],nums[j]);
            ans++;
        }
        return ans;
    
    }
    int digitSum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
};