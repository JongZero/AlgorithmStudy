#include <iostream>
using namespace std;

int main()
{
	int a, b, v;
	cin >> a >> b >> v;

	/// Mark1
	/// 1일부터 ~ 조건을 만족할 때까지 루프
	/// 시간 초과 되버림
	/*
	// 걸린 날짜
	int count = 1;

	// 현재 올라간 m
	int now = 0;

	while (true)
	{
		// 낮에 올라가고
		now += a;

		// 다 올라갔는지 체크
		if (now >= v)
			break;

		// 밤에 내려온다. 하루가 지난다.
		now -= b;

		count++;
	}

	cout << count;
	*/

	/// Mark2
	/// 공식을 유추
	// 꼭대기에 올라가기 하루 전까지 며칠인지 구하고 +1을 한다.
	int count = v - a;

	// 하루 (낮, 밤)이 모두 지났을 때 올라간 미터
	int c = a - b;

	// 꼭대기에 올라가기 하루 전
	// int
	int iCount = count / c;

	// float
	double fCount = (double)count / c;

	// 같지 않다면 소수점이 있다는 뜻
	if (fCount != iCount)
	{
		// 소수점이 있으면 하루가 더 걸리므로 +1 해준다.
		iCount += 1;
	}

	// 낮에 올라가는 미터가 정상보다 높거나 같다면 하루 만에 올라갈 것이다.
	if (a >= v)
	{
		iCount = 1;
	}
	// 1이상이라면 3일 이상 올라가야되는 것이다.
	else if (iCount >= 1)
	{
		// 하루를 더해준다.
		iCount += 1;
	}
	// 1보다 작다면 2일은 올라가야 되는 것이다.
	else
	{
		iCount = 2;
	}
	
	cout << iCount;

	return 0;

	// 꼭대기에 올라가기 하루 전을 구할 때
	// 형을 float로 했을 때 틀렸고, double로 바꾸니 맞았다.
	// 밑에는 질문답변에 있는 어느 답변
	/// float는 int와 동일한 4바이트(32비트)를 가지므로 지수부를 나타낼 부분만큼 유효숫자가 줄어듭니다.
	/// 3 1 1000000000 같은 값을 넣었을 때 (float)v / fin 값을
	/// 50000000 및 49999999와 비교해 보시면 모두 같다고 나오는 걸 확인하실 수 있습니다. 
	/// ( 내 경우엔 (float)count / c; )
	/// 두 정수를 float로 변환할 때 유효숫자 끝자리가 손실되면서 구분이 불가능해지기 때문입니다.
}