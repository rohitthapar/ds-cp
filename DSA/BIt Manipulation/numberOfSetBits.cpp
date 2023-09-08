class Solution{
public:
    int helper(int n){
        int c = 0;
        while((1<<c) <= n) c++;
        return c-1;
    }
    int countBits(int n){
        if(n == 0) return 0;
        int x = helper(n);
        int ans = x*(1<<(x-1)) + (n - (1<<x) + 1) + countBits(n - (1<<x));
        return ans;
    }
};