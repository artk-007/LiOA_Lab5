#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <queue>
#include <locale.h>
using namespace std;



int G[5][5], vis[5];
void rand_Zap(int* Matrix, int n) {
	srand(time(NULL));
	printf("G\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) {
				Matrix[i * n + j] = 0;
			}
			if (i < j) {
				Matrix[i * n + j] = rand() % 2;
				Matrix[j * n + i] = Matrix[i * n + j];
			}
		}
}
void print_G(int* Matrix, int n) {
	printf("  ");
	for (int i = 0; i < n; i++)
		printf("%3d", i + 1);
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		printf("%2d", i + 1);
		for (int j = 0; j < n; j++) {

			printf("%3d", Matrix[i * n + j]);
		}
		printf("\n");
	}
	printf("\n");


}
void BFS(int n)
{
	queue <int> Q;
	Q.push(n);
	vis[n] = 1;
	while (Q.empty()==false) {
		n = Q.front();
		printf("%d ", n + 1);
		Q.pop();
		for (int i = 0; i < 5; i++) {
			if ((G[n][i] == 1) && vis[i]==0) {
				Q.push(i);
				vis[i] = 1;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	DWORD Start = 0, End = 0;
	int i = 0, j = 0, r = 0, x=1;
	rand_Zap(&G[0][0], 5);
	print_G(&G[0][0], 5);
	printf("введите вершину для начала обхода\n");
	scanf("%d", &x);
	x--;
	BFS(x);
	getchar();
	return 0;
}