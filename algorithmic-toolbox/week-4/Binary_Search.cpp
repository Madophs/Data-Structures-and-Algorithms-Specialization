#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &sequence, int item) {
    int lower = 0, upper = (int)sequence.size() -1, middle = 0;
    while (lower <= upper) {
        middle = ((lower + upper) / 2);
        if (sequence[middle] == item)
            return middle;

        if (item < sequence[middle]) {
            upper = middle - 1;
        } else {
            lower = middle + 1;
        }
    }

    return -1;
}


void bulkSearch(vector<int> &sequence, vector<int> &toSearch) {
    for (int i = 0; i < (int)toSearch.size(); ++i) {
        if (i) cout << " ";
        cout << binarySearch(sequence, toSearch[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n;
    vector<int> sequence(n);
    for (int &val : sequence)
        cin >> val;
    cin >> k;
    vector<int> toSearch(k);
    for (int &val : toSearch)
        cin >> val;

    bulkSearch(sequence, toSearch);
    return 0;
}
