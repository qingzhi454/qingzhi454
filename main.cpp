#include <stdio.h>
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -1 
typedef int Status;
typedef char SElemType;

typedef struct {
	SElemType* top;
	SElemType* base;
	int stacksize;
}SqStack;

Status InitStack(SqStack& S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack& S, SElemType e) {
	if (S.base == S.top)
		return ERROR;
	e = *(--S.top);
	return OK;
}

char GetTop(SqStack &S) {
	if (S.top != S.base)
		return *(S.top - 1);
}
int main() {
	using namespace std;
	int choose;
	int flag = 0;
	SqStack s;
	SElemType j, e, t=0;
	cout << "1.初始化\n";
	cout << "2.入栈\n";
	cout << "3.读取栈顶元素\n";
	cout << "4.出栈\n";
	cout << "5.退出\n";
	choose = -1;
	while (choose != 0) {
		cout << "请选择：";
		cin >> choose;
		switch (choose) {
		case 1:if (InitStack(s)) {
			flag = 1;
			cout << "初始化成功！\n\n";
		}
			  else 
			cout << "初始化失败 \n\n";
			  break;
		case 2: {
			fstream file;
			file.open("SqStack.txt");
			if (!file) {
				cout << "错误！未找到文件！\n \n" << endl;
				exit(ERROR);
			}
			if (flag) {
				flag = 1;
				cout << "进栈的元素依次为：\n";
				while (!file.eof()) {
					file >> j;
					if (file.fail())
						break;
					else {
						Push(s, j);
						cout << j << " ";
					}
				}
				cout << endl << endl;
			}
			else
				cout << "栈未建立，请重新选择\n\n";
			file.close();
		}
			  break;
		case 3:

			if (flag != -1 && flag != 0)

				cout << "桟顶元素为: \n" << GetTop(s) << endl << endl; 
			else
				cout << "桟中无元素，靖重新选择\n" << endl;

			break;

		case 4:
			cout << "依次弾出的桟頂元素为:\n";

			while (Pop(s,t)) {
				flag = -1;
				cout << t << " ";
			} cout << endl << endl;
			break;
		}
	}
	return 0;

}
