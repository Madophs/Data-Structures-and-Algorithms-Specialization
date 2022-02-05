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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &item : vec)
        cin >> item;

    sort(vec.begin(), vec.end());
    int prevItem = -2, item = -1, currCount = 0, maxCount = 0;
    for (int i = 0; i < vec.size(); ++i) {
        item = vec[i];
        if (item != prevItem) {
            maxCount = max(currCount, maxCount);
            currCount = 0;
        }
        ++currCount;
        prevItem = item;
    }

    maxCount = max(currCount, maxCount);

    if (maxCount > (vec.size() / 2))
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
    return 0;
}
