#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll dp[101][100001];

//35��° �ٿ� ret=0�� �ƴ϶� ���� ���� �����ϱ� �³׿�..
//�������� ��ݾ��� �ڿ������ ��õǾ� �־, 0���� �������� ä������ ���ٰ� �����ϰ� ���ǵ�
//Ȥ�� �߾˰��ø� ��Ȯ�� �������ֽø� �����ϰڽ��ϴ� ^ ^

/// �亯 ->
//�� ��Ȳ���� ���������� �ð� ���� �����ϴ� ���� �ƿ� �Ұ����� ��� ��ݾ��� 0������ ��ȯ�ϰ� �Ǹ� 
//�� �������� ä���� ��ݾ׸�ŭ�� ���� �� �ִٰ� �Ǵ��ϴ� �Ͱ� �����ϴ�.
//�����δ� �������� �����ϴ� ���� �Ұ����ϱ� ������ �� ��찡 ������� �ʾƾ� �մϴ�.

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