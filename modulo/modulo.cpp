#include <iostream>
using namespace std;

int mod(int a, int n){
	if(a>0){
		int q = a/n;
		int r = a-(q*n);
		return r;
	}
	else if(a<0){
		int q = a/n - 1;
		int r = a - (q*n);
		return r;
	}
	else return 0;
}

int main() {
  cout << mod(-255, 11);
}
