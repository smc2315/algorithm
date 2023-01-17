#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	int N, K;
	int con[100] = { 0, };//콘센트
	vector<int> v;
	vector<int> step; //순서
	cin >> N >> K;
	int count = 0;
	for (int i = 0; i < K; i++)
	{
		int input;
		cin >> input;
		step.push_back(input);

	}
	for (int i = 0; i < K; i++)
	{
		int cnt = 0;
		int empty = 101;
		bool already = false;
		for (int j = 0; j < N; j++)
		{

			if (con[j] == step[i])
			{
				already = true;
			}
			else if (con[j] == 0)
			{
				if (empty > j)
					empty = j;
			}
		}
		if (already == true)
			continue;
		else if (already == false && empty != 101)
		{
			con[empty] = step[i];
		}
		else if (already == false && empty == 101)
		{
			int idx,tmp = -1;
			for (int j = 0; j < N; j++)
			{
				int idxtmp = 0;
				for (int k = i + 1; k < K; k++)
				{
					if (con[j] == step[k])
						break;
					idxtmp++;
				}
				if (idxtmp > tmp)
				{
					idx = j;
					tmp = idxtmp;
				}

			}
			count++;
			con[idx] = step[i];
		}

	}
	std::cout << count;
	return 0;
}