#include <graphics.h>//ͼ��ͷ�ļ�
#include <stdio.h>
#include <math.h>
#include <mmsystem.h>//��ý��ͷ�ļ�
#include<string>
#include<iostream>
#include<stdlib.h>
#pragma comment(lib,"winmm.lib")//�������ֵĿ��ļ�

using namespace std;

//#define	MaxVal 1000;
//������Ϊ���� 
//��ʱʧ��

class Chess 
{
public:
	void initGame();    //��ӡ���̲��ҳ�ʼ������
	void playChess();   //���������������������
	int judge(int a,int b);   //�ж��Ƿ���� ������������Ӯ
	void rule();       //��ӡ��֪�����
	void num();        //��ӡ��Ӯ����

};

//��¼�������
string name1, name2;

//��Ǻ������
int flag = 0;		

//����Ƿ�ƽ��
int flag2 = 0;

//0��ʾû�������״̬ ������ʾ���� ż����ʾ����
int board[20][20] = { 0 };	

//��̬�洢�������������
int stack[2] = { 0 };

//������Ӯ����
int n1 = 0, n2 = 0,n3=0;

Chess x1;
int main()
{
	//������Ϸ
	x1.rule();
	cout << "���������һ��������";
	cin >> name1;
	cout << "��������Ҷ���������";
	cin >> name2;
	system("cls");
	//��ӡ���̺ͳ�ʼ����Ϸ
	x1.initGame();	

	x1.playChess();

	//�رս���
	closegraph();

	x1.num();

	return 0;
}
void Chess::rule()
{   
	cout << "���һʹ�ú���"<<endl
		 << "��Ҷ�ʹ�ð���"<<endl
		 << "��һ�ֺ������֣��������"<<endl
	     << "��һ���ٽ��н���" << endl
		 << "�벻Ҫ�ڱ�Ե������"<<endl
		 << "ף����һ���������飡"<<endl
		 << "OvO" << endl;
	cout << "Written by ����" << endl;
	cout << endl << endl;
	cout << "��<ENTER>����";
	int n = getchar();
	system("cls");
}
void Chess::initGame()
{
	string name1, name2;
	initgraph(600, 500);						//��ͼ����	
	//�ṩ��ͼ����,���ڿ��  �⺯��
	initgraph(600, 500);
	setbkcolor(LIGHTBLUE);//������ɫ
	cleardevice();//ˢ����ɫ
	mciSendString("open quiteMusic.mp3", 0, 0, 0);	//������
	mciSendString("play quiteMusic.mp3", 0, 0, 0);	//��������
	//��������
	setlinecolor(RED);						//����������ɫΪ��ɫ
	for (int i = 1; i < 20; i++)
	{
		line(0, i * 25, 500, i * 25);	//��������
		line(i * 25, 0, i * 25, 500);
	}
	setlinestyle(PS_SOLID, 2);			//��������Ϊʵ��,���Ϊ2
	line(500, 0, 500, 500);				//�߽���
	outtextxy(512, 60, "���1:����");
	//outtextxy(512, 80, name1);
	outtextxy(512, 100, "���2:����");
	//outtextxy(512, 120, name2);
	outtextxy(512, 140, "�Ҽ����壡");
}

void push(int x, int y)
{
	stack[0] = x;
	stack[1] = y;
}

