#include<cstdio>
using namespace std;
int main(){
	int a[100],Max,Maxpos=1; Max=a[1]=a[0]=55;
	for(int i=2;i<=16;i++){
		a[i]=(a[i-1]*15+97)%256,a[0]+=a[i];
		if(Max<a[i]) Max=a[i],Maxpos=i;
	}
	printf("a����Ԫ��Ϊ:\n");
	for(int i=1;i<=16;i++) printf("%d ",a[i]);
	printf("\nƽ��ֵ=%.1lf\n���ֵ=%d\n",a[0]/16.0,Max);
	printf("ɾ��%d�������Ԫ��:\n",Max);
	for(int i=1;i<=16;i++) if(i!=Maxpos) printf("%d ",a[i]);
    return 0;
}
