#include "calcchec.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char normOpChec(char *strOp){
        if (strOp == NULL || strOp[0] == '\0'){
                printf("Ошибка ввода: введён некорректный знак операции \n");
                return 'e';
        }
        if (strlen(strOp) == 1){
                char op=strOp[0];
                if (op == '+' || op == '-' || op == '*' || op == '%') {
                        return op;
                }
                else{
                        printf("Ошибка ввода: введён некорректный знак операции \n");
                        return 'e';
                }
        }
	printf("Ошибка ввода: введён некорректный знак операции \n");
	return 'e';
}
int isNumChec(char *num){
	if (num == NULL || num [0] == '\0'){
		return 0;
	}
	unsigned int start = 0;
	if (num[0] == '-'){
		start = 1;
		if (num[1] == '\0'){
			return 0;
		}
	}
	if (isdigit(num[start]) == 0){
		return 0;
	}
	for (unsigned int i = 1; i<strlen(num); i++){
		if (isdigit(num[i])==0){
			return 0;
		}
	}
	return 1;
}
int sizeChec(int argc){
	if(argc<6){
		printf("Ошибка ввода: недостаточно аргументов \n");
		return 1;
	}
	return 0;
}

int flagChec(int kPlace){                                       //проверка на наличие флага -k (0 - верно/1 - неверно)
	if (kPlace == -1){
                printf("Ошибка ввода: флаг -k не введён \n");
                return 1;
        }
	return 0;
}
int keyInChec(int kPlace,int argc){                             //проверка на наличие ключа и его единство (0 - есть флаг и он один/1 - нет ключа/1 - ключ не один)
	if (kPlace == argc - 1){
                printf("Ошибка ввода: ключ не введён \n");
                return 1;
	}
	if (kPlace + 2 != argc){
                printf("Ошибка ввода: введён некорректный ключ \n");
                return 1;
	}
	return 0;
}
int keyChec(char *num){                                         //проверка на корректность ключа (проверка на то, что это число) (0 - число/1 - не число)
	if (isNumChec(num) == 0){
                printf("Ошибка ввода: введён некорректный ключ \n");
                return 1;
        }
	return 0;
}
int opCountChec(int beforeK){                                   //проверка на верность кол-ва введённых аргументов (0 - кратное 3/1 - не кратное 3)
	if (beforeK % 3!=0){
                printf("Ошибка ввода: некорретный ввод аргументов \n");
                return 1;
	}
	return 0;
}
