Partner Project Simple Shell
By Alfred Rosado and Britt Herman

Introduction
This is an implementation of a Linux shell written in C language.

Project details
Welcome to the Mandalorian Simple Shell project!! This program is a simple shell that can be compiled and launched from the command line.

How to Compile
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

Syntax
When using this shell, the syntax for running any command follows the familiar syntax when running a command in any other shell.

Builtin Commands
This shell supports a variety of commands:

alias - create or list an alias

cd - change directory

env - list the current environment variables

exit - exit the shell

history - display the command history for the current shell session

setenv - sets an environment variable

unsetenv - unsets an environment variable

Run the shell
Clone this directory and cd into it.
Run the command cc  shell.c -o shell.
Run ./shell.
Run any command in the shell. It can entail as many number of tabs and spaces, the shell accounts for those.
In order to exit, run exit.
