#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int> &vec)
{
    for (int i = 0; i < (int)vec.size(); ++i) {
        if (i) cout << " ";
        cout << vec[i];
    }
    cout << '\n';
}

int alignNumbers(int pivot,vector<int> &vec, vector<int> &indexes)
{
    if (indexes.empty())
        return pivot + 1;
    int i, j;
    for (i = pivot, j = indexes.size()-1; i < indexes.front() &&  j >= 0; ++i) {
        if (vec[i] == vec[pivot]) {
            if (i >= indexes[j])
                --j;
            continue;
        }
        swap(vec[i], vec[indexes[j]]);
        --j;
    }
    return i;
}

pair<int, int> apply3Partition(vector<int> &vec, int l, int r)
{
    int pivot = l++;
    vector<int> pivotIndexes;
    while (l < r) {
        while (l < r && vec[l] < vec[pivot]) ++l;
        while (r > l && vec[r] >= vec[pivot]) {
            if (vec[r] == vec[pivot])
                pivotIndexes.push_back(r);
            --r;
        }
        swap(vec[l], vec[r]);
        if (vec[r] == vec[pivot])
            pivotIndexes.push_back(r);
        if (l < r)
            --r;
    }

    if (vec[l] >= vec[pivot])
        --l;

    swap(vec[l], vec[pivot]);
    int rightPivot = alignNumbers(l, vec, pivotIndexes);
    return make_pair(l, rightPivot);
}

void QuickSort(vector<int> &vec, int l, int r)
{
    if (l >= r)
        return;
    pair<int, int> pivot = apply3Partition(vec, l, r);
    QuickSort(vec, l, pivot.first-1);
    QuickSort(vec, pivot.second, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int size, elem;
    vector<int> vec;
    cin >> size;
    while (size-- && cin >> elem) {
        vec.push_back(elem);
    }

    QuickSort(vec, 0, vec.size()-1);

    printVec(vec);
    return 0;
}
