#include <stdio.h>

char map[50][51];    //��ͼ����50*50 
int sign[50][50];     //��� 
int next[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
int n, m;    //ʵ�ʵ�ͼ���������� 
int endy, endx;     //�յ�λ�� 
int min = 99999999;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//����һ��յ����¼���Թ���·��
struct Node
{
	int y;
	int x;
};

struct Stack
{
	Node * pbase;
	int top;
};

void StackInit(Stack * pstack) {
	pstack->pbase = new Node[100];
	pstack->top = 0;
}

void StackPush(Stack * pstack, int y, int x) {
	Node node;
	node.y = y;
	node.x = x;
	pstack->pbase[pstack->top] = node;
	++pstack->top;
}

void StackCopy(Stack * pstack1, Stack * pstack2) {
	pstack2->top = pstack1->top;
	for (int i = 0; i<pstack2->top; i++)
	{
		pstack2->pbase[i] = pstack1->pbase[i];
	}
}

void StackPop(Stack * pstack) {
	--pstack->top;
}

Stack stack;
Stack minstack;

//����������� 
void dfs(int y, int x, int step) {
	int ty, tx;
	if (y == endy&&x == endx)
	{
		if (step<min)
		{
			StackCopy(&stack, &minstack);
			min = step;
		}
		return;
	}

	for (int i = 0; i<4; i++)
	{
		ty = y + next[i][0];
		tx = x + next[i][1];
		if (ty >= 0 && ty<n&&tx >= 0 && tx<m&&map[ty][tx] != '#'&&sign[ty][tx] == 0)
		{
			StackPush(&stack, ty, tx);
			sign[ty][tx] = 1;
			dfs(ty, tx, step + 1);
			StackPop(&stack);
			sign[ty][tx] = 0;
		}
	}
	return;
}

int main(int argc, char** argv) {
	printf("����������������:");
	scanf("%d %d", &n, &m);
	printf("�봴����ͼ:\n");
	for (int i = 0; i<n; i++)
	{
		scanf("%s", &map[i]);
	}
	printf("�����ĵ�ͼ����:\n");
	for (int i = 0; i<n; i++)
	{
		printf("%s\n", map[i]);
	}
	printf("���������y x:");
	int starty, startx;
	scanf("%d %d", &starty, &startx);
	printf("�������յ�y x:");
	scanf("%d %d", &endy, &endx);
	sign[starty][startx] = 1;

	StackInit(&stack);
	StackInit(&minstack);

	dfs(starty, startx, 0);
	printf("���·��Ϊ%d\n", min);

	printf("���·��Ϊ:\n");
	map[starty][startx] = 's';    //���ַ�'s'��ʾ��� 
	for (int i = 0; i<minstack.top; i++)
	{
		map[minstack.pbase[i].y][minstack.pbase[i].x] = '>';
	}
	for (int i = 0; i<n; i++)
	{
		printf("%s\n", map[i]);
	}
	return 0;
}