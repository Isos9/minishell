# Minishell (2016)

C shell that can execute commands as well as interpreting pipes, redirections, separators...

This shell is based on [tcsh](https://en.wikipedia.org/wiki/Tcsh).

## Requirements

 - [A Linux distribution](https://en.wikipedia.org/wiki/Linux_distribution) or [Apple's macOS](https://en.wikipedia.org/wiki/MacOS)
 - [Make](https://www.gnu.org/software/make/)
 - [GCC](https://gcc.gnu.org/)

## Execution

```
cd minishell
make
./mysh
```

## Features
 - Execute basic commands
 - Execute complex commands:
   - Separators
   - Pipes
   - Redirections
 - Can manage its own environment
 - Builtin commands:
   - `builtins`
   - `cd / chdir`
   - `echo`
   - `env [-0] [--null] [-u]`
   - `printenv`
   - `pwd`
   - `setenv`
   - `unsetenv`
