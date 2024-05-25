#include <cctype>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int maxn = 26;

int n;
int pref[maxn][maxn];
int order[maxn][maxn];
int nxt[maxn];
int fw[maxn];
int fh[maxn];
queue<int> que;

void engage(const int & man, const int & woman)
{
	if (fh[woman] != -1)
	{
		fw[fh[woman]] = -1;
		que.push(fh[woman]);
	}
	fw[man] = woman;
	fh[woman] = man;
}

int main()
{
	int T;
	char name[2];
	char line[maxn + 3];
	int CN;
	int i, j;
	int man, woman;

	int T;
	cin >> T;
	for (int TN = 0; TN < T ; TN++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> name;
		for (int i = 0; i < n; i++)
			cin >> name;
		for (int i = 0; i < n; i++)
		{
			cin >> line;
			man = line[0] - 'a';
			for (int j = 0; j < n; j++)
				pref[man][j] = line[j + 2] - 'A';
		}
		for (int i = 0; i < n; i++)
		{
			cin >> line;
			woman = line[0] - 'A';
			for (int j = 0; j < n; j++)
				order[woman][line[j + 2] - 'a'] = j;
		}

		memset(nxt, 0, sizeof(nxt[0]) * n);
		memset(fh, -1, sizeof(fh[0]) * n);
		for (int i = 0; i < n; i++)
			que.push(i);
		for ( ; !que.empty() ; que.pop())
		{
			man = que.front();
			woman = pref[man][nxt[man]];
			nxt[man]++;

			if (fh[woman] == -1 ||
				order[woman][man] < order[woman][fh[woman]])
				engage(man, woman);
			else
				que.push(man);
		}

		if (TN > 0)
			cout << endl;
		for (int i = 0; i < n; i++)
			cout << ('a' + i) << " " << ('A' + i) << endl;
	}

	return 0;
}