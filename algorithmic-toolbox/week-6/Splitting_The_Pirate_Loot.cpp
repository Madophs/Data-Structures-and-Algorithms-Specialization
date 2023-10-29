#include <bits/stdc++.h>
#include <valarray>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

typedef vector<short> Vec;
typedef vector<Vec> Matrix;
typedef vector<Matrix> Matrix3D;

Matrix3D memo;

bool knapsackHasSolution(const vector<int>& loot, int n, int a, int b, int c)
{
    if (a == 0 && b == 0 && c == 0) {
        return true;
    }

    if (n >= (int)loot.size()) {
        return false;
    }

    if (memo[a][b][c] != -1) {
        return memo[a][b][c];
    }

    short isSolution = 0;
    if (a-loot[n] >= 0) {
        isSolution |= ((short)knapsackHasSolution(loot, n+1, a-loot[n], b, c));
    }

    if (!isSolution && b-loot[n] >= 0) {
        isSolution |= ((short)knapsackHasSolution(loot, n+1, a, b-loot[n], c)) << 1;
    }

    if (!isSolution && c-loot[n] >= 0) {
        isSolution |= ((short)knapsackHasSolution(loot, n+1, a, b, c-loot[n])) << 2;
    }

    return isSolution;
}

int splitLootIsPossible(const vector<int>& loot)
{
    if (loot.size() < 3u) return 0;
    auto totalSum = accumulate(loot.begin(), loot.end(), 0);
    if (totalSum % 3 != 0) return 0;
    int splitSize = totalSum / 3;
    memo.resize(splitSize + 1, Matrix(splitSize + 1, Vec(splitSize+1, -1)));
    return knapsackHasSolution(loot, 0, splitSize, splitSize, splitSize);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> loot(n, 0);
    for (int i = 0; i < (int)loot.size(); ++i) cin >> loot[i];
    cout << splitLootIsPossible(loot) << endl;
    return 0;
}
