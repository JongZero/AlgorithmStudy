// [��ó] [�˰��� ����] 7����.DP, ������ȹ��, ���̳������α׷��� | �ۼ��� ū��

// � idx���� � ����� ���� �ֳ��� �� �����ؾ� �Ѵ�.
// ���� Ž���� ������ ����� �޸������̼��� �Ѵ�. ��, ���� Ž�� + �޸������̼�
// �޸������̼� : � ���°��� �ڷᱸ���� �����ϴ� ��. (map, set, �迭...)
// �� ���°��� �����ϴ� ���� DP�� �ٽ��̴�.
// dp[idx][turn];

// dp�� ����
// 1. ���������� ������ �ϸ� �Է��� ������ ������ҿ� ������� ������ ��ġ�� �ʾƾ� �Ѵ�.
// 2. ��ġ�� �κ� ������ �־�� �Ѵ�.
// 3. ���� �κб����� ������ �־�� �Ѵ�.
// ���� 1���� �ڵ��׽�Ʈ ������� �� ���Ѽ� �ش�.
// ����� ���������̶� �ܺ� ���������� ������ ��ġ�� �ʾƾ� �ϰ� �Է¿� ���ؼ���
// ����� �����Ǿ�� �ϴ� ���� ���Ѵ�.

// ��� �ڵ��׽�Ʈ�� Ǯ �� �̷��� 3������ �����ϱ�� �ʹ��� ��ƴ�.
// �׷���... �̷��� �����ϴ� ���� ����.
// 1. �̰� ����Ž���ε�?
// 2. ����� ���� �ʹ��� ū��?
// 3. �޸������̼��� �����ϳ�? (�迭�� ���� �� �ֳ�)
// �ϰ� ���� ���̴�. 
// �迭�� �ֱ⿡�� �ʹ� ũ��. ���� ��� �迭�� 1000�������� �ʿ��ϴ�.
// �׷��� �׸��𱸳�... �ƴϸ� �ٸ� �˰����� ��� �ϴ±��� �ϰ� ���� ���̴�.

// ���� ���������� DAG ������ ������ �־�� �Ѵ�. ���⼺�� �ְ� ����Ŭ�� ���� �׷��� ������ ������ �Ѵ�.
// ��� �� �κ��� �� ����� DP ������ �ٷ� �� �Ű��� �Ѵ�.
// ���� ��� ����� ������ �����ϰų� ����Ŭ�� �ִ� �׷��� ���� ��� preprocess�� ����
// DAG�� ����� DP ������ Ǯ��� �Ѵ�.

/*
// 2240, �ڵγ��� - Ʋ��(�𸣰���)
#include<bits/stdc++.h>
using namespace std;
int dp[1004][2][34], n, m, b[1004];

int go(int idx, int tree, int cnt) {
    cout << "dp[" << idx << "][" << tree << "][" << cnt << "] : \n";
    //cout << idx << "��, " << tree << "�� ����, ���� ������ Ƚ�� : " << cnt << '\n';
    if (cnt < 0) return -1e9;
    if (idx == n) return cnt == 0 ? 0 : -1e9;
    int& ret = dp[idx][tree][cnt];
    cout << "\t\t" << ret << '\n';
    if (~ret)
    {
        cout << "������ ���� ! \n";
        return ret;
    }
    ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
    cout << "dp[" << idx << "][" << tree << "][" << cnt << "] : " << "������ ��� ���� ret: " << ret << '\n';
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
// 15989, 1,2,3 ���ϱ� 4 - Ʋ��(�𸣰���)
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

// 2748, �Ǻ���ġ �� 2 - ����
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

