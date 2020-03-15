#include <iostream>
using namespace std;

int main()
{
	string S;
	cin >> S;
	for (size_t i = 1; i < S.size(); i++)
	{
		if (S[i] == S[i - 1])
		{
			if (S[i] == 'z') { S[i] = 'a'; }
			else {
				S[i] += 1;
			}
		}
	}
	cout << S;

}