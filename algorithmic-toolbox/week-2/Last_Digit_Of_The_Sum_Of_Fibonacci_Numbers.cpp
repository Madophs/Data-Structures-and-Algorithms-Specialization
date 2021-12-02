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

int getLastDigitOfSum(unsigned long long nth, vector<unsigned long long> &fibs)
{
    unsigned long long sumPerCycle = accumulate(fibs.begin(), fibs.end(), 0LL);
    unsigned long long loops = floor(nth / 60LL);
    int pos = (int)(nth % 60LL);
    unsigned long long ans = loops * sumPerCycle;
    unsigned long long lastPartialSum = accumulate(fibs.begin(), fibs.begin() + pos + 1, 0);
    ans += lastPartialSum;
    ans %= 10;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unsigned long long nth;
    cin >> nth;
    vector<unsigned long long> fibs = getFirst60DigitsOfFibs();
    cout << getLastDigitOfSum(nth, fibs) << endl;
    return 0;
}
