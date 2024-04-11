#define CRT SECURE NO WARNINGS 
#include <stdio.h> 
#include <Windows.h>
void main() {
    char text[100], text1[10], text2[20], text3[30];
    DWORD cb, cb2, cb3, cb4, cbw1, cbw2, cbw3, cbw4; 
    BOOL rc1, rc2, rc3;
    HANDLE hstdout, h1, h2, h3;
    hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

    h1 = CreateFile(TEXT("file.txt"), GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (h1 == INVALID_HANDLE_VALUE) return; 
    DuplicateHandle(GetCurrentProcess(), h1, GetCurrentProcess(), &h2, 0, FALSE, DUPLICATE_SAME_ACCESS);
    h3 = CreateFile(TEXT("file.txt"), GENERIC_READ, FILE_SHARE_READ, 0,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    BOOL rc = SetFilePointer(h1, 10, 0, FILE_BEGIN);
    if (rc == NULL) return;
    rc = ReadFile(h1, text, 80, &cb, NULL);
    if (!rc) return;
    WriteFile(hstdout, text, cb, &cbw1, NULL);
    printf("\nHandle values: h1=%d, h2=%d, h3=%d\n", h1, h2, h3);
    rc1 = SetFilePointer(h1, 0, 0, FILE_BEGIN);
    rc1 = ReadFile(h1, text1, 7, &cb2, NULL);
    if (!rc1) return;
    WriteFile(hstdout, text1, cb2, &cbw2, NULL); printf("\n");
    rc2 = SetFilePointer(h2, 7, 0, FILE_BEGIN);
    rc2 = ReadFile(h2, text2, 7, &cb3, NULL);
    if (!rc2) return; WriteFile(hstdout, text2, cb3, &cbw3, NULL); printf("\n");
    rc3 = SetFilePointer(h3, 14, 0, FILE_BEGIN);
    rc3 = ReadFile(h2, text3, 7, &cb4, NULL); if (!rc3) return;
    WriteFile(hstdout, text3, cb4, &cbw4, NULL);
    CloseHandle(h1);
    CloseHandle(h2);
    CloseHandle(h3);
}