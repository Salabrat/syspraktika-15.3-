#include <windows.h>
#include <stdio.h>

#define BUFFER_SIZE 4096

int main() {
    HANDLE hSourceTextFile, hTargetTextFile, hSourceBinFile, hTargetBinFile;
    char buffer[BUFFER_SIZE];
    DWORD dwBytesRead, dwBytesWritten;

    // Копирование текстового файла
    hSourceTextFile = CreateFile("source.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    hTargetTextFile = CreateFile("target.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hSourceTextFile == INVALID_HANDLE_VALUE || hTargetTextFile == INVALID_HANDLE_VALUE) {
        printf("Failed to open files.\n");
        return 1;
    }

    while (ReadFile(hSourceTextFile, buffer, BUFFER_SIZE, &dwBytesRead, NULL) && dwBytesRead > 0) {
        WriteFile(hTargetTextFile, buffer, dwBytesRead, &dwBytesWritten, NULL);
        if (dwBytesWritten != dwBytesRead) {
            printf("Failed to write file.\n");
            CloseHandle(hSourceTextFile);
            CloseHandle(hTargetTextFile);
            return 1;
        }
    }

    CloseHandle(hSourceTextFile);
    CloseHandle(hTargetTextFile);

    // Копирование бинарного файла
    hSourceBinFile = CreateFile("source.jpg", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    hTargetBinFile = CreateFile("target.jpg", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hSourceBinFile == INVALID_HANDLE_VALUE || hTargetBinFile == INVALID_HANDLE_VALUE) {
        printf("Failed to open files.\n");
        return 1;
    }

    while (ReadFile(hSourceBinFile, buffer, BUFFER_SIZE, &dwBytesRead, NULL) && dwBytesRead > 0) {
        WriteFile(hTargetBinFile, buffer, dwBytesRead, &dwBytesWritten, NULL);
        if (dwBytesWritten != dwBytesRead) {
            printf("Failed to write file.\n");
            CloseHandle(hSourceBinFile);
            CloseHandle(hTargetBinFile);
            return 1;
        }
    }

    CloseHandle(hSourceBinFile);
    CloseHandle(hTargetBinFile);
    
    return 0;
}
