#Basic 'Crypter' in C/C++
This project takes the Process Hollowing to the next level in an attempt to create something more like a 'crypter' (without the actual encryption or encoding, which will be added later in another project) Initially, the aim here is more about understanding the methods used, rather then to create actual encoders/encrypters, but over time this will happen also.

#ShellcodeGenerator.c
ShellcodeGenerator.c takes an executable as an input argument, and converts it into ShellCode (or ByteCode/Hexadecimal, whatever you prefer) A new .h header-file will be created called ShellCode.h, which contains an array with the shellcode of the executable, and the calculated size of that.

#runPE.h
runPE.h contains a class called runPE which has a void function called run, that takes two arguments, this will convert the shellcode.h file to an executable state again, and runs it in the context of the original process (crypter.cpp)

#crypter.cpp
Crypter.cpp contains the shellcode.h, which it will execute from memory through the runPE class

#OriginalVirus.c
Is just a simple Hello-World C-SourceFile, which is used instead of a virus to prevent harm to computers, if you want to test this on a real trojan, you can edit the batchfile to your needs, it should be pretty straightforward.

#Batch file: 
The batch file will compile, all the projects using the [MinGW-compiler](http://www.mingw.org/) for windows
