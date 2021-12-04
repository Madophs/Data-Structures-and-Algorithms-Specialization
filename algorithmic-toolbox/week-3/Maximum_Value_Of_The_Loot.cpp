#include <bits/stdc++.h>
#include <ios>

using namespace std;

struct Item {
    double value;
    double weight;
    double valuePerWeight;

    Item() {
        this->value = 0.0;
        this->weight = 0.0;
        this->valuePerWeight = 0.0;
    }

    // Overload operator to sort by decreasing order
    bool operator < (Item item) {
        return !(this->valuePerWeight <= item.valuePerWeight);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(4);

    int n , W;
    cin >> n >> W;
    vector<Item> items(n, Item());

    for (int i = 0; i < n; ++i) {
        cin >> items[i].value >> items[i].weight;
        items[i].valuePerWeight = items[i].value / items[i].weight;
    }

    sort(items.begin(), items.end());

    double ans = 0.0;
    for (Item item: items) {
        if ((int)item.weight <= W) {
            ans += (item.valuePerWeight * item.weight);
            W -= item.weight;
        } else {
            ans += (item.valuePerWeight * W);
            W = 0;
        }

        if (W <= 0)
            break;
    }

    cout << ans << endl;
    return 0;
}
