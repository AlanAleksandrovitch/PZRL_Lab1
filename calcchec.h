#pragma once

int isNumChec(char *num);

char normOpChec(char *strOp);

int sizeChec(int argc);						//Проверка на ввод

int flagChec(int kPlace);                            		//проверка на наличие флага -k (0 - верно/1 - неверно)

int keyInChec(int kPlace,int  argc);		       	       	//проверка на наличие ключа и его единство (0 - есть флаг и он один/1 - нет ключа/1 - ключ не один)

int keyChec(char *digit);		      	               	//проверка на корректность ключа (проверка на то, что это число) (0 - число/1 - не число)

int opCountChec(int beforeK);                          		//проверка на верность кол-ва введённых аргументов (0 - кратное 3/1 - не кратное 3)
