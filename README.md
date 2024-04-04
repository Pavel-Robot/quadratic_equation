# Quadratic equation module

## Task

![image](https://github.com/Pavel-Robot/quadratic_equation/assets/50141984/9910074c-6523-44d5-82d3-6b6a2b735f0e)

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

![image](https://github.com/Pavel-Robot/quadratic_equation/assets/50141984/bf96f2b2-a9c3-4054-9cd2-7dda888c9846)

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

## Dependencies
*gcc version 11.4.0 (Ubuntu 11.4.0-1ubuntu1~22.04)
*Linux kernel 5.15.0-100-universal
*Make 4.3
