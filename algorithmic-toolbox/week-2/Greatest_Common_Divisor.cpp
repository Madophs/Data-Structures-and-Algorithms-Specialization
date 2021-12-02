#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

uint32_t gcd(uint32_t a, uint32_t b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
    return 0;
}
