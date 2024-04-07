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

At this point, the installation is complete. You may also need the following commands:

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

The tests are located in the tests directory. The tests are made by comparing the input with the output of the program. We get the input values from input.txt , we get the value and put it in output.txt after that, we compare the values with the lines in the file correct.txt . We do this through the bash while loop. You can also use diff to see the differences (diff output.txt correct.txt) in the tests or write python unit testing separately, but I did so.

The makefile contains installation and testing instructions.

## Dependencies

*gcc version 11.4.0 (Ubuntu 11.4.0-1ubuntu1~22.04)

*Linux kernel 5.15.0-100-universal

*Make 4.3
