#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

typedef pair<int32_t, int32_t> Pair;
typedef vector<pair<int32_t, int32_t>> VecPair;
typedef vector<VecPair> CountSequence;
enum Parent {WithoutInheretedParent = 1, WithInheretedParent};

struct StackState {
    StackState* m_parent{nullptr};
    uint32_t m_index;
    uint32_t m_subIndex{0};
    int32_t m_result{0};
    bool m_secondCallPerformed{false};
    StackState(uint32_t i_index)
        :m_index(i_index)
    {
    }

    ~StackState()
    {
        m_parent = nullptr;
    }
};

inline Pair& getIndexCounter(const StackState& frame, CountSequence& memo)
{
    if (frame.m_parent != nullptr) {
        return memo[frame.m_parent->m_index][frame.m_parent->m_subIndex];
    }
    return memo[frame.m_index][frame.m_subIndex];
}

inline StackState createItemForStack(StackState& frame, Parent parent)
{
    StackState data{frame.m_index + 1};

    if (parent == Parent::WithoutInheretedParent) {
        data.m_parent = &frame;
    } else {
        if (frame.m_parent == nullptr) {
            data.m_parent = &frame;
        } else {
            data.m_parent = frame.m_parent;
        }
    }

    return data;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t n, m;
    cin >> n; int32_t a1[n];
    for (auto i = 0u; i < n; ++i) cin >> a1[i];
    cin >> m; int32_t a2[m];
    for (auto i = 0u; i < m; ++i) cin >> a2[i];

    CountSequence memo;
    for (uint32_t i = 0; i < n; ++i) {
        auto value2count = a1[i];
        VecPair indexes; // Index <-> Sequence Count
        for (uint32_t j = 0; j < m; ++j) {
            if (value2count == a2[j]) {
                indexes.push_back(make_pair(j, -1));
            }
        }

        if (!indexes.empty()) {
            memo.push_back(indexes);
        }
    }

    int answer = 0;
    stack<StackState> s;
    if (!memo.empty()) {
        s.push(StackState{0});
    }

    while (!s.empty()) {
        auto& frame = s.top();

        if (frame.m_index >= memo.size()) {
            memo[frame.m_parent->m_index][frame.m_parent->m_subIndex].second = 1;
            s.pop();
            continue;
        }

        bool stackcall = false;
        while (!stackcall && frame.m_subIndex < memo[frame.m_index].size()) {
            auto& indexCounter = memo[frame.m_index][frame.m_subIndex];
            if (frame.m_result == 0 && indexCounter.second == -1) {
                s.push(createItemForStack(frame, Parent::WithoutInheretedParent));
                s.push(createItemForStack(frame, Parent::WithInheretedParent));
                stackcall = true;
            } else if (!frame.m_secondCallPerformed) {
                s.push(createItemForStack(frame, Parent::WithInheretedParent));
                frame.m_secondCallPerformed = true;
                stackcall = true;
            } else {
                indexCounter.second = frame.m_result != 0 ? frame.m_result : indexCounter.second;
                if (frame.m_parent != nullptr) {
                    auto& parentIndexCounter = memo[frame.m_parent->m_index][frame.m_parent->m_subIndex];
                    if (parentIndexCounter.first < indexCounter.first) {
                        frame.m_parent->m_result = max(indexCounter.second + 1, frame.m_parent->m_result);
                    } else {
                        frame.m_parent->m_result = max(1, frame.m_parent->m_result); // At least the parent matches with himself
                    }
                }
                answer = max(indexCounter.second, answer);
                frame.m_result = 0;
                if (++frame.m_subIndex < memo[frame.m_index].size()) {
                    frame.m_secondCallPerformed = false;
                }
            }
        }

        if (!stackcall) {
            s.pop();
        }

    }
    //debug(memo);
    cout << answer << endl;
    return 0;
}
