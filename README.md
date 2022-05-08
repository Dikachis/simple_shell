# 0x16. C - Simple Shell
## ![alt text](https://github.com/Dikachis/alx-low_level_programming/blob/master/image/shell.jpg?raw=true)

## Table of Content
* [Description](#Description)
* [Objectives](#Objectives)
* [General Requirements](#General-Requirements)
* [File Structure/description](#File-structures/description)
* [Installation](#Installation)
* [Usage](#Usage)
* [Example of Use](#Example-of-Use)
* [Bugs](#Bugs)
* [Authors](#Authors)
* [License](#License)

## Description
Shell is a program that takes the command inputs written from the the user’s keyboard and passes them to the machine to execute them through the kernel. It also verifies if the command inputs from the user are correct. A shell is a messanger between the user, the kernel and the machine [Ricardo Hincapie](https://medium.com/swlh/tutorial-to-code-a-simple-shell-in-c-9405b2d3533e) && [Unix shell](https://en.wikipedia.org/wiki/Unix_shell). 
Simple_shell is a command line interpreter, or shell, in the tradition of the first Unix shell written by [Ken Thompson](https://en.wikipedia.org/wiki/Thompson_shell) in 1971. Standard functions and system calls employed in simple_shell include: **access, execve, exit, fork, free, fstat, getline, malloc, perror, signal, stat, wait, write**.

## Objectives
* To have knowledge of who designed and implemented the original Unix operating system
* To know who wrote the first version of the UNIX shell
* To know who invented the B programming language (the direct predecessor to the C programming language)
* To know who is Ken Thompson
* To know how a shell works
* To know what a pid and a ppid is
* To know how to manipulate the environment of the current process
* To know the difference between a function and a system call
* To know how to create processes
* To know the three prototypes of main
* To know how the shell use the PATH to find the programs
* To know how to execute another program with the execve system call
* To know how to suspend the execution of a process until one of its children terminates
* To know what **EOF** / **“end-of-file”** is.

## General Requirements
* Allowed editors: **vi**, **vim**, **emacs**
* Simple_shell is designed to run in the **Ubuntu 20.04 LTS linux environment and to be compiled using using gcc**, with the options **-Wall -Werror -Wextra -pedantic -std=gnu89**
* All files ends with a new line
* There is a **README.md** file, at the root of the folder of the project
* Codes are compiled using the **Betty style**
* The only C standard library functions allowed are **malloc**, **free** and **exit**.
* Also allowed to use **_putchar**
* The prototypes of all your functions and the prototype of the function **_putchar** should be included in your header file called main.h
* All header files were include guarded
* AUTHORS file at the root of the repository, listing all individuals having contributed content to the repository.

## File structures/description
| S/N   |       Files          |        Description  |
|:-----:|:--------------------:|:-------------------|
|1. |  |  |
|2.|  |  |
|3. |  |  |
|4. |  |  |

## Installation
* Clone this repository: **git clone "https://github.com/alexaorrico/simple_shell.git"**
* Change directories into the repository: **cd simple_shell**
* Compile: **gcc -Wall -Werror -Wextra -pedantic *.c -o hsh**
* Run the shell in interactive mode: **./hsh**
* Or run the shell in non-interactive mode: example **echo "pwd" | ./hsh**

## Usage
The simple_shell is designed to execute commands in a similar manner to sh, however with more limited functionality. The development of this shell is ongoing. The below features will be checked as they become available (see man page for complete information on usage):
### Features
- [ ] uses the PATH
- [ ] implements builtins
- [ ] handles command line arguments
- [ ] custom strtok function
- [ ] uses exit status
- [ ] shell continues upon Crtl+C (^C)
- [ ] handles comments (#)
- [ ] handles ;
- [ ] custom getline type function
- [ ] handles && and ||
- [ ] aliases
- [ ] variable replacement

### Builtins
- [ ] exit
- [ ] env
- [ ] setenv
- [ ] unsetenv
- [ ] cd
- [ ] help
- [ ] history

## Example of Use
Run the executable in your terminal after compiling:
```
$ ./hsh
$ # This is our rendition of the shell
$ ls -al
total 100
drwxrwxr-x  3 vagrant vagrant  4096 Jul 19 22:49 .
drwxr-xr-x 14 vagrant vagrant  4096 Jul 17 22:37 ..
-rw-rw-r--  1 vagrant vagrant   144 Jul 19 17:16 AUTHORS
-rw-rw-r--  1 vagrant vagrant  2367 Jul 19 22:33 builtins2.c
-rw-rw-r--  1 vagrant vagrant  2347 Jul 19 22:49 README.md
-rw-rw-r--  1 vagrant vagrant  1769 Jul 19 22:04 shell.h
-rw-rw-r--  1 vagrant vagrant  1480 Jul 18 21:15 simple_shell.c
```

## Bugs
At this time, there are no known bugs.

## Authors
[ONYEDIKACHI OKPARA](https://github.com/Dikachis) || [Ezugo Ojukwu](https://github.com/zugo-m)

## License
Simple_shell is open source and therefore free to download and use without permission.


[Alx](https://alx-intranet.hbtn.io/projects/235) | [Firefox Pocket](https://getpocket.com/my-list?src=navbar)
