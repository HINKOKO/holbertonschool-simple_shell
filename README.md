<h1 align="center" style="color:#FFFFFF"> C - Simple Shell<h1>

<br>

<p align="center">
  <img src="https://bashlogo.com/img/symbol/jpg/full_colored_light.jpg" />
</p>

<h3 align="right">by Anthony Pizzony & Nehemie Mombanga<h3>

# (Not so) Simple Shell 

## Table of contents



A brief description of what this project does and who it's for

- [Description](#description) 
- [File Structure](#file-structure)
- [Requirements](#requirements)
- [Usage](#usage)
- [Exemple of use](#example-of-useex)
- [Authors](#authors)
- [License](#license)

## Description 

A UNIX-Shell is a command-line interpreter or "shell" that provides you a command-line
user interface for Unix-like operating systems.
The Shell is both an interactive and a scripting language.
The first Shell was the "Thompson Shell", written by Ken Thompson at Bell Labs, distributed
from 1971 to 1975.
Ken Thompson developped his Shell version, associated with Dennis Ritchie, in the B programming
language.
After creating B, Ritchie and teammates moved to language C.

## File structure

- [Authors](https://github.com/NehemieMbg/holbertonschool-simple_shell/blob/main/AUTHORS.md) - list of contributors to this project
- [man_simple_shell](https://github.com/NehemieMbg/holbertonschool-simple_shell/blob/main/man_shell) - manual page for the simple_shell
- [shell.h](https://github.com/NehemieMbg/holbertonschool-simple_shell/blob/main/shell.h) - header program file
- Major builtins functions supported:<br>
        - [check_builtins.c](https://github.com/NehemieMbg/holbertonschool-simple_shell/blob/main/check_builtin.c) - check if user's command matches a builtin <br>
        - [new_exit](https://github.com/NehemieMbg/holbertonschool-simple_shell/blob/main/new_exit.c) - exits the shell <br>
        - [print_env](https://github.com/NehemieMbg/holbertonschool-simple_shell/blob/main/print_env.c) - prints the shell environnement's variable to standard output <br>
- Program running commands: <br>
        - [executor](https://github.com/NehemieMbg/holbertonschool-simple_shell/blob/main/executor.c): execute process expected <br>
        - [exec_path](https://github.com/NehemieMbg/holbertonschool-simple_shell/blob/main/execpath.c): search a command along the PATH <br>
        - [pathfinder](https://github.com/NehemieMbg/holbertonschool-simple_shell/blob/main/path_finder.c): Look in PATH if command exist <br>
- String Functions: <br>
        - [Parser](https://github.com/NehemieMbg/holbertonschool-simple_shell/blob/main/Parser.c): get_args function creates token words with the command entered, free_argsfunction frees the space allocated for the array of args. <br>
        - [wordcount](https://github.com/NehemieMbg/holbertonschool-simple_shell/blob/main/wordcount.c): create tokenized words. <br>
- Signal Functions: <br>
        - [handle_signal](): function that handle the signal inputed by (Ctrl^C), doesn't exit the shell but displays a new line. <br> 

## Requirements

Simple shell project was compiled on `Ubuntu 20.04 LTS` using gcc compiler, with following options <br>

```
gcc -Wall -Werror Wextra -pedantic -std=gnu89
```
## Usage

Clone this repository: <br>
```
git clone git@github.com:NehemieMbg/holbertonschool-simple_shell.git
```
Switch inside the directory: 
```
cd holbertonschool-simple_shell
```
Compile all the files with the correct flags and the wildcard *.c :
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -o ./hsh
```
You're all good to use the shell either in Interactive mode, to do so enter in your terminal:
```
./hsh
```
Then a prompt will be displayed, and you can enter commands.

The other way is in Non-Interactive mode, for example if you want to list files and directory, command ```ls```, call the shell like so:
```
echo "/bin/ls" | ./hsh
```
## Example of use

This is what our shell looks like:

![DuragShell](/Screenshots/durag%20shell.png)

## Authors

*The two following persons worked on this project:* <br>
Nehemie Mombanga <br>
&nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;- nehemie.mbg@gmail.com <br>
&nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;- https://github.com/NehemieMbg

Anthony Pizzoni <br>
&nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;- piotr62@live.fr <br>
&nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;- https://github.com/HINKOKO

## License

Our simple shell is open-source, free to download and use without permissions.



[Back to Summary](#table-of-contents)






