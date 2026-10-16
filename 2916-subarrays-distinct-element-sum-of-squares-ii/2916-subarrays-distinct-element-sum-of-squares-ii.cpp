class Solution {
public:
    const long long MOD=1000000007;
    vector<long long> sum,sq,lazy;
    int n;

    int sumCounts(vector<int>& nums) {
        n=nums.size();
        sum.assign(4*n,0);
        sq.assign(4*n,0);
        lazy.assign(4*n,0);
        vector<int> last(100001,-1);
        long long ans=0;
        int i;
        for(i=0;i<n;i++){
            int l=last[nums[i]]+1;
            update(1,0,n-1,l,i);
            last[nums[i]]=i;
            ans=(ans+sq[1])%MOD;
        }
        return ans;
    }

    void push(int node,int l,int r){
        if(lazy[node]==0) return;
        long long d=lazy[node];
        int m=(l+r)/2;
        int a=node*2,b=node*2+1;
        sq[a]=(sq[a]+2*d*sum[a]+d*d*(m-l+1))%MOD;
        sum[a]=(sum[a]+d*(m-l+1))%MOD;
        lazy[a]=(lazy[a]+d)%MOD;
        sq[b]=(sq[b]+2*d*sum[b]+d*d*(r-m))%MOD;
        sum[b]=(sum[b]+d*(r-m))%MOD;
        lazy[b]=(lazy[b]+d)%MOD;
        lazy[node]=0;
    }

    void update(int node,int l,int r,int ql,int qr){
        if(l>qr||r<ql) return;
        if(l>=ql&&r<=qr){
            long long len=r-l+1;
            sq[node]=(sq[node]+2*sum[node]+len)%MOD;
            sum[node]=(sum[node]+len)%MOD;
            lazy[node]++;
            return;
        }
        push(node,l,r);
        int m=(l+r)/2;
        update(node*2,l,m,ql,qr);
        update(node*2+1,m+1,r,ql,qr);
        sum[node]=(sum[node*2]+sum[node*2+1])%MOD;
        sq[node]=(sq[node*2]+sq[node*2+1])%MOD;
    }
};