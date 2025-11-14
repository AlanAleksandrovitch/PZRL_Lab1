#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "calcchec.h"
//#include "calcfunc.h"

char normOp(char *strOp){
	if (strOp == NULL||strOp[0]=='\0'){
		printf("Ошибка ввода: введён некорректный знак операции");
		return 'e';
	}
	if (strlen(strOp) == 1){
		char op=strOp[0];
		if (op == '+' || op == '-' || op == '*' || op == '%') {
			return op;
        	}
		else{
			printf("Ошибка ввода: введён некорректный знак операции");
			return 'e';
		}
	}
	else{
		printf("Ошибка ввода: введён некорректный знак операции");
		return 'e';
	}
}

int isNum(char *num){
	for (int i = 0; i<strlen(num); i++){
		if (isdigit(num[i])==0){
			return 0;
		}
	}
	return 1;
}

int calculation(int left, char op, int right){
	switch (op){
		case('+'):
			return left + right;
		case('-'):
			return left - right;
		case('*'):
			return left * right;
		case('%'):
			if (right == 0){
				printf("Ошибка ввода: деление на 0!");
				return 0;
			}
			return left % right;
		default:
			printf("Ошибка ввода: введён некоррректный знак операции");
			return 0;
	}
}

void decoder(int output[], int key, int opCount){
	int charOut;
	printf("Результирующая строка: ");
	for (int i = 0; i<opCount; i++){
		charOut=(output[i]-key);
		printf("%c", charOut);
	}
}

int main(int argc, char **argv)
{
	if(argc<5){
		printf("Ошибка ввода: недостаточно аргументов");
		return 1;
	}
	int kPlace = -1;				//Место флага k в строке ввода
	for (int i = 0;i<argc;i++){
		if (strcmp(argv[i],"-k")==0){
			kPlace=i;
		}
	}
	int beforeK = kPlace - 1;			//кол-во аргументов, введёных до k
	int key;					//ключ декодировки
	int opCount = beforeK / 3;			//кол-во операций	
	if (kPlace == -1){
		printf("Ошибка ввода: флаг -k не введён");
		return 1;
	}
	if (kPlace == argc - 1){
		printf("Ошибка ввода: ключ не введён");
		return 1;
	}
	if (isNum(argv[kPlace+1]) == 0){
		printf("Ошибка ввода: введён некорректный ключ");
		return 1;
	}
	key = atoi(argv[kPlace+1]);
	if (kPlace + 2 != argc){
		printf("Ошибка ввода: введён некорректный ключ");
		return 1;
	}
	if (beforeK % 3!=0){
		printf("Ошибка ввода: некорретный ввод аргументов");
		return 1;
	}
	int *output = calloc(opCount,sizeof(int));
	if (output == NULL){
		printf("Ошибка системы: не удалось выделить память");
		return 2;
	}
	int outIndex = 0;
	for (int i = 1; i<kPlace; i+=3){
		char oper = normOp(argv[i+1]);
		if (oper == 'e'){
			free(output);
			return 1;
		}
		if (isNum(argv[i]) == 0 || isNum(argv[i+2]) == 0){
			printf("Ошибка ввода: введён некорректный операнд");
			return 1;
		}
		int left = atoi(argv[i]);
		int right = atoi(argv[i+2]);
		output[outIndex]=calculation(left, oper, right);
		outIndex+=1;
	}
	for (int i = 0; i<opCount; i++){
		printf("Ответ №%d: %d \n", i+1, output[i]);
	}
	decoder(output, key, opCount);
	free(output);
	return 0;
}
