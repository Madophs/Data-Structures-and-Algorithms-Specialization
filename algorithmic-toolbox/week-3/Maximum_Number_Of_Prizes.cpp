#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, price = 1;
    vector<int> pairs;
    cin >> n;

    while (n > 0) {
        if (n >= price) {
            n -= price;
            pairs.push_back(price);
        } else {
            pairs.back() += n;
            break;
        }

        ++price;
    }

    cout << pairs.size() << endl;
    for (int i = 0; i < pairs.size(); ++i) {
        if (i)
            cout << " ";
        cout << pairs[i];
    }
    return 0;
}
