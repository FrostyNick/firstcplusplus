Compile and execute this to try out the program.

# Compile

This assumes you're in the correct directory and you have `g++` or `gcc` installed and in your path.

`g++`
```bash
g++ first-code.cpp -o nameOfYourFile.exe
```

`gcc`
```bash
gcc -x c++ first-code.cpp -lstdc++ -o nameOfYourFile.exe
```

Note: `.exe` is not needed if you don't need to double click it. Also this is just for Windows.

# Execute

```bash
.\nameOfYourFile.exe # powershell (or you can double click the file in File Explorer in Windows)
./nameOfYourFile # linux if no .exe
```

# Old instructions
(This will proabably only work on debian-based linux distros, or not.)
If you know how to run bash, you can run the binary (the file without any extension) by typing `./first-code`. Make sure you use cd (change directory) to be in the correct location. Maybe I'll explain this better in the future.

Example executing the file if you saved the repository in Downloads:
```
cd Downloads/first
./first-code
```

