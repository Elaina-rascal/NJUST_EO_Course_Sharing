// ��Ŀ���� :  ���������� 
// ָ����ʦ :  ���»� 
// ����     :  ������ 
// ѧ��     :  9211040G0637 
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<windows.h>
#define maxn 10000
using namespace std;
int opt,l,r,p,k,root;
char type;
struct node{
	int key,l,r,val,size,sum;
}tree[maxn];
class fhqtree
{
public:
	int add(int x)
	{
		tree[++k].key=rand();
		tree[k].size=1;
		tree[k].val=x;
		tree[k].sum=tree[k].val;
		return k;
	}
	void update(int id)
	{
		tree[id].size=tree[tree[id].l].size+tree[tree[id].r].size+1;
		tree[id].sum=tree[tree[id].l].sum+tree[tree[id].r].sum+tree[id].val;
	}
	void split(int u,int x,int &l,int &r)
	{
		if(!u)
		{
			l=r=0;
			return ;
		}
		if(x>=tree[u].val)
		{
			l=u;
			split(tree[u].r,x,tree[u].r,r);
		}
		else
		{
			r=u;
			split(tree[u].l,x,l,tree[u].l);
		}
		update(u);
	}
	int merge(int l,int r)
	{
		if(!l||!r) return l+r;
		if(tree[l].key<=tree[r].key)
		{
			tree[l].r=merge(tree[l].r,r);
			update(l);
			return l;
		}
		else
		{
			tree[r].l=merge(l,tree[r].l);
			update(r);
			return r;
		}
	}
	int kth(int u,int x)
	{
		if(tree[tree[u].l].size+1==x) return u;
		if(tree[tree[u].l].size>=x) return kth(tree[u].l,x);
		return kth(tree[u].r,x-tree[tree[u].l].size-1);
	}
	int find(int u,int x)
	{
		if(tree[u].val==x) return u;
		if(!tree[u].l && tree[u].val>x) return 0;
		if(!tree[u].r && tree[u].val<x) return 0;
		if(tree[u].val>x) return find(tree[u].l,x);
		if(tree[u].val<x) return find(tree[u].r,x);
	}
	void dfs(int u)
	{
		printf("%d ",tree[u].val);
		if(tree[u].l) dfs(tree[u].l);
		if(tree[u].r) dfs(tree[u].r);
	}
	void print(int u,int deep)
	{
		if(tree[u].r) print(tree[u].r,deep+1);
		for(int i=1;i<deep;i++) printf("      ");
		printf("| %d |\n",tree[u].val);
		if(tree[u].l) print(tree[u].l,deep+1);
	}
	void sort_min_to_max(int u){
		if(tree[u].l) sort_min_to_max(tree[u].l);
		printf("%d ",tree[u].val);
		if(tree[u].r) sort_min_to_max(tree[u].r);
	}
	void sort_max_to_min(int u){
		if(tree[u].r) sort_max_to_min(tree[u].r);
		printf("%d ",tree[u].val);
		if(tree[u].l) sort_max_to_min(tree[u].l);
	}
}fhq;
class UI
{
public:
	void menu()
	{
		printf("-----------------------------------------\n");
		printf("|��Ŀ : ����������                      |\n");
		printf("|                                       |\n");
		printf("|ָ����ʦ : ���»�                      |\n");
		printf("|��ʹ�����ݽṹ : fqhƽ����             |\n");
		printf("|���� : ������    ѧ�� : 9211040G0637   |\n");
		printf("-----------------------------------------\n");
	}
	void help()
	{
		printf("\n                  ����:\n");
		printf("1  : ��������               9  : ���ƽ��ֵ\n");
		printf("2  : ɾ������               10 : ������˳�����������\n");
		printf("3  : ��������               11 : ��С�����������\n");
		printf("4  : �ҳ�ǰ������           12 : �Ӵ�С�������\n");
		printf("5  : �ҳ��������           13 : ĳһ���ڵ㼰��������ƽ��ֵ\n");
		printf("6  : ����Сֵ               14 : ĳһ���ڵ㼰���������ܺ�\n");
		printf("7  : �����ֵ               15 : �������ݲ��˳�\n");
		printf("8  : ���������             16 : ��������\n");
		printf("------------------------------------------------------\n");
	}
	void cls(){
		system("cls");
		menu();
		help();
	}
	void set(){
		printf("----��ѡ��ģʽ-----\n");
		printf("a : ����ģʽ\n");
		printf("b : ��ʾģʽ\n");
		scanf("%c",&type);
		cls(); 
		while(type!='a' && type!='b'){
			printf("\n������ѡ��\n");
			scanf("%c",&type); 
		}
	}
}UI;
signed main()
{
	UI.cls();
	srand(unsigned(time(0)));
	UI.set();
	if(type=='a'){
		while(scanf("%d",&opt)!=EOF)
		{
			if(opt==0){
				UI.cls();
				UI.help();
			}
			else if(opt==1)
			{ //�������� 
				int x;
				scanf("%d",&x);
				fhq.split(root,x,l,r);
				root=fhq.merge(fhq.merge(l,fhq.add(x)),r);
				UI.cls(); 
				printf("����ָ���� : ���� %d\n",x);
			}
			else if(opt==2)
			{ //ɾ������ 
				int x;
				scanf("%d",&x);
				if(!fhq.find(root,x))
				{
					UI.cls(); 
					printf("����ָ���� : ɾ��ʧ�� , �������в����� %d\n",x);
					continue;
				}
				fhq.split(root,x,l,r);
				fhq.split(l,x-1,l,p);
				p=fhq.merge(tree[p].l,tree[p].r);
				root=fhq.merge(fhq.merge(l,p),r);
				UI.cls();
				printf("����ָ���� : ɾ�� %d �ɹ�\n",x);
			}
			else if(opt==3)
			{
				int x;
				scanf("%d",&x);
				UI.cls();
				if(fhq.find(root,x)) printf("����ָ���� : %d �����ڶ�������\n",x);
				else printf("����ָ���� : %d �������ڶ�������\n",x);
			}
			else if(opt==4)
			{ //ǰ�� 
				int x;
				scanf("%d",&x);
				if(x<=tree[fhq.kth(root,1)].val)
				{
					UI.cls();
					printf("����ָ���� : %d û��ǰ������",x);
					printf(" , ��ǰ����Сֵ��: %d\n",tree[fhq.kth(root,1)].val);
					continue;
				}
				fhq.split(root,x-1,l,r);
				UI.cls();
				printf("����ָ���� : %d ��ǰ�������� %d\n",x,tree[fhq.kth(l,tree[l].size)].val);
				root=fhq.merge(l,r);
			}
			else if(opt==5)
			{ //��� 
				int x;
				scanf("%d",&x);
				if(x>=tree[fhq.kth(root,tree[root].size)].val)
				{
					UI.cls();
					printf("����ָ���� : %d û�к������",x);
					printf(" , ��ǰ����ֵ��: %d\n",tree[fhq.kth(root,tree[root].size)].val);
					continue;
				}
				fhq.split(root,x,l,r);
				UI.cls();
				printf("����ָ���� : %d �ĺ�������� %d\n",x,tree[fhq.kth(r,1)].val);
				root=fhq.merge(l,r);
			}
			else if(opt==6)
			{ //��Сֵ 
				UI.cls();
				printf("����ָ���� : ��������СֵΪ %d\n",tree[fhq.kth(root,1)].val);
			}
			else if(opt==7)
			{//���ֵ 
				UI.cls();
				printf("����ָ���� : ���������ֵΪ %d\n",tree[fhq.kth(root,tree[root].size)].val);
			}
			else if(opt==8)
			{//��������� 
				UI.cls();
				printf("����ָ���� : ����������״Ϊ\n");
				fhq.print(root,1);
				printf("\n");
			}
			else if(opt==9)
			{//�����������ƽ��ֵ 
				UI.cls();
				printf("����ָ���� : ������ƽ��ֵΪ %.3lf\n",1.0*tree[root].sum/tree[root].size);
			}
			else if(opt==10)
			{//���ձ���˳����������� 
				UI.cls();
				printf("����ָ���� : ����˳����\n"); 
				fhq.dfs(root);
				printf("\n");
			}
			else if(opt==11){//��С����������� 
				UI.cls();
				printf("����ָ���� : ��С�����������Ϊ\n"); 
				fhq.sort_min_to_max(root);
				printf("\n");
			}
			else if(opt==12){//�Ӵ�С������� 
				UI.cls();
				printf("����ָ���� : �Ӵ�С�������Ϊ\n"); 
				fhq.sort_max_to_min(root);
				printf("\n");
			}
			else if(opt==13){
				int x;
				scanf("%d",&x);
				int treeid=fhq.find(root,x);
				UI.cls();
				if(treeid==0) printf("����ָ���� : �ڵ� %d ������\n",x);
				else printf("����ָ���� : �ڵ� %d ƽ��ֵΪ %.2lf\n",x,1.0*tree[treeid].sum/tree[treeid].size);
			}
			else if(opt==14){
				UI.cls();
				int x;
				scanf("%d",&x);
				int treeid=fhq.find(root,x);
				if(treeid==0) printf("����ָ���� : �ڵ� %d ������\n",x);
				else printf("����ָ���� : �ڵ� %d �ܺ�Ϊ %d\n",x,tree[treeid].sum);
			}
			else if(opt==15){
				UI.cls();
				printf("����ָ���� : ���ݱ���ɹ� �����ļ���Ϊ\"data.out\"\n"); 
				freopen("data.out","w",stdout);
				printf("%d\n",k);
				for(int i=1;i<=k;i++){
					printf("%d %d %d %d %d %d\n",tree[i].key,tree[i].l,tree[i].r,tree[i].size,tree[i].sum,tree[i].val);
				}
				printf("%d\n",root);
				freopen("CON","w",stdout); 
				exit(0); 
			}
			else if(opt==16){
				UI.cls();
				printf("����ָ���� : ��������ɹ� \n"); 
				freopen("data.out","r",stdin);
				scanf("%d",&k);
				memset(tree,0,sizeof tree);
				for(int i=1;i<=k;i++){
					scanf("%d %d %d %d %d %d",&tree[i].key,&tree[i].l,&tree[i].r,&tree[i].size,&tree[i].sum,&tree[i].val);
				}
				scanf("%d",&root);
				freopen("CON","r",stdin);
			}
			else {
				UI.cls();
				printf("����ָ���� : input error\n");
			}
		}
	}
	
//-------------------------------------------------------------------------------------------------------------------------------	
	
	else if(type=='b'){
		while(scanf("%d",&opt)!=EOF)
		{
			if(opt==0){
				UI.cls();
				UI.help();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
			}
			else if(opt==1)
			{ //�������� 
				int x;
				scanf("%d",&x);
				fhq.split(root,x,l,r);
				root=fhq.merge(fhq.merge(l,fhq.add(x)),r);
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : ���� %d\n",x);
			}
			else if(opt==2)
			{ //ɾ������ 
				int x;
				scanf("%d",&x);
				if(!fhq.find(root,x))
				{
					UI.cls(); 
					printf("-------------------------\n");
					fhq.print(root,1);
					printf("-------------------------\n");
					printf("����ָ���� : ɾ��ʧ�� , �������в����� %d\n",x);
					continue;
				}
				fhq.split(root,x,l,r);
				fhq.split(l,x-1,l,p);
				p=fhq.merge(tree[p].l,tree[p].r);
				root=fhq.merge(fhq.merge(l,p),r);
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : ɾ�� %d �ɹ�\n",x);
			}
			else if(opt==3)
			{
				int x;
				scanf("%d",&x);
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				if(fhq.find(root,x)) printf("����ָ���� : %d �����ڶ�������\n",x);
				else printf("����ָ���� : %d �������ڶ�������\n",x);
			}
			else if(opt==4)
			{ //ǰ�� 
				int x;
				scanf("%d",&x);
				if(x<=tree[fhq.kth(root,1)].val)
				{
					UI.cls();
					printf("-------------------------\n");
					fhq.print(root,1);
					printf("-------------------------\n");
					printf("����ָ���� : %d û��ǰ������",x);
					printf(" , ��ǰ����Сֵ��: %d\n",tree[fhq.kth(root,1)].val);
					continue;
				}
				fhq.split(root,x-1,l,r);
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : %d ��ǰ�������� %d\n",x,tree[fhq.kth(l,tree[l].size)].val);
				root=fhq.merge(l,r);
			}
			else if(opt==5)
			{ //��� 
				int x;
				scanf("%d",&x);
				if(x>=tree[fhq.kth(root,tree[root].size)].val)
				{
					UI.cls();
					printf("-------------------------\n");
					fhq.print(root,1);
					printf("-------------------------\n");
					printf("����ָ���� : %d û�к������",x);
					printf(" , ��ǰ����ֵ��: %d\n",tree[fhq.kth(root,tree[root].size)].val);
					continue;
				}
				fhq.split(root,x,l,r);
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : %d �ĺ�������� %d\n",x,tree[fhq.kth(r,1)].val);
				root=fhq.merge(l,r);
			}
			else if(opt==6)
			{ //��Сֵ 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : ��������СֵΪ %d\n",tree[fhq.kth(root,1)].val);
			}
			else if(opt==7)
			{//���ֵ 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : ���������ֵΪ %d\n",tree[fhq.kth(root,tree[root].size)].val);
			}
			else if(opt==8)
			{//��������� 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : �������������״\n");
				printf("\n");
			}
			else if(opt==9)
			{//�����������ƽ��ֵ 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : ������ƽ��ֵΪ %.3lf\n",1.0*tree[root].sum/tree[root].size);
			}
			else if(opt==10)
			{//���ձ���˳����������� 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : ����˳����\n"); 
				fhq.dfs(root);
				printf("\n");
			}
			else if(opt==11){//��С����������� 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : ��С�����������Ϊ\n"); 
				fhq.sort_min_to_max(root);
				printf("\n");
			}
			else if(opt==12){//�Ӵ�С������� 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : �Ӵ�С�������Ϊ\n"); 
				fhq.sort_max_to_min(root);
				printf("\n");
			}
			else if(opt==13){
				int x;
				scanf("%d",&x);
				int treeid=fhq.find(root,x);
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				if(treeid==0) printf("����ָ���� : �ڵ� %d ������\n",x);
				else printf("����ָ���� : �ڵ� %d ƽ��ֵΪ %.2lf\n",x,1.0*tree[treeid].sum/tree[treeid].size); 
			}
			else if(opt==14){
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				int x;
				scanf("%d",&x);
				int treeid=fhq.find(root,x);
				if(treeid==0) printf("����ָ���� : �ڵ� %d ������\n",x);
				else printf("����ָ���� : �ڵ� %d �ܺ�Ϊ %d\n",x,tree[treeid].sum);
			}
			else if(opt==15){
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : ���ݱ���ɹ� �����ļ���Ϊ\"data.out\"\n"); 
				freopen("data.out","w",stdout);
				printf("%d\n",k);
				for(int i=1;i<=k;i++){
					printf("%d %d %d %d %d %d",tree[i].key,tree[i].l,tree[i].r,tree[i].size,tree[i].sum,tree[i].val);
				}
				printf("%d\n",root);
				freopen("CON","w",stdout); 
				exit(0); 
			}
			else if(opt==16){
				UI.cls();
				freopen("data.out","r",stdin);
				scanf("%d",&k);
				memset(tree,0,sizeof tree);
				for(int i=1;i<=k;i++){
					scanf("%d %d %d %d %d %d",&tree[i].key,&tree[i].l,&tree[i].r,&tree[i].size,&tree[i].sum,&tree[i].val);
				}
				scanf("%d",&root);
				freopen("CON","r",stdin);
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : ��������ɹ� \n"); 
			}
			else{
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("����ָ���� : input error\n");
			}
		}
	}
	return 0;
}
