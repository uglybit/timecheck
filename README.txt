'timecheck' lets you check the time of compiling and execution your cpp project

1. Compile 'timecheck':
    LINUX:   g++ timecheck.cpp -o timecheck
    WINDOWS: g++ timecheck.cpp -o timecheck.exe

2. Add 'timecheck' to your project directory

3. Make sure that 'timecheck' has permissions for execution

4. Check your *.cpp file: '$ ./timecheck <filename.cpp>' 
    for example, checking file 'main.cpp'
        LINUX:   ./timecheck main.cpp
        WINDOWS: .\timecheck.exe main.cpp

5. 'timecheck' will compile your *.cpp file and create output file

6. After execution output file will be deleted