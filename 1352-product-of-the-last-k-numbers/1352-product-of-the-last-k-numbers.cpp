class ProductOfNumbers {
    vector<int> pre;

public:
    ProductOfNumbers() {
        pre = {1};
    }

    void add(int num) {
        if (num == 0) {
            pre = {1};
        } else {
            pre.push_back(pre.back() * num);
        }
    }

    int getProduct(int k) {
        int n = pre.size();
        if (k >= n) return 0;
        return pre.back() / pre[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */