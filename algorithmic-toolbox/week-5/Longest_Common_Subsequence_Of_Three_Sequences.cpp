#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

typedef vector<int32_t> Vector;
typedef vector<Vector> Matrix;
typedef vector<Matrix> Matrix3D;

inline Matrix3D createMatrix(const uint32_t& n, const uint32_t& m, const uint32_t& l)
{
    return Matrix3D(n, Matrix(m, Vector(l, 0)));
}

template <typename R, typename... T>
R maxVariadic(T&&... values)
{
    R r = 0;
    for (auto val : {values...}) {
        r = max(r, static_cast<R>(val));
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    uint32_t n, m, l;
    vector<int32_t> v1, v2, v3;
    cin >> n; v1.resize(n);
    for (auto i = 0u; i < n; ++i) cin >> v1[i];
    cin >> m; v2.resize(m);
    for (auto i = 0u; i < m; ++i) cin >> v2[i];
    cin >> l; v3.resize(l);
    for (auto i = 0u; i < l; ++i) cin >> v3[i];

    const int32_t MATCH_COST = 1;
    ++n, ++m, ++l;
    Matrix3D matrix = createMatrix(n, m, l);
    for (auto i = 1u; i < n; ++i) {
        for (auto j = 1u; j < m; ++j) {
            for (auto k = 1u; k < l; ++k) {
                if (v1[i-1u] == v2[j-1u] && v2[j-1u] == v3[k-1u]) {
                    matrix[i][j][k] = matrix[i-1u][j-1u][k-1u] + MATCH_COST;
                } else {
                    matrix[i][j][k] = maxVariadic<int32_t>(
                            matrix[i-1u][j][k], matrix[i][j-1u][k], matrix[i][j][k-1u],
                            matrix[i-1u][j-1u][k], matrix[i-1u][j][k-1u], matrix[i][j-1u][k-1u]);
                }
            }
        }
    }
    auto answer = matrix.back().back().back();
    cout << answer << endl;
    return 0;
}
