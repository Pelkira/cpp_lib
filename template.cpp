// to compile by gcc
//#include<bits/stdc++.h>

// to compile by clang
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define reps(i,j,k) for(int i=(j);i<(k);++i)
#define rep(i,j) reps(i,0,j)
#define fs first
#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
ostream& operator<<(ostream &out, const vector<T> &v){
	out << "{";
	rep(i,v.size()) out << v[i] << ", ";
	return out << "}" << endl;
}
template<class S, class T>
ostream& operator<<(ostream &out, const pair<S, T> &p){
	return out << "(" << p.fs << ", " << p.sc << ")" << endl;
}

int main(){
	int n;
	return 0;
}
