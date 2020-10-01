# Process Hollowing used in many file Crypters (C/C++)
This project takes the Process Hollowing to the next level in an attempt to create something more like a 'crypter' (without the actual encryption or encoding, which will be added later in another project) 

Initially, the aim here is more about understanding the methods used, rather then to create actual encoders/encrypters, but over time this will happen also.

# ShellcodeGenerator.c
ShellcodeGenerator.c takes an executable as an input argument, and converts it into ShellCode (or ByteCode/Hexadecimal, whatever you prefer) 
A new .h header-file will be created called ShellCode.h, which contains an array with the shellcode of the executable, and the calculated size of that.

# runPE.h
runPE.h contains a class called runPE which has a void function called run, that takes two arguments, this will convert the shellcode.h file to an executable state again, and runs it in the context of the original process (crypter.cpp)

# crypter.cpp
Crypter.cpp contains the shellcode.h, which it will execute from memory through the runPE class

# OriginalVirus.c
Is just a simple Hello-World C-SourceFile, which is used instead of a virus to prevent harm to computers, if you want to test this on a real trojan, you can edit the batchfile to your needs, it should be pretty straightforward.

# MinGW Builder.bat: 
The batch file will compile, all the projects using the [MinGW-compiler](http://www.mingw.org/) for windows

# Note
This repository contains no actual malicious code of any kind, however, the example file CryptedVirus.exe in the executables folder, has a Detection ratio of 24 / 55 on virustotal [as you can see here] (https://www.virustotal.com/en-gb/file/88d762cc978932e939bb5936956eb3cfb8826b2611705dbb02fa437b4e29193a/analysis/1438197026/)

These are false-positives are the result of heuristic virus-scanners, they flag some of the used winapi's as 'malicous' because in the past malware like for instance Zeus/ZBot have also used these methods
