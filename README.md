# pipex

## Info
![image](https://user-images.githubusercontent.com/94758944/165585232-f29cc609-0dda-496a-a3ee-1f8fcd595c5d.png)

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
