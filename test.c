#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// �ֵ�������ӣ���ʾ�������һ������
// �ֵ��������ӣ�����ҿհ׵���������

// 1.�������̣���ά���鼴�ɣ�
#define ROW 3
#define COL 3
char g_board[ROW][COL];

// 2.��ʼ�����̳ɿո񣨳�ʼ����ά���飩
void Init() {
	// ����һ��ʼ��ʱ�������������
	srand((unsigned int)time(0));
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COL; ++col) {
			g_board[row][col] = ' ';
		}
	}
}

// 3.��ӡ������
void Print() {
	printf("\n");
	printf(" ___________\n");
	for (int row = 0; row < ROW; ++row) {
		printf("| %c | %c | %c |\n", g_board[row][0], g_board[row][1], g_board[row][2]);
		printf("|___|___|___|\n");
	}
}

// 4.�������(�� ��x�� ��ʾ)
void PlayerMove() {
	while (1) {
		int row, col;
		printf("\n��������ӣ�");
		scanf_s("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL) {
			printf("�����������������������������꣡\n");
			continue;
		}
		if (g_board[row][col] != ' ') {
			printf("��ǰλ���Ѿ������ˣ�����������������꣡\n");
			continue;
		}
		g_board[row][col] = 'x';
		break;
	}
}

// 5.��������(�� ��o�� ��ʾ)
void ComputerMove() {
	printf("\n�������������У�\n");
	while (1) {
		int row = rand() % ROW;
		int col = rand() % COL;
		if (g_board[row][col] != ' ') {
			continue;
		}
		g_board[row][col] = 'o';
		printf("\n�������ӵ�����Ϊ��%d %d", row, col);
		break;
	}
}

// �ж���Ϸ�Ƿ����
char CheckWinner() {
	// winner=x, ���ʤ
	// winner=0, ����ʤ
	// winner=' ', ʤ��δ��
	// winner=q, ����

	// �ȼ����
	for (int row = 0; row < ROW; ++row) {
		if (g_board[row][0] == g_board[row][1]
			&& g_board[row][0] == g_board[row][2]
			&& g_board[row][0] != ' ') {
			return g_board[row][0];
		}
	}
	// �ټ����
	for (int col = 0; col < COL; ++col) {
		if (g_board[0][col] == g_board[1][col]
			&& g_board[0][col] == g_board[2][col]
			&& g_board[0][col] != ' ') {
			return g_board[0][col];
		}
	}
	// ��������Խ���
	if (g_board[0][0] == g_board[1][1]
		&& g_board[0][0] == g_board[2][2]
		&& g_board[0][0] != ' ') {
		return g_board[0][0];
	}
	if (g_board[2][0] == g_board[1][1]
		&& g_board[2][0] == g_board[0][2]
		&& g_board[2][0] != ' ') {
		return g_board[2][0];
	}
	// ��� �����塱 �����
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COL; ++col) {
			if (g_board[row][col] == ' ') {
				return ' ';
			}
		}
	}
}

int main() {
	Init();
	char winner;
	while (1) {
		Print();
		PlayerMove();
		Print();
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
		ComputerMove();
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
	}
	if (winner == 'x') {
		printf("��ϲ��ʤ���ˣ�\n");
	}
	else if (winner == 'o') {
		Print();
		printf("����ʤ����\n");
	}
	else
	{
		printf("���壡\n");
	}
	system("pause");
	return 0;
}