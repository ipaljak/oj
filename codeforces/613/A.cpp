#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>

#define MAXN 100010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

struct Point {
    llint x, y;

    Point () {}
    Point (llint _x, llint _y) {
        x = _x;
        y = _y;
    }

    friend bool operator < (const Point &A, const Point &B) {
        if (A.x == B.x) return A.y < B.y;
        return A.x < B.x;
    }

    friend bool operator == (const Point &A, const Point &B) {
        return A.x == B.x && A.y == B.y;
    }

};

int N;

const double pi = 3.14159265359;

Point O, A, B;
Point pts[MAXN];

llint dist(const Point &A, const Point &B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

llint dot(const Point &A, const Point &B) {
    return A.x * B.x + A.y * B.y;
}

llint cross(const Point &A, const Point &B) {
    return A.x * B.y - A.y * B.x;
}

double point_to_line(const Point &A, const Point &B, const Point &P) {

    Point AB = Point(B.x - A.x, B.y - A.y);
    Point BA = Point(A.x - B.x, A.y - B.y);

    Point AP = Point(P.x - A.x, P.y - A.y);
    Point BP = Point(P.x - B.x, P.y - B.y);

    if (dot(AB, BP) > 0) return sqrt(dist(B, P));
    if (dot(BA, AP) > 0) return sqrt(dist(A, P));

    return abs((double) cross(AB, AP) / sqrt(dist(A, B)));


}

int main(void) {

    llint x, y; 
    scanf("%d%lld%lld", &N, &x, &y);
    
    O = Point(x, y);
    
    scanf("%lld%lld", &x, &y);
    pts[0] = B = Point(x, y);

    for (int i = 0; i < N - 1; ++i) {
        scanf("%lld%lld", &x, &y);
        pts[i + 1] = Point(x, y);
        if (dist(O, pts[i + 1]) > dist(O, B)) B = pts[i + 1];
    }

    double dist_a = point_to_line(pts[N - 1], pts[0], O);
    for (int i = 1; i < N; ++i) {
        dist_a = min(dist_a, point_to_line(pts[i - 1], pts[i], O)); 
    }

    printf("%.12lf\n", (dist(O, B) - dist_a * dist_a) * pi);

    return 0;

}


