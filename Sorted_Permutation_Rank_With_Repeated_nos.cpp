#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int mod = 1000003;
long long s = 1;
long long fact(int n) {
    long long f = 1;
    for (int i = 2; i <= n; i++) {
        f = (f * i) % 1000003;
    }
    return f;
}
long long power(long long x, long long y, long long mod) {
    long long res = 1;
    while (y) {
        if (y & 1) res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

int solve(string s) {
    int n = s.size();
    long long mod = 1000003;
    long long ans = 1; // As we have to add 1 to get rank. 
    for (int i = 0; i < n; i++) {
        long long less_than = 0;
        for (int j = i + 1; j < n; j++) {
            if ((int)s[i] > (int)s[j]) {
                less_than += 1;
            }
        }
        vector<int> freq(52, 0);
        for (int j = i; j < n; j++) {
            if (s[j] >= 'A' && s[j] <= 'Z')
                freq[s[j] - 'A'] += 1;
            else
                freq[s[j] - 'a' + 26] += 1;
        }
        long long denominator = 1;
        for (long long ele : freq) {
            denominator = (denominator * fact(ele)) % mod;
        }

        long long inverse = power(denominator, mod - 2, mod); // inverse = (1/denominator)%mod

        long long permutation = (fact(n - i - 1) * inverse) % mod;
        long long total_permutation = (less_than * permutation) % mod;

        ans = (ans + total_permutation) % mod;
    }
    return ans;
}
int main()
{
    string s = "bbbbaaaa";
    int count = solve(s);
    cout << count << endl;
}
