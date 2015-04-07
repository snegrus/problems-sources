#ifdef ONLINE_JUDGE
	#include <bits/stdc++.h>
#else
	#include <algorithm>
	#include <bitset>
	#include <cassert>
	#include <cmath>
	#include <cstdio>
	#include <cstdlib>
	#include <cstring>
	#include <iostream>
	#include <map>
	#include <set>
	#include <stack>
	#include <string>
	#include <utility>
	#include <vector>
	#include <queue>
#endif

using namespace std;

	// lambda : [] (int a, int b) -> bool { body return }
	// string r_str = R"(raw string)"

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define LL long long
#define ULL unsigned long long
#define BASE 73
#define NMAX 10000
#define NMAX2 20001
#define MOD1 1000000007
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()
#define CRLINE Duxar(__LINE__);
#define SHOWME(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#define ENTER putchar('\n');

int dx4[] = {-1, 0, 1, 0};
int dy4[] = {0, 1, 0, -1};

int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

void Duxar(int _this_line) {
#ifndef ONLINE_JUDGE
	printf("\n . . . . . . . . . . . . . Passed line - %d\n", _this_line);
#endif
}

template <class T>
void ReadNo(T &_value) {
	T _sign = 1;
	char ch;
	_value = 0;
	while(!isdigit(ch = getchar())) {
		(ch == '-') && (_sign = -1);
	}
	do {
		_value = _value * 10 + (ch - '0');
	} while(isdigit(ch = getchar()));
	_value *= _sign;
}

template <class T>
void AddNr(T &a, T b) {
	a = a + b;
	while (a >= MOD1) {
		a -= MOD1;
	}
	while (a < 0) {
		a += MOD1;
	}
}

int N, K;
vector <vector <int> > mat;
vector <int> sol;

int main(){
	string fileInput = "dezbateri";

	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);

//	freopen("input.cpp", "r", stdin);
	
	int i, j, v1, v2, v3;
	char c1, c2;
	ReadNo(N); ReadNo(K);
	mat.resize(N + 1, vector <int> (N + 1));
	
	for (i = 0; i < K; ++i) {
		scanf("%d%c%d%c%d\n", &v1, &c1, &v2, &c2, &v3);
		if (c1 == '>') {
			mat[v1][0] -= mat[v2][v1];
			mat[v1][0] -= mat[v3][v1];
			mat[v2][v1] = 1;
			mat[v3][v1] = 1;
			mat[v1][0] += 2;
		}
		else {
			mat[v1][0] -= mat[v3][v1];
			mat[v2][0] -= mat[v3][v2];
			mat[v3][v1] = 1;
			mat[v3][v2] = 1;
			mat[v1][0]++;
			mat[v2][0]++;
		}
	}
	
	for (i = 1; i <= N; ++i) {
		for (j = 1; j < i; ++j) {
			if (mat[i][j] + mat[j][i] == 2) {
				printf("0");
				return 0;
			}
		}
	}
	
	bool done = false;
	while (!done) {
		done = true;
		for (i = 1; i <= N; ++i) {
			if (mat[i][0] == 0) {
				done = false;
				sol.pb(i);
				mat[i][0] = -1;
				for (j = 1; j <= N; ++j) {
					mat[j][0] -= mat[i][j];
					mat[i][j] = 0;
				}
				break;
			}
		}
	}
	
	if (sol.size() < N) {
		printf("0");
	}
	else {
		for (i = 0; i < N; ++i) {
			printf("%d ", sol[i]);
		}
	}
	ENTER;
	
	return 0;
}


