#include <bits/stdc++.h>

template <typename Arg, typename... Args>
void debug(std::ostream& out, Arg&& arg, Args&&... args)
{
    out << std::forward<Arg>(arg);
    using expander = int[];
    (void)expander{0, (void(out << " " << std::forward<Args>(args)), 0)...};
    out << std::endl;
}

using namespace std;

typedef pair<int, int> Node;

double calcDist(Node &a, Node &b)
{
    return sqrt((double)pow((double)abs(a.second - b.second), 2.0f) + (double)pow((double)abs(a.first - b.first), 2.0f));
}

double bruteForce(Node vec[], int n) {
    double localMinDist = numeric_limits<double>::max();
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            localMinDist = min(calcDist(vec[i], vec[j]), localMinDist);
        }
    }
    return localMinDist;

}

double minPointsInMiddle(Node strip[], double minDist, int n)
{
    for (int i = 0; i < n; ++i) {
        int limit = min(n, i + 8);
        for (int j = i+1; j < limit; ++j) {
            minDist = min(calcDist(strip[i], strip[j]), minDist);
        }
    }
    return minDist;
}

double divideAndConquer(Node vec[], Node vecy[], int x, int y, int n)
{
    if (abs(x-y) <= 4) {
        return bruteForce(vecy, n);
    }

    int middle = (x + y) / 2;
    int middlePoint = vec[middle].first;
    int leftSize = abs(middle-x), rightSize = abs(y-middle);
    Node leftY[leftSize], rightY[rightSize];
    for (int i = 0, l = 0, r = 0; i < n; ++i) {
        if (l < leftSize && vecy[i].second <= middlePoint || (r >= rightSize))
            leftY[l++] = vecy[i];
        else
            rightY[r++] = vecy[i];
    }

    double leftMin = divideAndConquer(vec, leftY, x, middle, leftSize);
    double rightMin = divideAndConquer(vec, rightY, middle, y, rightSize);
    double minDist = min(leftMin, rightMin);

    Node strip[n];
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (minDist > abs(vecy[i].second - middlePoint)) {
            strip[s++] = vecy[i];
        }
    }

    return minPointsInMiddle(strip, min(leftMin, rightMin), s);
}


double closestPoint(Node vecX[], Node vecY[], int &n) {
    if (n < 8)
        return bruteForce(vecY, n);

    sort(vecX, vecX + n);
    sort(vecY, vecY + n);
    return divideAndConquer(vecX, vecY, 0, n, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(5);

    int n;
    double x, y;
    cin >> n;
    Node vecX[n], vecY[n];
    for (int i = 0; i < n && cin >> x >> y; ++i) {
        vecX[i] = make_pair(x, y);
        vecY[i] = make_pair(y, x);
    }

    double minDist = closestPoint(vecX, vecY, n);
    cout << minDist << endl;

    return 0;
}


