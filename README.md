# pipex

<p align="center">
  <img src="https://github.com/ArenKae/42-badges/blob/main/pipexe.png" alt="Pipex 42 project badge"/>
</p>

pipex is a 42 school project aimed to better understand shell redirection and pipes, by handling them in C.

This pipex program takes an input file, performs a command on it, pipes the result to another command which then writes its result to an output file. The result is virtually identical to this kind of shell command:
```
$ < input_file command1 | command2 > output file
```

---

## Status
Finished 12/06/2023. Grade: 100/100

## Usage
To compile, use ```make``` or ```make all```.

### Checking memory leaks
In order to check for memory leaks properly on MacOS, some adjustments need to be made to the code. First, we need to redirect stdout to its usual fd, since it is used in a pipe for this project. For this purpose, add the following line at the end of the main() function :
```
dup2(STDOUT_FILENO, fd2);
```
Then we can make a system call to check for leaks as usual :
```
system("leaks pipex");
```
In the pipex() function, we need to add a second fork in order for the stdout to work properly :
```
pid_t pid2;

[...]

pid2 = fork();
```
Then, replace the "else" statement with :
```
if (pid2 == CHILD)
```