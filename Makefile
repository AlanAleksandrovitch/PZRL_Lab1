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
	rm $(TARGET) *.o $(TARGET)
run: $(TARGET)
	./cmdcalc 6 '*' 12 71 - 2 78 - 2 38 '*' 2 70 + 9 -k 0
