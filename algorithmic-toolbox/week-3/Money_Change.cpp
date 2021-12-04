#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> currency({10, 5, 1});
    int m, coins = 0;
    cin >> m;

    for (int &value: currency) {
        coins += floor(m / value);
        m %= value;
    }

    cout << coins << endl;

    return 0;
}