void Chess::playChess()
{
	int x = 0, y = 0;
	int a = 0, b = 0;
	MOUSEMSG m;		//���������Ϣ
	HWND hwnd;
		//���ھ����������ǰ
	hwnd = GetHWnd();
	while (1)		//ʵ�ֲ�������
	{
		m = GetMouseMsg();			//��ȡһ�������Ϣ

		//��������ֵ
		for (int i = 1; i < 20; i++)
		{
			for (int j = 1; j < 20; j++)
			{
				if (abs(m.x - i * 25) < 12 && abs(m.y - j * 25) < 12)
				{
					a = i;
					b = j;
					x = i * 25;
					y = j * 25;
				}
			}
		}

		if (m.uMsg == WM_LBUTTONDOWN)	//�жϵ�ǰ�����Ϣ�ǲ�������������
		{
			if (board[a][b] != 0)
			{
				MessageBox(hwnd, "�����Ѿ���������,������ѡ��.", "������", MB_OK);
				continue;
			}
			push(a, b);
			if (flag % 2 == 0)
			{
				setfillcolor(BLACK);
				solidcircle(x, y, 10);
				board[a][b] = 1;
			}
			else
			{
				setfillcolor(WHITE);
				solidcircle(x, y, 10);
				board[a][b] = 2;
			}
			flag++;
		}
		else if (m.uMsg == WM_RBUTTONDOWN)//����ǲ����Ҽ����� �������
		{
			board[stack[0]][stack[1]] = 0;
			flag--;
			x1.initGame();
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 20; j++) {
					if (board[i][j] == 1) {
						setfillcolor(BLACK);
						solidcircle(i * 25, j * 25, 10);
					}
					else if (board[i][j] == 2) {
						setfillcolor(WHITE);
						solidcircle(i * 25, j * 25, 10);
					}
				}
			}
		}
		//�˴������ж�˭��˭Ӯ
		if (x1.judge(a, b))
		{
			if (1 == flag % 2)
			{
				n1++;
				if (MessageBox(hwnd, "���1ʤ�����Ƿ����¿�ʼ��Ϸ", "��Ϸ����", MB_OKCANCEL) == IDOK)
				{
					x1.initGame();
					memset(board, 0, sizeof(board));
					continue;
				}
				return;	
			}
			else if(0 == flag % 2)
			{
				n2++;
				if (MessageBox(hwnd, "���2ʤ�����Ƿ����¿�ʼ��Ϸ", "��Ϸ����", MB_OKCANCEL) == IDOK)
				{
					x1.initGame();
					memset(board, 0, sizeof(board));
					continue;
				}
				return;	
			}
			else if (flag2 == -1)
			{
				n3++;
				if (MessageBox(hwnd, "ƽ�֣��Ƿ����¿�ʼ��Ϸ", "��Ϸ����", MB_OKCANCEL) == IDOK)
				{
					x1.initGame();
					memset(board, 0, sizeof(board));
					continue;
				}
				return;
			}
		}
	}
}

//�ж��Ƿ���� a��bΪ�����ֵ
int Chess::judge(int a, int b)
{
	int i, j;
	int t = 2 - flag % 2;
	for (i = a - 4, j = b; i <= a; i++)
	{
		if (i >= 1 && i < 16 && t == board[i][j] && t == board[i + 1][j] && t == board[i + 2][j]
			&& t == board[i + 3][j] && t == board[i + 4][j])
			return 1;
	}
	for (i = a, j = b - 4; j <= b; j++)
	{
		if (j >= 1 && j < 16 && t == board[i][j] && t == board[i][j + 1]
			&& t == board[i][j + 2] && t == board[i][j + 3] && t == board[i][j + 4])
			return 1;
	}
	for (i = a - 4, j = b - 4; i <= a, j <= b; i++, j++)
	{
		if (i >= 1 && i < 16 && j >= 1 && j < 16 && t == board[i][j] && t == board[i + 1][j + 1] &&
			t == board[i + 2][j + 2] && t == board[i + 3][j + 3] && t == board[i + 4][j + 4])
			return 1;
	}
	for (i = a - 4, j = b + 4; i <= a, j >= b; i++, j--)
	{
		if (i >= 1 && i < 16 && j >= 1 && j < 16 && t == board[i][j] && t == board[i + 1][j - 1] &&
			t == board[i + 2][j - 2] && t == board[i + 3][j - 3] && t == board[i + 4][j - 4])
			return 1;
	}
	for (int x = 0; x < 20; x++)
	{
		for(int y = 0; y < 20; y++)
		{
			if (board[x][y] == 0) flag2 = -1;
		}
	}
	return 0;

}
void Chess::num()
{
	cout << name1 << "ʹ�ú���Ӯ��" << n1 << "��"<<endl;
	cout << name2 << "ʹ�ð���Ӯ��" << n2 << "��"<<endl;
	cout<<name1<<"��" << name2<<"ƽ����"<<n3<<"��" <<endl;
	cout << endl << endl;
	if (n1 > n2) cout << name1 << "��ʤһ�"<<endl;
	if (n1 < n2) cout << name2 << "��ʤһ�"<<endl;
	if (n1 == n2) cout << name1 << "��" <<name2<<"���˸�ƽ��" << endl;

}