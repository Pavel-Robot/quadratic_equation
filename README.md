# Quadratic equation

## Task

Image

## Build and install
1 First, we configure (that is, compile and assemble the program):

```
make all or (make) 
```

2 Then we install (that is, in our case, we transfer the executable file to the root and delete the build folder):

```
make install
```

3 Then we run tests:

```
make check
```

If everything is fine, then

Image

4 To clean up and delete the build directory

```
make clean 
```

5 To delete the quadratic_equation executable from the root directory

```
make uninstall
```

## How to use the program

To call help for commands, call

```
./quadratic_equation -h
```

## Structure

The main quadratic_equation.c file contains the implementation.
The file quadratic_equation.h defines, structures and enums.
The tests are located in the tests directory.
The makefile contains installation and testing instructions.