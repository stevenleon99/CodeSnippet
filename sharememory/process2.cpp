#include <windows.h>
#include <iostream>

int main() {
    // Open the file mapping object for shared memory
    HANDLE hMapFile = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,     // Read/write access
        FALSE,                   // Do not inherit the name
        "MySharedMemory");       // Name of the mapping object

    if (hMapFile == NULL) {
        std::cerr << "Could not open file mapping object (" << GetLastError() << ")." << std::endl;
        return 1;
    }

    // Map the file into the address space of the current process
    LPVOID pBuf = MapViewOfFile(
        hMapFile,                // Handle to the map object
        FILE_MAP_ALL_ACCESS,     // Read/write permission
        0,                       // File offset high
        0,                       // File offset low
        1024);                   // Number of bytes to map (1KB)

    if (pBuf == NULL) {
        std::cerr << "Could not map view of file (" << GetLastError() << ")." << std::endl;
        CloseHandle(hMapFile);
        return 1;
    }

    // Read the message size from the end of the shared memory
    size_t* message_size_ptr = (size_t*)((char*)pBuf + 1024 - sizeof(size_t));
    size_t message_size = *message_size_ptr;

    // Read the message from the shared memory
    char* message = new char[message_size];
    CopyMemory(message, pBuf, message_size);
    std::cout << "Process B read message: " << message << std::endl;

    // Cleanup
    delete[] message;
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}