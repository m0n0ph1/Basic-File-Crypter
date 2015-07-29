#Basic Crypter source code

Info: This is just a simple noob-friendly source code of crypter to get you started with making your own crypters. 
Please note that this is just a "skeleton" of a crytpter, having only the bare-minimum that a crypter needs in order to be functional. Anything on top of that, including the encryption, you have to add. 
Also, keep in mind that you are building the crypter file (that you can run), not a builder that generetes crypted files. 

Crypting method: 
This crypter stores the (unencrypted) bytes of an executable in itself, 
and runs in memory by a method called runPE. It does not drop anything on the HD. 

Specs: 
Coded in C++, compiled with MinGW compiler, Not FUD

Credits:
runPE - unknown author, found on many sites. Slightly modified by me.
Shellcode generator - Mark Russanovich. Slightly modified by me.
I did not code either the runPE or the shellcode generator, I have only slightly modified parts of it to fit the needs of this project.

Contents:
Crypter.cpp - The source code for the crypter.
runPE.h - The header that contains the method for executing an app in memory.
ShellcodeGenerator.cpp - The source code for the shellcode generator. The shellcode generator will take bytes of an executable's image on HD, and store it in a header file called "shellcode.h".
shellcode.h - The header file that stores the bytes of the executable you want to crypt. This will be the storage method of the crypter.
MessageBox.cpp - A simple messagebox app that we will use to test the crypter. If you see the messagebox after you run the crypter, then the crypter works fine. 
make.bat - If you are using the gcc comiler, there is this batch file in each folder that will comiler and link the source codes, for an easy way create executables.

How to compile:
1) Compile the MessageBox.cpp to create a MessageBox.exe, 
this will be the file we will be crypting. 
If you have another executable you want to test, that is fine too.

2) Compile ShellcodeGenerator.cpp to create ShellcodeGenerator.exe

3) Put MessageBox.exe (or whatever file you want to crypt) in ShellcodeGenerator.exe's folder.

4) Run ShellcodeGenerator.exe with parameters from command line like this: 
(ShellcodeGenerator.exe MessageBox.exe shellcode), after you run it you'll see shellcode.h created. 
This contains the bytes of our exetable that we wanted to crypt.

5) Put shellcode.h in crypter.cpp's directory.

6) Compile crypter.cpp, now you'll have you're crypter output called crypted.exe!

If you do everything correctly, after running crypted.exe you'll see the messagebox.