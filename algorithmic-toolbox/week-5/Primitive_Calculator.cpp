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

int memo[3][1000002];
const int INF = 9999999;

int minNumOfOperations(int state, int transition = 2)
{
    if (state < 0)
        return INF;

    if (state <= 1)
        return 0;

    if (memo[transition][state] != -1)
        return memo[transition][state];

    int optimal = INF;
    int sol1 = minNumOfOperations(state/3, 2) + 1 + (state % 3);
    int sol2 = minNumOfOperations(state/2, 1) + 1 + (state % 2);

    if (sol1 < sol2) {
        memo[0][state] = 2;
    } else {
        memo[0][state] = 1;
    }

    optimal = min(sol1, sol2);

    return memo[transition][state] = optimal;
}

void printSolution(int n)
{
    int action = memo[0][n], number = n;
    vector<int> solution;
    for (int i = 0; i < 30 && number > 1; ++i) {
        solution.push_back(number);
        if (action == 2) {
            while (number % 3 != 0 && number > 1)
                solution.push_back(--number);
            number /= 3;
        } else {
            while (number % 2 != 0 && number > 1)
                solution.push_back(--number);
            number /= 2;
        }
        action = memo[0][number];
    }

    cout << "1";
    for (auto item = solution.rbegin(); item != solution.rend(); ++item)
        cout << " " << *item;
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    memset(memo, -1, sizeof(memo));
    cout << minNumOfOperations(n) << '\n';
    printSolution(n);
    return 0;
}
