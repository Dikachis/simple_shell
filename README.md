

# Shell Project `(simple Shell)`

By David Joel, and Nixon Okoth

A simple command-line interpreter developed as an end of trimester project at the ALX-Holberton School.

<h2>Description: :thought_balloon:</h2>

Simple shell reads simple commands from standard input or from a file and executes them.

<h3>Compilation :fireworks::</h3>

To invoke simple_shell, you must compile all the *.c files in the repository and run the resulting executable:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`<br/>
`./hsh`

Simple shell can be invoked in two modes: interactive and non-interactive.<br/>

**Non-interactive mode**

 invoked with standard input simple shell will read and execute commands in order.

Example:

`root@dea58c22b3fe:~/simple_shell# echo "/bin/ls" | ./hsh`<br/>
`'#README.md#'       a.out        getEnvironCharN.c   main.c                  strD2PathCpy.c   strtokPath.c`<br/>
`6forkExePrueba.c   concPath.c   hsh                 man_1_simple_shell.gz   strconcat.c`<br/>
`README.md          funcs.c      lib.h               strD2Cpy.c              strtok.c`<br/>
`root@dea58c22b3fe:~/simple_shell# echo "pwd" | ./hsh`<br/>
`/root/simple_shell`<br/>
`root@dea58c22b3fe:~/simple_shell#`<br/>


**Interactive mode**

Simple shell can also be invoked with standard input which will be determined isatty(). In this mode simple_shell will display a prompt, $, when ready to read the user's input.

Example:

`root@dea58c22b3fe:~/simple_shell# ./hsh`<br/>
`$ ls`<br/>
`6forkExePrueba.c  concPath.c         hsh     man_1_simple_shell.gz  strconcat.c`<br/>
`README.md         funcs.c            lib.h   strD2Cpy.c             strtok.c`<br/>
`a.out             getEnvironCharN.c  main.c  strD2PathCpy.c         strtokPath.c`<br/>
`$ pwd`<br/>
`/root/simple_shell`<br/>
`$ sooooo`<br/>
`IT DOES NOT WORK!`<br/>


- ### How the shell works?

  1. ** The shell prompts for user input **

     Using the `write()` function to display (stdout(1)) `$ `

  2. Get user input.

     Using the `char *user_input(void);` function, which uses `getline()`function to get and store user input into a buffer, which getline mallocs for, if getline succeds, the function returns the buffer that holds the user input. 

  3. Parse the input.

     Using the `char **tokens(char *buffer);` function, tokanizes the user input and saves each token into a double pointer erray(**hold_tokens). The double pointer erray is then returned.

  4. Run the command.

     1. Using the `int _execute(char **args);` function, checks if the user input is a builtin or not(this is called a filler). For example if the command `exit` is the user input. the function will make sure the command is in the array list of builtin commands."exit" or "env".

     2. If it's not then then the `int run(char **args);` function is returned.

     3. Using the `int run(char **args);` function, creates a child Proccess, In the child process we check if the user input is a path command (`/bin/ls`) or a regular command (`ls`). If it is a regular command (`ls`) we tokanize the path variable whos value is equall to PATH env variable, and cp = strcat("/", ls); = `/ls`, we then append `cp` to every path's token deliminated by `:`. This is saved into a variable called new. And then using `access` we check if the `new` variable is correct(`ls` is in the dir) or if we can execute `ls`. If so then `execve` the new varible. But if the user input is is a path then we skip all the above steps and just assigned the path to `execve`. AND finally if neither is true then `perror`.(print error).

  5. Starts again at number 1 until terminated(exit, or with kill signals).

- ### The PATH(env var)

  ** PATH ** is an environmental ** variable in Linux ** and other Unix-like operating systems that tells the shell which directories to search for executable files. Understanding the path, is really important to buiding a shell. Its important to know how to access the PATH (working with environmental variables). 

  

- ### Builtins

  A builtin command is a Linux/Unix command which is "* built into a shell interpreter * such as sh, ksh, bash, etc.

  

  ```c
  #include "simpleshell.h"
  
  /**
  * main - main shell function, where the magic happens
  * takes in no arg
  * Return: return (0) on success
  */
  
  int main(void)
  {
  	/* the dollar :)*/
  	char *prompt = "$ ";
  
  	char *buffer;
  	char **cmd;
  
  	while (1)
  	{
  		write(1, prompt, (sizeof(char) * 2));
  		buffer = user_input();
  		cmd = tokens(buffer);
  		_execute(cmd);
  
  		/* free(buffer);*/
  		/* free(cmd);*/
  	}
  }
  ```

  

  

| Function `(name)`                                            | File `(name)`                                                |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| `char *user_input(void);`                                    | [user_input.c](https://github.com/DavidJ001/simple_shell/blob/master/user_input.c) |
| `char **tokens(char *buffer);`                               | [tokens.c](https://github.com/DavidJ001/simple_shell/blob/master/tokens.c) |
| `int main(void);`                                            | [shell_main.c](https://github.com/DavidJ001/simple_shell/blob/master/shell_main.c) |
| `char *_getenv(char *var_name);`                             | [shell_getenv.c](https://github.com/DavidJ001/simple_shell/blob/master/shell_getenv.c) |
| `int run(char **args);`                                      | [run.c](https://github.com/DavidJ001/simple_shell/blob/master/run.c) |
| `void *_realloc(void *ptr, size_t old_size, size_t new_size);` | [100-realloc.c](https://github.com/DavidJ001/simple_shell/blob/master/100-realloc.c) |
| `int _execute(char **args);`<br />`int _exit(char **argv)`   | [execute.c](https://github.com/DavidJ001/simple_shell/blob/master/execute.c) |
| ** String functions **<br />`int _strlen(char *s);`<br />`char *_strchr(char *s, char c);`<br />`char *_strcat(char *dest, char *src);`<br />`int _strcmp(char *s1, char *s2);`<br />`char *str_concat(char *s1, char *s2);` | <br />[_strlen.c](https://github.com/DavidJ001/simple_shell/blob/master/_strlen.c)<br />[_strchr.c](https://github.com/DavidJ001/simple_shell/blob/master/_strchr.c)<br />[_strcat.c](https://github.com/DavidJ001/simple_shell/blob/master/_strcat.c)<br />[_strcmp.c](https://github.com/DavidJ001/simple_shell/blob/master/3-strcmp.c)<br />[2-str_concat.c](https://github.com/DavidJ001/simple_shell/blob/master/2-str_concat.c) |
| `man_1_simple_shell`                                         | [man_1_simple_shell](https://github.com/DavidJ001/simple_shell/blob/master/man_1_simple_shell) |



