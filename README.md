<h1 align="center" style="color:#FFFFFF"> C - Simple Shell<h1>

<br>

<p align="center">
  <img src="https://bashlogo.com/img/symbol/jpg/full_colored_light.jpg" />
</p>

<h3 align="right">by Anthony Pizzony & Nehemie Mombanga<h3>

# (Not so) Simple Shell 

## Table of contents



A brief description of what this project does and who it's for

- [Descrition](#description) 
- File Structure
- Requirements
- Usage
- Exemple of use 

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

- [Authors]() - list of contributors to this project
- [man_simple_shell]() - manual page for the simple_shell
- [shell.h] - header program file
- [builtins.c] - major builtin functions supported
          - check_builtins.c - check if user's command mathes a builtin
          - new_exit - exits the shell
          - _env - prints the shell environnement's variable to standard output
          -




## Requirements

Simple shell project was compiled on Ubuntu 20.04 LTS using gcc compiler, with following options <br>

>>>>>>>>>>gcc -Wall -Werror Wextra -pedantic -std=gnu89



