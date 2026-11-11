class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

        auto total = [&](long long z) {
            return z * cb + max(0LL, n1 - z) * c1 + max(0LL, n2 - z) * c2;
        };

        long long lo = min(n1, n2), hi = max(n1, n2);

        return min({total(0), total(lo), total(hi)});
    }
};