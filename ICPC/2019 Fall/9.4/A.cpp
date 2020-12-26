#include <iostream>

using namespace std;

int main()
{
	int task;
	cin >> task;
	int ret = 0;
	for (int i = 1; i <= task/2; i++) {
		if ((task-i)%i == 0)
			ret++;
	}
	cout << ret << endl;
	return 0;
}