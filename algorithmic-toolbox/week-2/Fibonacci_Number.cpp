#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n)
{
    long long fib[n+1];
    fib[0] = 0, fib[1] = 1;
    if (n <= 1)
        return fib[n];

    for (int i = 2; i < n+1; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    cout << fibonacci(n) << '\n';
    return 0;
}
