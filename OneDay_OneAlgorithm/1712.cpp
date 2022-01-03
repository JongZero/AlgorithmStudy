#include <iostream>
#include <limits.h>
using namespace std;

/// 1712

int main()
{
	int A, B, C;

	cin >> A >> B >> C;

	// 한 대 판매비용이 한 대 생산비용보다 커야 손익분기점이 발생 가능하다.
	if (B < C)
	{
		/// Mark 1 반복문 사용
		/// 시간초과로 틀리다고 나옴
		/*
		// 손익분기점을 넘는 노트북 판매량
		unsigned long long n = 0;

		// 초기 시작 개수 유추
		int k = A + B;
		n = k / C;

		for (unsigned long long i = n; i < ULLONG_MAX; i++)
		{
			// 노트북을 생산하는 총 비용
			unsigned long long d = A + (B * i);

			// 노트북을 판매해 얻은 총 수입
			unsigned long long totalR = C * i;

			// 총 비용 보다 총 수입이 클 때
			if (d < totalR)
			{
				// 개수 저장
				n = i;
				break;
			}
		}
		*/

		/// Mark2 반복문 사용 X
		/// 예제1과 예제3의 공통점 발견
		/// 이를 토대로 공식을 유추해서 적용
		
		// 손익분기점을 넘는 노트북 판매량
		unsigned int n = 0;
		n = A / (C - B) + 1;

		cout << n;
	}
	else
	{
		cout << -1;
	}	

	return 0;
}