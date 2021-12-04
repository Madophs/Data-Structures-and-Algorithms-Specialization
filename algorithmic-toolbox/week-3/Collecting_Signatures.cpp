#include <bits/stdc++.h>

using namespace std;

bool sortByEnd(pair<int, int> a, pair<int, int> b)
{
    if (a.second <= b.second)
        return true;
    if (a.second == b.second)
        return a.first < b.first;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b;
    cin >> n;
    vector<pair<int, int>> vec;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }

    sort(vec.begin(), vec.end(), sortByEnd);

    vector<int> coor;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (visited[i])
            continue;

        int fartest = vec[i].second;
        for (int j = i;j < n; ++j) {
            if (visited[j])
                continue;
            if (fartest >= vec[j].first && fartest <= vec[j].second)
                visited[j] = true;
        }
        coor.push_back(fartest);
    }

    cout << coor.size() << '\n';
    for (int i = 0; i < (int)coor.size(); ++i) {
        if (i)
            cout << " ";

        cout << coor[i];
    }
    return 0;
}
