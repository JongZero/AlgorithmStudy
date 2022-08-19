#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio( false );
	std::cin.tie( NULL );

	vector<int> pieceTable = { 1,1,2,2,2,8 };
	vector<int> input( 6 );

	for ( int i = 0; i < 6; i++ )
	{
		cin >> input[i];
		cout << pieceTable[i] - input[i] << " ";
	}

	return 0;
}