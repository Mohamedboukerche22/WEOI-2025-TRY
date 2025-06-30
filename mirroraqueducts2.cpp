// 13 points
#include<bits/stdc++.h>


using std::vector;
using std::cin;
using std::cout;



vector<int> count(int N, vector<int> S, vector<int> P) {
    vector<int> result(N);

    for (int k = 0; k < N; k++) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (i == k) continue;

            bool dominated = false;
            for (int j = 0; j < N; j++) {
                if (j == k || j == i) continue;
                if (S[j] > S[i] && P[j] < P[i]) {
                    dominated = true;
                    break;
                }
            }
            if (!dominated) cnt++;
        }
        result[k] = cnt;
    }

    return result;
}
