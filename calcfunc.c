#include <stdio.h>
#include <string.h>
#include "calcfunc.h"
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

int kPosition(int argc, char **argv){
        for (int i = 0;i<argc;i++){
                if (strcmp(argv[i],"-k")==0){
                        return i;
                }
        }
        return -1;
}
