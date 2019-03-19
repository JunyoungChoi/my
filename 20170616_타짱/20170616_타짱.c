#include <stdio.h> 
#include <time.h>    // �ð��Լ�
#include<windows.h>   // cls�Լ�
#include<string.h>   // str�Լ�
#include<malloc.h>   // malloc
#include<stdlib.h>  // 
#include<conio.h>  // kbhit

FILE* stream;
clock_t start, end;

void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void Color(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

int CountNum(char data[]) {
	char a = 'A';
	while (1) {
		data[3] = a;
		stream = fopen(data, "r");
		if (stream == NULL)
			break;
		a++;
		fclose(stream);
	}
	return a - 'A';
}

/*int LoadNum(char data[]) {           // ����� num �� ��������
stream = fopen("datanum.txt", "r");
fscanf(stream, "%d", &num);
fclose(stream);
return num;
}

void SaveNum() {         // num�� �ֽ�ȭ

stream = fopen("datanum.txt", "wt");

fputc(num + 48, stream);
fclose(stream);
}*/

void NewData(char data[], char long_sen[], char Title[]) {          // ��� �����
	int a = 0;
	int b = 0;
	int key = 0;
	char *mid;
	char title[100];

	Title[5] = CountNum(data) + 'A';
	stream = fopen(Title, "w");
	gotoxy(47, 3);
	printf("������ �Է����ּ���");
	gotoxy(53, 6);
	fflush(stdin);
	scanf("%s", title);
	fflush(stdin);
	fprintf(stream, "%s", title);
	fclose(stream);
	gotoxy(0, 10);
	printf("�����Է�\n");
	mid = long_sen;
	while (1) {
		scanf(" %[^\n]s", mid);
		fflush(stdin);

		long_sen[strlen(long_sen)] = '\n';
		mid = &long_sen[strlen(long_sen)];
		Sleep(1500);           //  1.5��
		if (_kbhit() == 0)   // 1.5�ʰ� �Է¾����� ����
			break;
	}
	long_sen[strlen(long_sen) - 1] = '\0';

	printf("\n\n�Ϸ�ƽ��ϴ�.\n\n�޴��� ���ư����� �ƹ�Ű�� ��������.\n");

	data[3] = CountNum(data) + 'A';

	stream = fopen(data, "w");    // ���ο� ���� ����		
	fputs(long_sen, stream);
	fclose(stream);


	key = 0;
	while (1) {
		if (kbhit()) {
			key = getch();
			if (key != 0)
				break;
		}
	}
}

float play(char long_sen[], int A, char data[]) {
	int a, b, c, cnt, result, Acc, count, d;
	float fast;
	char *Answer;
	char ch;
	char *temp, *realtemp;
	char nnnn;
	int *wrong;  // Ʋ���κ�
	int e = 0;
	b = 0;
	c = 1;
	result = 0;
	count = 0;
	cnt = 0;
	Answer = (char*)malloc(sizeof(char)*(strlen(long_sen) + 1));
	wrong = (int*)malloc(sizeof(int)*(strlen(long_sen) + 1));
	realtemp = (char*)malloc(sizeof(char)*(strlen(long_sen) + 1));

	memset(Answer, 0, (strlen(long_sen) + 1));
	memset(wrong, 100, (strlen(long_sen) + 1));
	memset(realtemp, 0, (strlen(long_sen) + 1));

	gotoxy(0, 3);
	temp = &Answer[strlen(Answer)];

	start = clock();// ���۽ð�
	a = 0;
	c = 0;
	while (cnt < A) {          // �޾ƾ��� ����

		printf(" ");

		gets(temp);

		//Answer[strlen(Answer)] = ' ';
		gotoxy(0, 3 + ++c * 7);
		Answer[strlen(Answer)] = ' ';
		temp = &Answer[strlen(Answer)];
		cnt++;
	}
	Answer[strlen(Answer)] = '\0';


	end = clock();   // ����ð�
	fast = (float)(end - start) / CLOCKS_PER_SEC;    // ��ġ�µ� �ɸ��½ð�
	e = 0;
	for (a = 0; long_sen[a] != '\0'; a++) {
		if (Answer[a] == long_sen[a])
			result++;
		else
			wrong[count++] = a;
	}
	Acc = result * 100 / strlen(long_sen);  // ��Ȯ��
	free(Answer);

	a = 0;
	stream = fopen(data, "r");
	count = 0;
	c = 0;
	gotoxy(0, 0);
	printf(" ");
	while (long_sen[e++] != '\0') {                // Ʋ���� �����κ����� ��Ÿ����
		fscanf(stream, "%c", &realtemp[a]);
		fflush(stdin);

		/*		if (a == b + 119) {
		c += 4;
		b += 119;
		gotoxy(0, c);
		}*/
		if (realtemp[a] == '\n') {
			b = a;
			realtemp[a] = ' ';
			c += 7;
			gotoxy(0, c);
		}
		if (a == wrong[count]) {
			Color(12);
			printf("%c", realtemp[a]);
			count++;
		}
		else {
			Color(11);
			printf("%c", realtemp[a]);
		}
		a++;
	}


	printf("\n");
	gotoxy(47, c + 4);
	Color(13);
	printf("��Ȯ�� : %d%%", Acc);
	gotoxy(47, c + 5);
	printf("��  �� : %.2fŸ\n", result / fast);
	gotoxy(47, c + 6);
	printf("��  �� : %.0fŸ", result / fast * 60);
	Color(15);

	fclose(stream);
	free(realtemp);
	free(wrong);
	gotoxy(40, c + 8);
	printf("�ƹ�Ű�� ������ �޴��� ���ư��ϴ�.");
	{int key = 0;
	while (1) {
		if (kbhit()) {
			key = getch();
			if (key != 0)
				break;
		}
	}
	}
	return fast;
}

void LoadData(char data[], char long_sen[], char Title[]) {        // ��� �ҷ�����
	char ans[3];         // ���
	int a, b, c, Acc, d; //Acc�� ��Ȯ��
	float fast;   // ������
	char temp[100] = { '0', };
	b = c = d = 0;
	if (CountNum(data) == 0) {
		int key;
		gotoxy(43, 15);
		printf("���� ����� ���� �����ϴ�.");
		gotoxy(40, 16);
		printf("�ƹ�Ű�� ������ �޴��� ���ư��ϴ�.");
		key = 0;
		while (1) {
			if (kbhit()) {
				key = getch();
				if (key != 0)
					break;
			}
		}
		return 0;
	}
	do {                                    // ��ۼ���
		system("cls");
		gotoxy(43, 5);
		printf("���� %d���� �� ���� �ֽ��ϴ�.", CountNum(data));
		for (a = 0; a < CountNum(data); a++) {
			Title[5] = a + 'A';
			gotoxy(50, 7 + a);
			stream = fopen(Title, "r");
			fscanf(stream, "%s", temp);
			fflush(stdin);
			printf("%d. %s", a + 1, temp);
			fclose(stream);
		}
		gotoxy(48, 10 + a);
		printf("����� ������ : ");
		gets(ans);
		fflush(stdin);
		if (ans[0] > CountNum(data) + '0' || ans[0] <= '0') {
			gotoxy(47, 21);
			printf("�߸��Է��ϼ̽��ϴ�.");
			for (a = 0; a < 500000000; a++);  // ����
		}
		else {
			gotoxy(47, 21);
			printf("%d���� �����ϼ̽��ϴ�.", ans[0] - '0');
			for (a = 0; a < 500000000; a++);
		}
	} while (ans[0] > CountNum(data) + '0' || ans[0] <= '0');

	data[3] = ans[0] - '1' + 'A';
	system("cls");
	a = 0;
	stream = fopen(data, "r");

	Color(11);
	printf(" ");
	memset(long_sen, 0, (strlen(long_sen)));

	while (feof(stream) == 0) {
		fscanf(stream, "%c", &long_sen[a]);

		/*if (a == b + 119) {
		c += 4;
		b += 119;
		gotoxy(0, c+d++);
		}*/
		if (long_sen[a] == '\n') {
			b = a;
			long_sen[a] = ' ';
			c += 7;
			gotoxy(0, c);
		}
		printf("%c", long_sen[a]);
		a++;
	}

	fclose(stream);
	Color(15);
	fast = play(long_sen, c / 7 + 1, data);

}



void main(void)
{
	char data[] = "New0.txt";
	char Title[] = "Title0.txt";
	char long_sen[1200] = { '0', };
	int a, b, c, key, sel;
	int title[8][40] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,2,1,2,1,0,0,0,2,0,0,0,0,0,0,0,0,1,2,1,2,1,2,1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,
		2,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,2,0,1,0,2,0,1,0,0,0,0,2,1,0,0,0,0,
		2,1,2,1,2,0,0,0,1,2,0,0,0,0,0,0,0,1,0,0,0,0,2,0,0,0,1,0,0,0,2,0,0,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,2,1,2,1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0
	};
	//system("mode con:lines=36");
	key = 0;
	sel = 0;
	gotoxy(48, 20);
	printf("�ƹ�Ű�� ��������");
	while (1) {
		c = 0;
		for (a = 0; a < 8; a++) {
			gotoxy(37, 3 + c++);
			for (b = 0; b < 40; b++) {

				if (title[a][b] == 1) {
					printf("��");
					title[a][b] = 2;
				}
				else if (title[a][b] == 0) {
					printf(" ");
				}
				else if (title[a][b] == 2) {
					printf("��");
					title[a][b] = 1;
				}
			}

			printf("\n");
			Sleep(100);
		}
		if (kbhit()) {
			key = getch();
			if (key != 0)
				break;
		}
	}
	while (sel != 4) {
		system("cls");

		gotoxy(45, 10);
		printf("����������������������");
		gotoxy(45, 11);
		printf("��  1.��� �����   ��");
		gotoxy(45, 12);
		printf("����������������������");

		gotoxy(45, 14);
		printf("����������������������");
		gotoxy(45, 15);
		printf("��   2.Ÿ�� ����    ��");
		gotoxy(45, 16);
		printf("����������������������");

		gotoxy(45, 18);
		printf("����������������������");
		gotoxy(45, 19);
		printf("��    3. ����     ��");
		gotoxy(45, 20);
		printf("����������������������");

		gotoxy(45, 22);
		printf("����������������������");
		gotoxy(45, 23);
		printf("��     4. ����      ��");
		gotoxy(45, 24);
		printf("����������������������");

		gotoxy(45, 27);
		printf("�޴� ���� : ");
		scanf("%d", &sel);
		fflush(stdin);

		while (sel > 4 || sel <= 0) {
			gotoxy(59, 27);
			printf(" ");
			gotoxy(45, 30);
			printf("�߸����̽��ϴ�. �ٽ� ����ּ���");
			gotoxy(59, 27);
			scanf("%d", &sel);
			fflush(stdin);
		}
		system("cls");
		switch (sel) {
		case 1:
			NewData(data, long_sen, Title);
			break;
		case 2:
			LoadData(data, long_sen, Title);
			break;
		case 3:
			printf("1.��۸����\n ��۸����� ������ �ۼ��Ͽ� Ÿ�ڿ����� �� �� �ְԲ� ������ ���� ����ϴ�.\n\n\n2.Ÿ�ڿ���\n Ÿ�ڿ����Դϴ�. Ÿ�ڸ� �� ģ �� Ʋ�� �κ��� ������ ǥ�õ˴ϴ�.");
			gotoxy(41, 25);
			Color(12);
			printf("�޴��� ���ư����� �ƹ�Ű�� ��������");
			Color(15);
			key = 0;
			while (1) {
				if (kbhit()) {
					key = getch();
					if (key != 0)
						break;
				}
			}
			break;
		case 4:
			system("cls");
			gotoxy(52, 18);
			Color(8);
			printf("����!!!!\n\n\n\n\n\n");
			Color(0);
			break;
		}
	}
	//	CountNum(data);     // ����� ����

	//	LoadData(data, long_sen);      // �������ִ� ��� �ҷ�����
	//SaveNum();         // ���� ���� �ֽ�ȭ

}