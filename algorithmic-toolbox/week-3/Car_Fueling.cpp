#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dist, miles, n;
    cin >> dist >> miles >> n;

    vector<int> stops(n);
    for (int &stop : stops)
        cin >> stop;
    stops.emplace_back(dist);

    int refills = 0;
    int lastRefill = 0;
    bool possible = true;

    for (int i = 0; i < (int)stops.size() && possible ; ++i) {
        if (miles < (stops[i]-lastRefill))
            possible  = false;

        while (i < (int)stops.size() && miles >= (stops[i+1]-lastRefill))
            ++i;

        if (i == (int)stops.size())
            break;

        ++refills;
        lastRefill = stops[i];
    }

    if (possible) {
        cout << refills << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
