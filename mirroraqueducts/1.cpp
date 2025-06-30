// 0 points

#include<bits/stdc++.h>

using namespace std;
const int MAX = 10e9+1;

vector<int> count(int N, vector<int> S, vector<int> P) {
    vector<tuple<int,int,int>>C;
    for(int i=0;i<P.size();i++)
    {
       C.push_back({i,S[i],P[i]});
    }
    sort(C.begin(),C.end(),[](const auto &a,const auto &b){
        return get<1>(a) > get<1>(b);
    });
    vector<bool>OP(N,true);
    int min = MAX;
    for(const auto &m : C){
        int in = get<0>(m);
        int p = get<2>(m);
        if(p > min){
            OP[in] = false;
        }else{
            min = p;
        }

    }
    vector<int> ans(N);
    for(int i =0;i<N;i++){
        int count = 0;
        for(int j=0;j<N;j++){
            if(i == j){
                continue;
            }
            if(OP[i]){
                count++;
            }
        }
        ans[i] = count;
    }

   return ans;
}
