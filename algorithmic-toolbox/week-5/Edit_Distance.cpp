#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Matrix;

inline int min3(const int& a, const int& b, const int& c)
{
    return min(a, min(b, c));
}

Matrix createMatrix(const uint32_t& height, const uint32_t& width)
{
    Matrix vec(height+1, vector<int>(width+1, 0));
    return vec;
}

void initMatrix(Matrix& matrix)
{
    int cols = (int)matrix.front().size();
    for (int i = 0, c = 0; i < cols; ++i)
        matrix[0][i] = c++;
    int rows = (int)matrix.size();
    for (int i = 0, c = 0; i < rows; ++i)
        matrix[i][0] = c++;
}

int editDistance(string& a, string &b)
{
    Matrix matrix = createMatrix(a.size(), b.size());
    initMatrix(matrix);

    int rows = (int)matrix.size();
    int cols = (int)matrix.front().size();
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (a[i-1] == b[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                int lastDeletionCost = matrix[i-1][j] + 1;
                int lastInsertionCost = matrix[i][j-1] + 1;
                int lastMismatchCost = matrix[i-1][j-1] + 1;
                int lastOptimalAction = min3(lastMismatchCost, lastDeletionCost, lastInsertionCost);
                matrix[i][j] = lastOptimalAction;
            }
        }
    }

    return matrix.back().back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    cin >> a >> b;
    cout << editDistance(a, b);
    return 0;
}
