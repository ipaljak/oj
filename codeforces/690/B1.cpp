#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " = ", << x << endl
#define REP(i, n) for(int i=0; i<n; i++)
#define X first
#define Y second


typedef pair<int, int> pii;
typedef long long ll;

const int oo = 0x3f3f3f3f;

const int MAXN = 55;

int n;
char c[MAXN][MAXN];

bool check(pii a, pii b){
	int test[MAXN][MAXN];

	memset(test, 0, sizeof test);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i >= a.X && i <= b.X && j >= a.Y && j <= b.Y){
				test[i][j] = 4;
			}
			
			if(( i+1 == a.X || i-1 == b.X) && (j >= a.Y && j <= b.Y) ||
				 ( j+1 == a.Y || j-1 == b.Y) && (i >= a.X && i <= b.X)){
				test[i][j] = 2;
			}
			

			if((i+1 == a.X || i-1 == b.X)){
				if((j+1 == a.Y || j-1 == b.Y)){
					test[i][j] = 1;
				}
			}
		}
	}


	for(int i=0; i<n; i++)
		for(int t=0; t<n; t++)
			if(c[i][t] != test[i][t])
				return false;

	return true;
}

int main(){
	
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%s", c[i]);
		for(int j=0; j<n; j++)
			c[i][j] -= '0';
	}

	pii first = {-1, -1}, last = {-1, -1};
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(c[i][j] == 4){
				last = {i, j};
				if(first.X == -1)
					first = {i, j};
			}
		}
	}


	if(check(first, last))
		printf("Yes\n");
	else
		printf("No\n");


	return 0;
}
