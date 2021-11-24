# pipex

## Info
pipex: reproduce the shell's pipe and redirections. 

> <img width="201" alt="Screen Shot 2021-11-20 at 9 54 09 PM" src="https://user-images.githubusercontent.com/94758944/143295194-2b5b1470-f189-4ffa-a421-c2986dc9bc0f.png">

## How to use
- make
- make bonus

## Mandatory part:
- file1 and file2 are file names, cmd1 and cmd2 are shell commands with their parameters.
> ./pipex file1 cmd1 cmd2 file2

## Bonus part:
- Handle multiple pipes
> ./pipex_bonus file1 cmd1 cmd2 cmd3 ... cmdn file2
- Support « and » when the first parameter is "here_doc"
> ./pipex_bonus here_doc LIMITER cmd cmd1 cmd2 ... cmdn file
