#include <bits/stdc++.h>

using namespace std;

vector<int> startPoints, endPoints;

int upperBound(vector<int> &vec, int val)
{
    if (vec.size() == 1)
        return val < vec.front() ? 0 : 1;

    int low = 0, high = vec.size()-1, mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (val == vec[mid]) {
            if (mid+1 <= high && vec[mid+1] == vec[mid]) {
                low = mid+1;
                continue;
            }
            break;
        }
        if (val < vec[mid]) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    if (vec[mid] <= val)
        ++mid;
    return mid;
}

int segmentsInterseccion(int &val)
{
    return upperBound(startPoints, val) - upperBound(endPoints, val-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s, s1, s2, p, p1;
    vector<int> points;
    cin >> s >> p;

    while (s-- && cin >> s1 >> s2) {
        startPoints.push_back(s1), endPoints.push_back(s2);
    }

    while (p-- && cin >> p1)
        points.push_back(p1);

    sort(startPoints.begin(), startPoints.end());
    sort(endPoints.begin(), endPoints.end());

    for (int i = 0; i < points.size(); ++i) {
        if (i) cout << " ";
        cout << segmentsInterseccion(points[i]);
    }
    cout << '\n';
    return 0;
}
