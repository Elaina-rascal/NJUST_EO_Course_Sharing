#include<cstdio>
#include<algorithm>
#include<cmath>
#define maxn
using namespace std;

signed main(){
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	double s=a+b+c;
	printf("�ܳ���:%lf\n",s);
	s/=2;
	printf("�����:%lf\n",sqrt(s*(s-a)*(s-b)*(s-c)));
	return 0;
}

