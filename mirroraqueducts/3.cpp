#include<bits/stdc++.h>

using namespace std;

struct Material {
    int S, P, index;
};

vector<int> count(int N, vector<int> S, vector<int> P) {
    vector<Material> moh(N);
    for (int i = 0; i < N; ++i) {
        moh[i] = {S[i], P[i], i};
    }

    sort(moh.begin(), moh.end(), [](const Material &a, const Material &b) {
        return a.S > b.S;
    });

    vector<int> C(N, 0);
    for (int k = 0; k < N; ++k) {
        int count = 0;
        int min = INT_MAX;
        for (int i = 0; i < N; ++i) {
            if (moh[i].index == k) continue;
            if (moh[i].P < min) {
                min = moh[i].P;
                count++;
            }
        }
        C[k] = count;
    }

    return C;
}
