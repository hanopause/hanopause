#include <bits/stdc++.h>
using namespace std;

struct DP{
    long long r, g, b;
};

#define num 1000007
DP dp[3][100001];

void run() {

    dp[0][2].r = 1, dp[0][2].g = 1, dp[0][2].b = 1;
    dp[1][2].r = 1, dp[1][2].g = 1, dp[1][2].b = 0;
    dp[2][2].r = 1, dp[2][2].g = 0, dp[2][2].b = 1;

    for(int i=3; i<=100000; i++) {
        dp[0][i].r = (dp[0][i-1].r + dp[1][i-1].r + dp[2][i-1].r)%num;
        dp[0][i].g = (dp[0][i-1].g + dp[1][i-1].g + dp[2][i-1].g)%num;
        dp[0][i].b = (dp[0][i-1].b + dp[2][i-1].b + dp[1][i-1].b)%num;

        //cannot handle dp[2][i]
        dp[1][i].r = (dp[0][i-1].r + dp[1][i-1].r)%num;
        dp[1][i].g = (dp[0][i-1].g + dp[1][i-1].g)%num;
        dp[1][i].b = (dp[0][i-1].b + dp[1][i-1].b)%num;

        //cannot handle dp[1][i]
        dp[2][i].r = (dp[0][i-1].r + dp[2][i-1].r)%num;
        dp[2][i].b = (dp[0][i-1].b + dp[2][i-1].b)%num;
        dp[2][i].g = (dp[0][i-1].g + dp[2][i-1].g)%num;

    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int N, T;
    cin>>T;
    run();
    while(T--) {
        cin>>N;
        if(N == 1) cout<<"3\n";
        else cout<<(dp[0][N].r + dp[0][N].g + dp[0][N].b + dp[1][N].r + dp[1][N].g + dp[2][N].r + dp[2][N].b)% num<<"\n";
    }

}
