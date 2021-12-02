#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

uint64_t GCD(uint64_t a, uint64_t b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

uint64_t LCM(uint64_t a, uint64_t b)
{
    if (a == b)
        return a;
    uint64_t maxPossible= a * b;
    return maxPossible / GCD(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long a, b;
    cin >> a >> b;
    cout << LCM(a, b) << '\n';
    return 0;
}
