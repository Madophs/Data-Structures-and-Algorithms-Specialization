#include <bits/stdc++.h>

using namespace std;

int nthFibonacci(int nth)
{
    const int n = 61;
    int fib[n];
    fib[0] = 0, fib[1] = 1;
    if (n <= 1)
        return fib[nth];

    for (int i = 2; i < n; ++i) {
        fib[i] = (fib[i-1] + fib[i-2]) % 10;
    }

    int index = nth % 60;
    return fib[index] % 10;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    cout << nthFibonacci(n) << '\n';
    return 0;
}
