# Makefile for build program
.PHONY: all install uninstall clean check

SHELL := /bin/bash

CC=gcc
CFLAGS=-fdiagnostics-color=always -Wall -g -I. -Wno-address -o
POST_FLAGS=-lm

# Name of the output program
NAME=quadratic_equation
#The directory for building the module
BUILD=c

# default standard target
all: execute 

execute: c/quadratic_equation.c c/quadratic_equation.h c/tests.h c/CuTest/lib/CuTest.c c/CuTest/lib/CuTest.h
	$(CC) $(CFLAGS) $(BUILD)/$(NAME) c/quadratic_equation.c c/quadratic_equation.h c/tests.h c/CuTest/lib/CuTest.c c/CuTest/lib/CuTest.h $(POST_FLAGS)

install:
	cp $(BUILD)/$(NAME) $(NAME)
	make clean

uninstall:
	rm quadratic_equation

clean:
	rm $(BUILD)/$(NAME)

check: $(NAME)
	./$(NAME) -t

