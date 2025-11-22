.PHONY: clean run
TARGET = cmdcalc
GCC_FLAGS=-Wall -Wextra
all:$(TARGET)
main.o: main.c
	gcc $(GCC_FLAGS) -c main.c
calcfunc.o: calcfunc.c calcfunc.h
	gcc $(GCC_FLAGS) -c calcfunc.c
calcchec.o: calcchec.c calcchec.h
	gcc $(GCC_FLAGS) -c calcchec.c
$(TARGET): main.o calcfunc.o calcchec.o
	gcc main.o calcfunc.o calcchec.o -o $(TARGET)
clean:
	rm -f *.o $(TARGET)
run: $(TARGET)
	./cmdcalc 6 '*' 13 71 + 4  41 '*' 2 182 % 100 5 '*' 17 5 '*' 10 32 + 6 93 + 0 117 - 0 132 - 12 100 + 14 106 % 1000 42 - 3 -k 6
