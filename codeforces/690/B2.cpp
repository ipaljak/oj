#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " = ", << x << endl
#define REP(i, n) for(int i=0; i<n; i++)
#define X first
#define Y second


typedef pair<int, int> pii;
typedef long long ll;

const int oo = 0x3f3f3f3f;

const int MAXN = 510;

int n;
char c[MAXN][MAXN];
vector<pii> v;
pii ish;

int ccw(pii a, pii b, pii c){
	return a.X * (b.Y - c.Y) + b.X * (c.Y - a.Y) + c.X * (a.Y - b.Y);
}

int dist(pii a, pii b){
	return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

bool cmp(pii a, pii b){
	return ccw(v[0], a, b) < 0;
}

int main(){

	scanf("%d", &n);

	while(n){
		v.clear();
		for(int i=0; i<n; i++){
			scanf("%s", c[i]);
			for(int t=0; t<n; t++){
				c[i][t] -= '0';
			}
		}

		for(int i=1; i<n; i++){
			for(int t=1; t<n; t++){
				if(c[i-1][t-1] && c[i][t-1] && c[i-1][t] && c[i][t]){
					v.push_back({i, t});
					c[i][t]--;
					c[i-1][t]--;
					c[i][t-1]--;
					c[i-1][t-1]--;
				}
			}
		}
		for(int i=0; i<n; i++){
			if(c[0][i]){
				v.push_back({0, i});
				c[0][i]--;
				if(i+1<n) c[0][i+1]--;
			}
			if(c[n-1][i]){
				v.push_back({n-1, i});
				c[n-1][i]--;
				if(i+1<n) c[n-1][i+1]--;
			}
			if(c[i][0]){
				v.push_back({i, 0});
				c[i][0]--;
				if(i+1<n) c[i+1][0]--;
			}
			if(c[i][n-1]){
				v.push_back({i, n-1});
				c[i][n-1]--;
				if(i+1<n) c[i+1][n-1]--;
			}

		}

		
		vector<pii> cp;
		for(auto x : v)
			cp.push_back(x);

		v.clear();
		for(auto x : cp)
			v.push_back({x.Y, n-x.X});


		
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		pii h[v.size()*2];

		int k = 0;

		for(pii x : v){
			while(k >= 2 &&		ccw(h[k-2], h[k-1], x) >= 0) k--;
			h[k++] = x;
		}
		int t = k+1;
		for(int i=v.size() - 2; i >= 0; i--){
			while(k >= t && ccw(h[k-2], h[k-1], v[i]) >= 0) k--;
			h[k++] = v[i];
		}

		printf("%d\n", k-1);
		for(int i=0; i<k-1; i++)
			printf("%d %d\n", h[i].X, h[i].Y);


		scanf("%d", &n);
	}



	return 0;
}
