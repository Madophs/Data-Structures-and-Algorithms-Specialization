#include <bits/stdc++.h>

using namespace std;

bool greedyCmp(int a, int b) {
    int digitsA = floor(log10(a)) + 1;
    int digitsB = floor(log10(b)) + 1;

    if (digitsA == digitsB)
        return a > b;

    long long altA = atol((to_string(a) + to_string(b)).c_str());
    long long altB = atol((to_string(b) + to_string(a)).c_str());

    return altA > altB;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> num(n);

    for (int &val : num)
        cin >> val;

    sort(num.begin(), num.end(), greedyCmp);

    string ans = "";
    for (int &val : num) {
        ans += to_string(val);
    }

    cout << ans << endl;
    return 0;
}
