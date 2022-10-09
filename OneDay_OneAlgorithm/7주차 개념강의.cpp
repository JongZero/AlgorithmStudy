// [출처] [알고리즘 강의] 7주차.DP, 동적계획법, 다이나믹프로그래밍 | 작성자 큰돌

// 어떤 idx에서 어떤 경우의 수가 있나를 늘 생각해야 한다.
// 완전 탐색의 구조를 만들고 메모이제이션을 한다. 즉, 완전 탐색 + 메모이제이션
// 메모이제이션 : 어떤 상태값을 자료구조에 저장하는 것. (map, set, 배열...)
// 이 상태값을 정의하는 것이 DP의 핵심이다.
// dp[idx][turn];

// dp의 조건
// 1. 참조투명성을 가져야 하며 입력을 제외한 외적요소에 결과값이 영향을 미치지 않아야 한다.
// 2. 겹치는 부분 문제가 있어야 한다.
// 3. 최적 부분구조를 가지고 있어야 한다.
// 보통 1번은 코딩테스트 문제라면 다 지켜서 준다.
// 참고로 참조투명성이란 외부 전역변수에 영향을 끼치지 않아야 하고 입력에 의해서만
// 출력이 결정되어야 하는 것을 말한다.

// 사실 코딩테스트를 풀 때 이렇게 3가지를 생각하기란 너무나 어렵다.
// 그래서... 이렇게 생각하는 것이 좋다.
// 1. 이거 완전탐색인데?
// 2. 경우의 수가 너무나 큰데?
// 3. 메모이제이션이 가능하나? (배열로 담을 수 있나)
// 하고 들어가는 것이다. 
// 배열에 넣기에도 너무 크다. 예를 들어 배열이 1000만정도가 필요하다.
// 그러면 그리디구나... 아니면 다른 알고리즘을 써야 하는구나 하고 들어가는 것이다.

// 또한 묵시적으로 DAG 구조를 가지고 있어야 한다. 방향성이 있고 사이클이 없는 그래프 구조를 가져야 한다.
// 사실 이 부분은 좀 어려운 DP 문제를 다룰 때 신경써야 한다.
// 예를 들어 양방향 간선이 존재하거나 사이클이 있는 그래프 같은 경우 preprocess를 통해
// DAG를 만들어 DP 문제를 풀어야 한다.

/*
// 2240, 자두나무 - 틀림(모르겠음)
#include<bits/stdc++.h>
using namespace std;
int dp[1004][2][34], n, m, b[1004];

int go(int idx, int tree, int cnt) {
    cout << "dp[" << idx << "][" << tree << "][" << cnt << "] : \n";
    //cout << idx << "초, " << tree << "번 나무, 남은 움직임 횟수 : " << cnt << '\n';
    if (cnt < 0) return -1e9;
    if (idx == n) return cnt == 0 ? 0 : -1e9;
    int& ret = dp[idx][tree][cnt];
    cout << "\t\t" << ret << '\n';
    if (~ret)
    {
        cout << "기존에 있음 ! \n";
        return ret;
    }
    ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
    cout << "dp[" << idx << "][" << tree << "][" << cnt << "] : " << "기존에 없어서 넣음 ret: " << ret << '\n';
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> b[i];
    int go1 = go(0, 1, m - 1);
    cout << "\n=====================================\n";
    int go2 = go(0, 0, m);
    cout << max(go1, go2) << '\n';
    return 0;
}
*/

/*
// 15989, 1,2,3 더하기 4 - 틀림(모르겠음)
#include<bits/stdc++.h>
using namespace std;

int dp[10001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    dp[0] = 1;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 10000; j++)
        {
            dp[j] += dp[j - i];
        }
    }

    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
*/

// 2748, 피보나치 수 2 - 맞음
#include<bits/stdc++.h>
using namespace std;

long long n, dp[91];
long long fibo(int s)
{
    cout << "s : " << s << '\n';
    long long f1 = 0;
    long long f2 = 0;
    if (dp[s - 1] == -1) dp[s - 1] = fibo(s - 1);
    if (dp[s - 2] == -1) dp[s - 2] = fibo(s - 2);
    f1 = dp[s - 1];
    f2 = dp[s - 2];
    return f1 + f2;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    dp[1] = 1;

    cin >> n;
    if (n == 0 || n == 1) cout << dp[n];
    else cout << fibo(n);

	return 0;
}

