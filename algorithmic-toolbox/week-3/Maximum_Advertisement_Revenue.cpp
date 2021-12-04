#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin  >> n;
    vector<int> profits(n), clicks(n);
    for (int &val : profits)
        cin >> val;

    for (int &val : clicks)
        cin >> val;

    sort(profits.begin(), profits.end(), greater<int>());
    sort(clicks.begin(), clicks.end(), greater<int>());

    int64_t ans = 0;
    for (int i = 0; i < n; ++i)
        ans += (int64_t)((int64_t)profits[i] * (int64_t)clicks[i]);

    cout << ans << endl;;
    return 0;
}
