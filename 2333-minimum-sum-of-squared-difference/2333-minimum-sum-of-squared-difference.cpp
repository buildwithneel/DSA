
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long> diff;
        long long k=(long long)k1+k2,total=0,mx=0;

        for(int i=0;i<nums1.size();i++){
            long long x=abs(nums1[i]-nums2[i]);
            diff.push_back(x);
            total+=x;
            mx=max(mx,x);
        }

        if(k>=total)
            return 0;

        long long l=0,r=mx;

        while(l<r){
            long long mid=(l+r)/2,need=0;

            for(int i=0;i<diff.size();i++)
                need+=max(0LL,diff[i]-mid);

            if(need<=k)
                r=mid;
            else
                l=mid+1;
        }

        long long need=0,ans=0;

        for(int i=0;i<diff.size();i++){
            need+=max(0LL,diff[i]-l);
            long long x=min(diff[i],l);
            ans+=x*x;
        }

        long long rem=k-need;
        ans-=rem*(2*l-1);

        return ans;
    }
};