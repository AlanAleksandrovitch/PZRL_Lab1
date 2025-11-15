#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calcchec.h"
#include "calcfunc.h"

int main(int argc, char **argv)
{
	if (sizeChec(argc)){							//проверка, что число аргументов не меньше 5
		return 1;
	}
	int kPlace = -1;							//Место флага k в строке ввода	
	kPlace = kPosition(argc, argv);						//Нахождение позиции флага k
	int beforeK = kPlace - 1;						//кол-во аргументов, введёных до k
	int key;								//ключ декодировки
	int opCount = beforeK / 3;						//кол-во операций	
	if (flagChec(kPlace)){							//проверка на наличие флага -k
		return 1;
	}
	if (keyInChec(kPlace, argc)){						//проверка на наличие ключа и его единство
		return 1;
	}
	if (keyChec(argv[kPlace + 1])){						//проверка на корректность ключа (проверка на то, что это число)
		return 1;
	}
	key = atoi(argv[kPlace+1]);
	if (opCountChec(beforeK)){						//проверка на верность кол-ва введённых аргументов
		return 1;
	}
	int *output = calloc(opCount,sizeof(int));
	if (output == NULL){
		printf("Ошибка системы: не удалось выделить память\n");
		return 2;
	}
	int outIndex = 0;
	for (int i = 1; i<kPlace; i+=3){
		char oper = normOpChec(argv[i+1]);				//проверка на верность введённой операции
		if (oper == 'e'){
			free(output);
			return 1;
		}
		if (isNumChec(argv[i]) == 0 || isNumChec(argv[i+2]) == 0){	//проверка на верность введённых операндов
			printf("Ошибка ввода: введён некорректный операнд\n");
			return 1;
		}
		int left = atoi(argv[i]);
		int right = atoi(argv[i+2]);
		output[outIndex]=calculation(left, oper, right);		//выполнение арифметического действия
		outIndex+=1;
	}
	for (int i = 0; i<opCount; i++){
		printf("Ответ №%d: %d \n", i+1, output[i]);
	}
	decoder(output, key, opCount);						//выполнение и вывод декодирования
	free(output);
	return 0;
}
