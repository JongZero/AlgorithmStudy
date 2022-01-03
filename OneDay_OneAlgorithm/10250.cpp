#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int h = 0; // 호텔의 층의 개수
		int w = 0; // 호텔의 방의 개수
		int n = 0; // 몇 번째 손님인지

		cin >> h >> w >> n;

		// 1 ~ 6
		if (n <= h)
		{
			string strN = to_string(n);
			strN += "01";

			cout << strN << "\n";
		}
		// 01호는 아니다. 넘어선다.
		else
		{
			// 02호부터 시작한다.
			int startW = 2;

			// n - h해서 h보다 작으면 그 열에 있는 것이다.
			// 10 - 6
			int checkN = n - h;

			while (true)
			{
				if (checkN <= h)
				{
					break;
				}
				else
				{
					// 계속 열의 개수(층의 개수)만큼 빼주면서 어느 열에 있는지 찾는다.
					checkN -= h;

					// 03호, 04호, 05호...
					startW++;
				}
			}

			string strN = to_string(checkN);

			// 십의 자리일 경우 그냥 붙인다.
			if (startW >= 10)
			{
				strN += to_string(startW);
			}
			// 일의 자리일 경우 0을 붙인다.(01, 02, 03...)
			else
			{
				strN += "0";
				strN += to_string(startW);
			}

			cout << strN << "\n";
		}
	}
	
	return 0;
}