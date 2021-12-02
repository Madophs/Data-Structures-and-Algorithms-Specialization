#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9;

void fibonacci(uint64_t nth, uint64_t mod)
{
    const int SIZE = 50000;
    uint32_t fibs[SIZE];
    fibs[0] = 0, fibs[1] = 1;
    int index = 1;
    do {
        ++index;
        fibs[index] = (fibs[index-1] + fibs[index-2]) % mod;
    } while (fibs[index] != 1 || fibs[index-1] != 0);
    int resIndex = nth % ((long long)(index-1));
    cout << fibs[resIndex] << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    uint64_t nth, mod;
    cin >> nth >> mod;
    fibonacci(nth, mod);
    return 0;
}
