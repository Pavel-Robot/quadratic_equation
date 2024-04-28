# Makefile for build program
.PHONY: all install uninstall clean check

SHELL := /bin/bash

CC=gcc
CFLAGS=-c -Wall
POST_FLAGS=-lm

# Name of the output program
NAME=quadratic_equation
#The directory for building the module
BUILD=build

# default standard target
all: execute 

execute: main $(BUILD)/$(NAME).o
	$(CC) $(BUILD)/$(NAME).o -o $(BUILD)/$(NAME) $(POST_FLAGS)

main: c/quadratic_equation.c c/quadratic_equation.h c/tests.h c/CuTest/lib/CuTest.c c/CuTest/lib/CuTest.h
	mkdir $(BUILD)
	$(CC) $(CFLAGS) c/quadratic_equation.c -o $(BUILD)/$(NAME).o

install:
	cp $(BUILD)/$(NAME) $(NAME)
	make clean

uninstall:
	rm quadratic_equation

clean:
	rm -R $(BUILD)/*
	rmdir $(BUILD)

