#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

typedef vector<vector<int32_t>> Matrix;

inline Matrix createMatrix(const uint32_t& n, const uint32_t& m)
{
   Matrix matrix(n, vector<int32_t>(m, 0));
   return matrix;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int32_t> vec1, vec2;
    uint32_t n, m;
    cin >> n; vec1.resize(n);
    for (auto i = 0u; i < n; ++i) cin >> vec1[i];
    cin >> m; vec2.resize(m);
    for (auto i = 0u; i < m; ++i) cin >> vec2[i];

    const int32_t MATCH_COST = 1;

    ++n, ++m;
    Matrix matrix = createMatrix(n, m);
    for (auto i = 1u; i < n; ++i) {
        for (auto j = 1u; j < m; ++j) {
            if (vec1[i-1u] == vec2[j-1u]) {
                matrix[i][j] = matrix[i-1u][j-1u] + MATCH_COST;
            } else {
                matrix[i][j] = max(matrix[i-1u][j], matrix[i][j-1u]);
            }
        }
    }

    auto answer = matrix.back().back();
    cout << answer << endl;
    return 0;
}
