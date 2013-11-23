#include <iostream>
using namespace std;

int main(){
	int m=1,n=1,up=1,down=1;
	cout << "please input m=" << endl;
	cin >> m;
	cout << "please input n=" << endl;
	cin >> n;
	for(int i=1;i<=n;i++){
		down *= i;
		up *= m-n+i;
	}

	cout << "cmn=" << up/down << endl;
	return 0;
}
