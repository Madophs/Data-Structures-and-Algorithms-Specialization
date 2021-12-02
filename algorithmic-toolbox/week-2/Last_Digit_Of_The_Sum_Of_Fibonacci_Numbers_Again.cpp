#include <bits/stdc++.h>

using namespace std;

vector<unsigned long long> getFirst60DigitsOfFibs()
{
    vector<unsigned long long> fibs;
    fibs.push_back(0), fibs.push_back(1);

    for (int i = 2; i < 61; ++i) {
        unsigned long long newFib = fibs[i-1] + fibs[i-2];
        fibs.push_back(newFib);
    }

    for_each(fibs.begin(), fibs.end(), [&](unsigned long long &item) {
            item %= 10;
    });

    return fibs;
}

unsigned long long getLastDigitSum(unsigned long long nth, vector<unsigned long long> &fibs)
{
    unsigned long long sumPerCycle = 280LL;
    unsigned long long loops = floor(nth / 60LL);
    int pos = (int)(nth % 60LL);
    unsigned long long ans = loops * sumPerCycle;
    unsigned long long lastPartialSum = accumulate(fibs.begin(), fibs.begin() + pos + 1, 0);
    ans += lastPartialSum;
    return ans;
}

unsigned long long getLastPartialSumDigit(unsigned long long a, unsigned long long b, vector<unsigned long long> &fibs)
{
    a = a > 0? a-1 : a;
    unsigned long long partialSumA = getLastDigitSum(a, fibs);
    unsigned long long partialSumB = getLastDigitSum(b, fibs);
    return (partialSumB - partialSumA) % 10LL;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unsigned long long a, b;
    cin >> a >> b;
    vector<unsigned long long> fibs = getFirst60DigitsOfFibs();
    cout << getLastPartialSumDigit(a, b, fibs) << endl;
    return 0;
}
