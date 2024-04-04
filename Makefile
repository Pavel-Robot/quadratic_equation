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
check: init test1 test2
	@echo -e "\e[38;5;166mTesting module quadratic_equation end!\e[0m"


P_TS1=$(PATH_TESTS)/test1
P_TS2=$(PATH_TESTS)/test2
init:
	@echo -e "\e[38;5;166mTesting module quadratic_equation start!\e[0m"
	> $(P_TS1)/output.txt
	> $(P_TS2)/output.txt

test1: $(P_TS1)/input.txt $(P_TS1)/output.txt $(P_TS1)/correct.txt
	@echo -e "\e[38;5;166mTesting 1!\e[0m"; \
	out=""; \
	err=""; \
	counter=1; \
	coun_test=1; \
	true_test=0; \
	while IFS= read -r line1 && IFS= read -r line2 <&3; do\
		string="$$line1";\
    	args=$$(echo $$string);\
		if [ -n "$$line1" ] && ! [[ $$line1 == *"#"* ]]; then\
			out=$$(./quadratic_equation $$args 2>&1); \
			echo "$$out" >> $(P_TS1)/output.txt; \
			if [ "$$out" == "$$line2" ];\
			then\
				echo -e "\t\e[34m$$coun_test\e[0m \e[32mChecking the output data with correct of the test line \e[95m$$counter\e[0m ---- \e[32m[OK]\e[0m"; \
				((true_test++));\
			else\
				echo -e "\t\e[34m$$coun_test\e[0m \e[31mChecking the output data with correct of the test line \e[95m$$counter\e[0m ---- \e[31m[NO]\e[0m";\
				fi;((coun_test++));\
		else\
			echo "" 1>> $(P_TS1)/output.txt; fi; ((counter++));\
	done < $(P_TS1)/input.txt 3< $(P_TS1)/correct.txt; \
	echo -e "\e[96mTest1 check: total $$((coun_test-1)) : correct $$true_test : incorrect $$(($$coun_test-$$true_test-1))\e[0m"\

test2: $(P_TS2)/input.txt $(P_TS2)/output.txt $(P_TS2)/correct.txt
	@echo -e "\e[38;5;166mTesting 2!\e[0m"; \
	out=""; \
	err=""; \
	counter=1; \
	coun_test=1; \
	true_test=0; \
	while IFS= read -r line1 && IFS= read -r line2 <&3; do\
		string="$$line1";\
    	args=$$(echo $$string);\
		if [ -n "$$line1" ] && ! [[ $$line1 == *"#"* ]]; then\
			out=$$(./quadratic_equation $$args 2>&1); \
			echo "$$out" >> $(P_TS2)/output.txt; \
			if [ "$$out" == "$$line2" ];\
			then\
				echo -e "\t\e[34m$$coun_test\e[0m \e[32mChecking the output data with correct of the test line \e[95m$$counter\e[0m ---- \e[32m[OK]\e[0m"; \
				((true_test++));\
			else\
				echo -e "\t\e[34m$$coun_test\e[0m \e[31mChecking the output data with correct of the test line \e[95m$$counter\e[0m ---- \e[31m[NO]\e[0m";\
				fi;((coun_test++));\
		else\
			echo "" 1>> $(P_TS2)/output.txt; fi; ((counter++));\
	done < $(P_TS2)/input.txt 3< $(P_TS2)/correct.txt; \
	echo -e "\e[96mTest1 check: total $$((coun_test-1)) : correct $$true_test : incorrect $$(($$coun_test-$$true_test-1))\e[0m"\
