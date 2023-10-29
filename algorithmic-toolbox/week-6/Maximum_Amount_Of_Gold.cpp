#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

typedef vector<int32_t> IVec;
typedef vector<IVec> Matrix;
Matrix memo;
IVec weights;

int32_t knapsack()
{
    for (auto i = 1u; i < memo.size(); ++i) {
        for (auto weight = 1; weight < (int)memo.front().size(); ++weight) {
            auto maxValue = memo[i-1][weight];
            if (weight >= weights[i]) {
                maxValue = max(memo[i-1][weight-weights[i]] + weights[i], maxValue);
            }
            memo[i][weight] = maxValue;
        }
    }
    return memo.back().back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int32_t W, n;
    cin >> W >> n;
    memo.assign(n+1, vector<int32_t>(W+1, 0));
    weights.resize(n+1);
    for (int i = 1; i < n+1; ++i) {
        cin >> weights[i];
    }
    cout << knapsack() << endl;
    return 0;
}
