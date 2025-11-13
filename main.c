#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "calcchec.h"
//#include "calcfunc.h"

char normOp(char *strOp){
	if (strOp == NULL||strOp=='\0'){
		printf("Ошибка ввода: введён некорректный знак операции");
		return 'e';
	}
	if strlen(strOp == 1){
		char op=strOp[0];
		if (op == '+' || op == '-' || op == '*' || op == '%') {
			return op;
        	}
	}
	else{
		printf("Ошибка ввода: введён некорректный знак операции");
		return 'e';
	}
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

int main(int argc, char **argv)
{
	if(argc<5){
		printf("Ошибка ввода: недостаточно аргументов");
		return 1;
	}
	int kPlace = -1;			//Место флага k в строке ввода
	for (int i = 1;i<argc;i++){
		if (strcmp(argv[i],"-k")==0){
			k_place=i;
		}
	}
	int beforeK = kPlace - 1;		//кол-во аргументов, введёных до k
	int opCount = beforeK / 3;		//кол-во операций	
	if (kPlace == -1){
		printf("Ошибка ввода: флаг -k не введён");
		return 1;
	}
	if (kPlace == argc - 1){
		printf("Ошибка ввода: ключ не введён");
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
	for (int i = 1; i<kPlace; i+=3){
		char oper = normOp(argv[i+1]);
		if (op == 'e'){
			free(output);
			return 1;
		}
		int left = argv[i];
		int right = argv[i+2];
		output[i-1]=calcilation[left, oper, right];
	}
	for (int i = 0; i<opCount; i++){
		printf("Ответ №%d: %d", i+1, output[i]);
	}
	free(output);
	return 0;
}
