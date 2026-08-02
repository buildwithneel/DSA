class Solution {
public:
    bool isPossible(vector<int>& t) {
        priority_queue<long long>pq;
        long long s=0;
        for(int x:t){
            pq.push(x);
            s+=x;
        }
        while(1){
            long long x=pq.top();
            pq.pop();
            long long r=s-x;
            if(x==1||r==1)
            return true;
            if(r==0||x<=r)
            return false;
            long long y=x%r;
            if(y==0)
            return false;
            pq.push(y);
            s=r+y;
        }
    }
};