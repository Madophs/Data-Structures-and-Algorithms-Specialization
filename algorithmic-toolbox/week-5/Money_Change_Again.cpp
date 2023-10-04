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

const int MAX_VALUE = 1004;
const int INF = 9999999;

int coins[] = {1, 3, 4};
int memo[MAX_VALUE][4];

int minNumOfCoins(int money, int index = 0)
{
    if (index >= 3 || money < 0)
        return INF;

    if (memo[money][index] != -1)
        return memo[money][index];

    if (money == 0)
        return 0;

    int min1 = minNumOfCoins(money-coins[index], index) + 1;
    int min2 = minNumOfCoins(money, index + 1);
    return memo[money][index] = min(min1, min2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(int) * MAX_VALUE * 4);
    int money;
    cin >> money;

    cout << minNumOfCoins(money) << '\n';
    return 0;
}
