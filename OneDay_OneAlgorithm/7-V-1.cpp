#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll dp[101][100001];

//35번째 줄에 ret=0이 아니라 음의 값을 넣으니까 맞네요..
//문제에서 모금액은 자연수라고 명시되어 있어서, 0보다 작은값이 채워질수 없다고 생각하고 쓴건데
//혹시 잘알고계시면 명확히 설명해주시면 감사하겠습니다 ^ ^

/// 답변 ->
//그 상황에서 마지막까지 시간 내에 도달하는 것이 아예 불가능한 경우 모금액을 0원으로 반환하게 되면 
//그 이전까지 채워온 모금액만큼은 모을 수 있다고 판단하는 것과 같습니다.
//실제로는 목적지에 도달하는 것이 불가능하기 때문에 이 경우가 고려되지 않아야 합니다.

struct A
{
	int walkTime;
	int walkMoney;
	int rideTime;
	int rideMoney;
};
A a[101];

ll func(int cnt, int timee)
{
	if (timee > k) return -1e15;
	if (cnt > n) return 0;
	long long& d = dp[cnt][timee];
	if (d != -1) return d;
	d = -1e15;
	d = max(d, func(cnt + 1, timee + a[cnt].walkTime) + a[cnt].walkMoney);
	d = max(d, func(cnt + 1, timee + a[cnt].rideTime) + a[cnt].rideMoney);
	//cout << cnt << ", " << timee << " : " << d << '\n';
	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int q, w, e, r;
		cin >> q >> w >> e >> r;
		a[i].walkTime = q;
		a[i].walkMoney = w;
		a[i].rideTime = e;
		a[i].rideMoney = r;
	}
	cout << func(0, 0);
}