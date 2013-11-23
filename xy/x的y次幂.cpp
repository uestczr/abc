#include <iostream>
using namespace std;

int qiumi(int x,int y){
	if(y==1) 
		return x;
	else
		return x*qiumi(x,y-1);
}
int main(){
	int x=0,y=0,re=0;
	cout << "please input x=" << endl;
	cin >> x;
	cout << "please input y=" << endl;
	cin >> y;
	re = qiumi(x,y);
	cout << "x^y=" << re << endl;
	cin >> x;
	return 0;
}