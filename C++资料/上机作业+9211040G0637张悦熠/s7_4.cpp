#include<iostream>
using namespace std;
int n,s;
int f(int n){
	int s=1;
	while(n){
		s=s*n%10;
		n/=10;
	}
	return s;
}
signed main(){
	cout<<"������һ����(����0����)��";
	cin>>n;
	while(n){
		s=f(n);
		cout<<s<<endl;
		cout<<"������һ����(����0����)��";
		cin>>n;
	}
	return 0;
}
