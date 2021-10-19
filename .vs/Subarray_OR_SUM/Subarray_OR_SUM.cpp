#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& A) {
    long long mod = 1000000007;
    long long i, j, n = A.size(), czero = 0;
    long long to_sum = (n * (n + 1)) / 2;
    long long cones = 0, twos = 1, consec = 0;
    long long ans = 0;
    int s = 1;
    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (!(A[j] & s))
            {
                //czero++;
                consec++;
                //cout << "consecutive =" << consec << endl;
            }
            else {
                czero += ((consec * (consec + 1)) / 2);
                consec = 0;
            }

        }
        if (czero == 0)//&& consec != 0)
        {
            czero += ((consec * (consec + 1)) / 2);
            consec = 0;
        }
        if (consec != 0)
        {
            czero += ((consec * (consec + 1)) / 2);
            consec = 0;
        }
        s = s << 1;
        //cout << "s= "<< s << endl;
        //cout << "czero= " << czero << endl;
        cones += to_sum - czero;
        //cout << "cones= "<<cones << endl;
        ans += ((cones % mod) * (twos % mod)) % mod;
        twos *= 2;
        czero = 0;
        cones = 0;

    }
    return int(ans % mod);

}
int main()
{
    vector<int> A = { 1,2,3,4,5 };
    int count = solve(A);
    cout << count;
}