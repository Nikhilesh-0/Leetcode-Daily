class Solution {
public:
    long long palindrome(long long n) {
        string s = to_string(n);
        string rev = s;
        s.pop_back();
        reverse(rev.begin(), rev.end());
        s += rev;
        return stoll(s);
    }
    bool isprime(long long n) {
        if (n < 2) {
            return false;
        }
        int sq = sqrt(n);
        for(int i = 2; i<=sq; ++i) {
            if(n%i==0) return false;
        }
        return true;
    }
    int primePalindrome(int n) {
        if (n <= 2) return 2;
        if (n <= 3) return 3;
        if (n <= 5) return 5;
        if (n <= 7) return 7;
        if (n <= 11) return 11; 
    
        long long i = 1;
        while (true) {
            long long t = palindrome(i);
            if (t>=n && isprime(t)) return t;
            ++i;
        }
        return -1;
    }
};