CC=gcc # CC указываем компилятор, используемый для сборки
CFLAGS=-c -Wall # в переменной CFLAGS лежат флаги, которые передаются компилятору
# c - компилировать исходный файл, но не выполнять этап линковки
# Wall - включить все предупреждения компилятора
# o - указать имя файла после компиляции

all: quadratic_equation # стандартная цель по умолчанию
#$(CC) main.o factorial.o hello.o -o quadratic_equation 
quadratic_equation: c/main.o #factorial.o hello.o
	$(CC) main.o -o c/quadratic_equation 

main.o: c/quadratic_equation.c
	$(CC) $(CFLAGS) "c/quadratic_equation.c"

clean:
	rm -rf *.o quadratic_equation