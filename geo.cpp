#include<iostream> //for clang
#include<algorithm>
#include<complex>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#define reps(i,j,k) for(int i = (j);i < (k);i++)
#define rep(i,j) reps(i,0,j)
#define re real
#define im imag
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef complex<double> pt;
typedef vector<pt> pg;

namespace std{
	//re -> imで大小の定義
	bool operator < (pt a, pt b){
		return a.re() != b.re() ? a.re() < b.re() : a.im() < b.im();
	}
}

const double eps = 1e-8;
const double inf = 1e12;

pt next_pt(){
	double a,b;
	cin >> a >> b;
	pt p(a,b);
	return p;
}

struct line : pg{
	line(){};
	line(pt p,pt q){pb(p);pb(q);}
};

line next_line(){
	line l;
	l[0] = next_pt();
	l[1] = next_pt();
	return l;
}

struct cr{
	pt p;
	double r;
	cr(){};
	cr(pt a, double s){p = a;r = s;}
};

pt unit(pt a){
	return a / abs(a);
}

pair<pt, pt> normal_vector(pt a){
	pt n1 = a * pt(0,1);
	pt n2 = a * pt(0,-1);
	return mp(n1,n2);
}

double crs(pt p, pt q){
	return im(conj(p)*q);
}

double dot(pt p,pt q){
	return re(conj(p)*q);
}

int ccw(pt a,pt b,pt c){
	b -= a;c -= a;
	if(crs(b,c)>0)return 1; //ccw
	if(crs(b,c)<0)return -1; //cw
	if(dot(b,c)<0)return 2; //c - a - b
	if(norm(b)<norm(c))return -2; // a - b - c
	return 0; //a - c - b
}

pt normalize(pt p,double l){
	return l * p / abs(p);
}

double triangle_area(pt a, pt b, pt c){
	return abs(crs(b-a, c-a)/2);
}

double vertex_area(pg ps){
	double ret = 0;
	rep(i,ps.size()){
		ret += crs(ps[i],ps[(i+1)%ps.size()]);
	}
	return ret / 2;
}

bool intersectll(line l, line m){
	return abs(crs(l[1]-l[0], m[1]-m[0])) > eps //平行でない
		|| abs(crs(l[1]-l[0], m[0]-l[0])) < eps; //同一直線
}

bool intersectls(line l, line s){
	return crs(l[1]-l[0], s[0]-l[0])			 //s[0]がlの片側
	     * crs(l[1]-l[0], s[1]-l[0]) < eps; //s[1]がその逆側
}

bool intersectlp(line l, pt p){
	return abs(crs(l[1]-p, l[0]-p)) < eps;
}

bool intersectss(line s, line t){
	return ccw(s[0],s[1],t[0]) * ccw(s[0],s[1],t[1]) <= 0
	    && ccw(t[0],t[1],s[0]) * ccw(t[0],t[1],s[1]) <= 0;
}

bool intersectsp(line s, pt p){
	return abs(s[0]-p) + abs(s[1]-p) - abs(s[1]-s[0]) < eps; //三角不等式
}

pt projection(line l, pt p){
	double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
	return l[0] + t * (l[0]-l[1]);
}

pt reflection(line l, pt p){
	return p + (projection(l, p) - p) + (projection(l, p) - p);
}

double distancelp(line l, pt p){
	return abs(p - projection(l, p));
}

double distancels(line l, line s){
	if(intersectls(l, s))return 0;
	return min(distancelp(l, s[0]), distancelp(l, s[1]));
}

double distancesp(line s, pt p){
	pt r = projection(s, p);
	if(intersectsp(s, r))return abs(r-p);
	return min(abs(s[0]-p), abs(s[1]-p));
}

double distancess(line s, line t){
	if(intersectss(s, t))return 0;
	return min(min(distancesp(s, t[0]), distancesp(s, t[1])),
				     min(distancesp(t, s[0]), distancesp(t, s[1])));
}

bool intersectcs(clr c, line l){
	return (distancelp(l,c.p) < c.r + eps &&
				 (c.r < abs(c.p - l[0]) + eps || c.r < abs(c.p - l[1]) + eps));
}

bool crosspointll(line l, line m, pt *p){ //存在すればtrue
	double a = crs(l[1] - l[0], m[1] - m[0]);
	double b = crs(l[1] - l[0], l[1] - m[0]);
	if(abs(a) < eps && abs(b) < eps){
		*p = m[0];
		return true;
	}
	if(abs(a) < eps)return false;
	*p = m[0] + b/a * (m[1] - m[0]);
	return true;
}

pg convex_hull(pg ps){
	int n = ps.size(), k = 0;
	sort(ps.begin(), ps.end());
	pg ch(2*n);
	for(int i = 0;i < n;ch[k++] = ps[i++]) //lower-hull
		while(k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
	for(int i = n-2, t = k+1;i>= 0;ch[k++] = ps[i--])
		while(k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
	ch.resize(k-1);
	return ch;
}

int contains(pg ps,pt p){
	bool in = false;
	rep(i,ps.size()){
		pt a = ps[i] - p, b = ps[(i+1)%ps.size()] - p;
		if(a.im() > b.im())swap(a,b);
		if(a.im() <= 0 && 0 < b.im())
			if(crs(a,b) < 0)in = !in;
		if(crs(a,b) == 0 && dot(a,b) <= 0)return 1;//on

	}
	return in ? 0 : 2;//in : out
}

int main(){

}
