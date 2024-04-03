# Makefile for build program
.PHONY: all install uninstall clean check

SHELL := /bin/bash

CC=gcc # CC указываем компилятор, используемый для сборки
CFLAGS=-c -Wall # в переменной CFLAGS лежат флаги, которые передаются компилятору
POST_FLAGS=-lm#для математических библиотеке
# c - компилировать исходный файл, но не выполнять этап линковки
# Wall - включить все предупреждения компилятора
# o - указать имя файла после компиляции

NAME=quadratic_equation#Название выходной программы
BUILD=build#директория для сборки модуля

all: execute # стандартная цель по умолчанию
#$(CC) main.o factorial.o hello.o -o quadratic_equation 
execute: main $(BUILD)/$(NAME).o#factorial.o hello.o
	$(CC) $(BUILD)/$(NAME).o -o $(BUILD)/$(NAME) $(POST_FLAGS)

main: c/quadratic_equation.c
	mkdir $(BUILD)
	$(CC) $(CFLAGS) c/quadratic_equation.c -o $(BUILD)/$(NAME).o

install:
	cp $(BUILD)/$(NAME) $(NAME)
	clean

uninstall:
	rm quadratic_equation

clean:
	rm -R $(BUILD)/*
	rmdir $(BUILD)


PATH_TESTS=tests
check: init test1
	echo "Testing module quadratic_equation end!"


P_TS1=$(PATH_TESTS)/test1
P_TS2=$(PATH_TESTS)/test2
init:
	echo "Testing module quadratic_equation start!"
	> $(P_TS1)/output.txt
	> $(P_TS2)/output.txt

test1: $(NAME) $(P_TS1)/input.txt $(P_TS1)/output.txt $(P_TS1)/correct.txt 
	
	while IFS= read -r line; do\
    	echo "$$line";\
    	string="$$line";\
    	args=$$(echo $$string);\
		if [ -n "$$line" ] && ! [[ $$line == *"#"* ]]; then\
			./quadratic_equation $$args 1>> $(P_TS1)/output.txt 2>>$(P_TS1)/output.txt;\
		else\
			echo "" 1>> $(P_TS1)/output.txt;\
		fi\
  	done < $(P_TS1)/input.txt

    #./quadratic_equation $$args 1>> $(P_TS1)/output.txt 2>>$(P_TS1)/output.txt;\
# if [ -n "$$line" ]; then echo "Program"; else echo "Probel";fi\