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

![image](https://github.com/Pavel-Robot/quadratic_equation/assets/50141984/0235a4d7-6dff-47f9-b86c-16509d1c9b7a)

At this point, the installation is complete. You may also need the following commands:

4 To clean up and delete quadratic_equation from the build directory

```
make clean 
```

5 To delete the quadratic_equation executable from the root directory

```
make uninstall
```

6 Directly test module:

```
./quadratic_equation -t
```

## How to use the program

To call help for commands, call

```
./quadratic_equation -h
```

Use example:

```
./quadratic_equation 1 2 3 
```

Ans:

```
-1.000000 1.414214 -1.000000 -1.414214
```

Note: The program also implements the stderr functionality, you can output errors to a file.

## Structure

The main quadratic_equation.c file contains the implementation.

The file quadratic_equation.h defines, structures and enums.
For example, you can change the behavior of the program from waiting for the transfer of console a,b,c by changing PROGRAM_COMMAND_LINE_ARGS TRUEMY to FALSEMY and work with input data using the solve_equation(...) function.

The tests are located in the c/tests.h file. Run from func RunAllTests() in file quadratic_equation.c. Or build ./quadratic_equation -t.

The makefile contains installation and testing instructions.

## Dependencies

*gcc version 11.4.0 (Ubuntu 11.4.0-1ubuntu1~22.04)

*Linux kernel 5.15.0-100-universal

*Make 4.3
