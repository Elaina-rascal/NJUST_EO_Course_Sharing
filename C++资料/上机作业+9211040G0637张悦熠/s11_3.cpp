#include<iostream>
#include<cstring>
using namespace std;
int ans;
char s[2000];
bool judge(char x){
	return (x>='a'&&x<='z') || (x>='A' && x<='Z');
}
int main(){//ֻҪ���Ǵ�Сд��ĸ��������� 
	cin.getline(s,1000);
	int len=strlen(s),now=0;
	while(now<len){
		if(!judge(s[now])) {now++;continue;}
		ans++;
		while(judge(s[now])) now++;
	}
	printf("%d\n",ans);
	return 0;
}
