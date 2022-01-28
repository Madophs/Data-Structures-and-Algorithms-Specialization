#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i) {
        if (i) cout << " ";
        cout << vec[i];
    }
    cout << '\n';
}

// BTW is bubble sort
long long mergeSort(vector<int> &vec, int l, int r)
{
    int estLoops = abs(r-l);
    long long inversions = 0;
    bool swapping = true;
    for (int c = 0; c < estLoops && swapping; ++c) {
        swapping = false;
        for (int i = l; i < (r-1); ++i) {
            if (vec[i] > vec[i+1]) {
                swap(vec[i], vec[i+1]);
                ++inversions;
                swapping = true;
            }
        }
    }
    return inversions;
}

long long  merge(vector<int> &vec)
{
    long long inversions = 0, half = vec.size() / 2;
    vector<int> tmpVec(vec);
    inversions += mergeSort(tmpVec, 0, half);
    inversions += mergeSort(tmpVec, half, tmpVec.size());

    int l_h1 = 0, r_h1 = half;
    int l_h2 = half, r_h2 = tmpVec.size();
    int index = 0;

    while (l_h1 < r_h1 && l_h2 < r_h2) {
        if (tmpVec[l_h1] <= tmpVec[l_h2]) {
            vec[index++] = tmpVec[l_h1++];
        } else {
            vec[index++] = tmpVec[l_h2++];
            inversions += (half - l_h1);
        }
    }
    while (l_h1 < r_h1) vec[index++] = tmpVec[l_h1++];
    while (l_h2 < r_h2) vec[index++] = tmpVec[l_h2++];
    return inversions;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    vector<int> vec;
    cin >> n;

    for (int i = 0, val = 0; i < n; ++i) {
        cin >> val;
        vec.push_back(val);
    }

    long long inversions = 0;
    inversions = merge(vec);
    cout << inversions << '\n';
    return 0;
}
