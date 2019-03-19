#include <stdio.h> 
#include <time.h>    // 시간함수
#include<windows.h>   // cls함수
#include<string.h>   // str함수
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

/*int LoadNum(char data[]) {           // 저장된 num 값 가져오기
stream = fopen("datanum.txt", "r");
fscanf(stream, "%d", &num);
fclose(stream);
return num;
}

void SaveNum() {         // num값 최신화

stream = fopen("datanum.txt", "wt");

fputc(num + 48, stream);
fclose(stream);
}*/

void NewData(char data[], char long_sen[], char Title[]) {          // 긴글 만들기
	int a = 0;
	int b = 0;
	int key = 0;
	char *mid;
	char title[100];

	Title[5] = CountNum(data) + 'A';
	stream = fopen(Title, "w");
	gotoxy(47, 3);
	printf("제목을 입력해주세요");
	gotoxy(53, 6);
	fflush(stdin);
	scanf("%s", title);
	fflush(stdin);
	fprintf(stream, "%s", title);
	fclose(stream);
	gotoxy(0, 10);
	printf("내용입력\n");
	mid = long_sen;
	while (1) {
		scanf(" %[^\n]s", mid);
		fflush(stdin);

		long_sen[strlen(long_sen)] = '\n';
		mid = &long_sen[strlen(long_sen)];
		Sleep(1500);           //  1.5초
		if (_kbhit() == 0)   // 1.5초간 입력없으면 종료
			break;
	}
	long_sen[strlen(long_sen) - 1] = '\0';

	printf("\n\n완료됐습니다.\n\n메뉴로 돌아가려면 아무키나 누르세요.\n");

	data[3] = CountNum(data) + 'A';

	stream = fopen(data, "w");    // 새로운 문장 대입		
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
	int *wrong;  // 틀린부분
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

	start = clock();// 시작시간
	a = 0;
	c = 0;
	while (cnt < A) {          // 받아쓰기 시작

		printf(" ");

		gets(temp);

		//Answer[strlen(Answer)] = ' ';
		gotoxy(0, 3 + ++c * 7);
		Answer[strlen(Answer)] = ' ';
		temp = &Answer[strlen(Answer)];
		cnt++;
	}
	Answer[strlen(Answer)] = '\0';


	end = clock();   // 종료시간
	fast = (float)(end - start) / CLOCKS_PER_SEC;    // 다치는데 걸리는시간
	e = 0;
	for (a = 0; long_sen[a] != '\0'; a++) {
		if (Answer[a] == long_sen[a])
			result++;
		else
			wrong[count++] = a;
	}
	Acc = result * 100 / strlen(long_sen);  // 정확도
	free(Answer);

	a = 0;
	stream = fopen(data, "r");
	count = 0;
	c = 0;
	gotoxy(0, 0);
	printf(" ");
	while (long_sen[e++] != '\0') {                // 틀린곳 빨간부분으로 나타낸다
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
	printf("정확도 : %d%%", Acc);
	gotoxy(47, c + 5);
	printf("초  당 : %.2f타\n", result / fast);
	gotoxy(47, c + 6);
	printf("분  당 : %.0f타", result / fast * 60);
	Color(15);

	fclose(stream);
	free(realtemp);
	free(wrong);
	gotoxy(40, c + 8);
	printf("아무키나 누르면 메뉴로 돌아갑니다.");
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

void LoadData(char data[], char long_sen[], char Title[]) {        // 긴글 불러오기
	char ans[3];         // 요기
	int a, b, c, Acc, d; //Acc는 정확도
	float fast;   // 빠르기
	char temp[100] = { '0', };
	b = c = d = 0;
	if (CountNum(data) == 0) {
		int key;
		gotoxy(43, 15);
		printf("현재 저장된 글이 없습니다.");
		gotoxy(40, 16);
		printf("아무키나 누르면 메뉴로 돌아갑니다.");
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
	do {                                    // 긴글선택
		system("cls");
		gotoxy(43, 5);
		printf("현재 %d개의 긴 글이 있습니다.", CountNum(data));
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
		printf("당신의 선택은 : ");
		gets(ans);
		fflush(stdin);
		if (ans[0] > CountNum(data) + '0' || ans[0] <= '0') {
			gotoxy(47, 21);
			printf("잘못입력하셨습니다.");
			for (a = 0; a < 500000000; a++);  // 지연
		}
		else {
			gotoxy(47, 21);
			printf("%d번을 선택하셨습니다.", ans[0] - '0');
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
	printf("아무키나 누르세요");
	while (1) {
		c = 0;
		for (a = 0; a < 8; a++) {
			gotoxy(37, 3 + c++);
			for (b = 0; b < 40; b++) {

				if (title[a][b] == 1) {
					printf("■");
					title[a][b] = 2;
				}
				else if (title[a][b] == 0) {
					printf(" ");
				}
				else if (title[a][b] == 2) {
					printf("□");
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
		printf("┌─────────┐");
		gotoxy(45, 11);
		printf("│  1.긴글 만들기   │");
		gotoxy(45, 12);
		printf("└─────────┘");

		gotoxy(45, 14);
		printf("┌─────────┐");
		gotoxy(45, 15);
		printf("│   2.타자 연습    │");
		gotoxy(45, 16);
		printf("└─────────┘");

		gotoxy(45, 18);
		printf("┌─────────┐");
		gotoxy(45, 19);
		printf("│    3. 도움말     │");
		gotoxy(45, 20);
		printf("└─────────┘");

		gotoxy(45, 22);
		printf("┌─────────┐");
		gotoxy(45, 23);
		printf("│     4. 종료      │");
		gotoxy(45, 24);
		printf("└─────────┘");

		gotoxy(45, 27);
		printf("메뉴 고르기 : ");
		scanf("%d", &sel);
		fflush(stdin);

		while (sel > 4 || sel <= 0) {
			gotoxy(59, 27);
			printf(" ");
			gotoxy(45, 30);
			printf("잘못고르셨습니다. 다시 골라주세요");
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
			printf("1.긴글만들기\n 긴글만들기는 본인이 작성하여 타자연습을 할 수 있게끔 본인이 글을 만듭니다.\n\n\n2.타자연습\n 타자연습입니다. 타자를 다 친 후 틀린 부분이 빨갛게 표시됩니다.");
			gotoxy(41, 25);
			Color(12);
			printf("메뉴로 돌아가려면 아무키나 누르세요");
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
			printf("종료!!!!\n\n\n\n\n\n");
			Color(0);
			break;
		}
	}
	//	CountNum(data);     // 긴글의 개수

	//	LoadData(data, long_sen);      // 가지고있는 긴글 불러오기
	//SaveNum();         // 파일 개수 최신화

}