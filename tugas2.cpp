/*tugas2*/
/*Putut Wijanarko*/
/*14201035*/


#include <stdio.h>
#include <windows.h>

int main(VOID)
{
STARTUPINFO si;
PROCESS_INFORMATION pi;

/*allocate memory*/
ZeroMemory(&si, sizeof(si));
si.cb = sizeof(si);
ZeroMemory(&pi, sizeof(pi));

/*create child process*/
if(!CreateProcess(NULL,/*use command line*/
"C:\\WINDOWS\\system32\\mspaint.exe",/*command*/
NULL, /*don't inherit process handle*/
NULL, /*don't inherit thread handle*/
FALSE, /*disable handle inhetitance*/
0, /*no creation flags*/
NULL, /*use parent's environment block*/
NULL, /* use parent's existing directory*/
&si,
&pi))
{
  fprintf(stderr, "create process failed");
  return -1;
}

/*parent will wait for the child to complete*/
WaitForSingleObject(pi.hProcess, INFINITE);
printf("child complete");

/*close handles*/
CloseHandle(pi.hProcess);
Close Handle(pi.hThread);
}