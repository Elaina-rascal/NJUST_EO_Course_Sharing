#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn
using namespace std;
bool book[1000];
class STR{
	public:
		char *p;
		STR(char *str){
			p=str;
		}
		void delsame(){
			for(int i=0;i<strlen(p);i++){
				if(book[*(p+i)]) continue;
				book[*(p+i)]=true;
				printf("%c",*(p+i));
			}
		}
		void show(){
			printf("֮ǰ���ַ���%s\n",p);
			printf("֮����ַ���");
			delsame();
		}
};
int main(){
	STR ans("test");
	ans.show();
	return 0;
}
