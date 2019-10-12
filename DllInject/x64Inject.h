#pragma once
#include <windows.h>
#include <winternl.h> 
#include "MyOutputDebugString.h"

typedef struct _LSA_UNICODE_STRING{
	USHORT Length;
	USHORT MaximumLength;
	PWSTR Buffer;
} LSA_UNICODE_STRING, *PLSA_UNICODE_STRING;

typedef NTSTATUS (NTAPI *pRtlInitUnicodeString)(PUNICODE_STRING,PCWSTR);
typedef NTSTATUS (NTAPI *pLdrLoadDll)(PWCHAR,ULONG,PUNICODE_STRING,PHANDLE);

typedef struct _THREAD_DATA
{
	pRtlInitUnicodeString fnRtlInitUnicodeString;
	pLdrLoadDll fnLdrLoadDll;
	UNICODE_STRING UnicodeString;
	WCHAR DllName[260];
	PWCHAR DllPath;
	ULONG Flags;
	HANDLE ModuleHandle;
}THREAD_DATA,*PTHREAD_DATA;

typedef VOID (WINAPI *fRtlInitUnicodeString)(PUNICODE_STRING DestinationString,
	PCWSTR ourceString);

typedef NTSTATUS (WINAPI *fLdrLoadDll)(IN PWCHAR PathToFile OPTIONAL, 
	IN ULONG Flags OPTIONAL, IN PUNICODE_STRING  ModuleFileName, 
	OUT PHANDLE ModuleHandle);

typedef DWORD64 (WINAPI *_NtCreateThreadEx64)(PHANDLE ThreadHandle,
	ACCESS_MASK DesiredAccess, LPVOID ObjectAttributes, HANDLE ProcessHandle,
	LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, 
	BOOL CreateSuspended, DWORD64 dwStackSize,
	DWORD64 dw1, DWORD64 dw2, LPVOID Unknown);

class Cx64Inject
{
public:
	Cx64Inject(void);
	~Cx64Inject(void);
	BOOL InjectDll(DWORD dwProcessId,LPCWSTR lpcwDllPath);
private:
	BOOL EnableDebugPrivilege();
	BOOL IsVistaOrLater();
	HANDLE MyCreateRemoteThread(HANDLE hProcess, 
		LPTHREAD_START_ROUTINE pThreadProc, LPVOID pRemoteBuf);
};

