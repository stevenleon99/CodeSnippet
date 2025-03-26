#include <windows.h>
#include <iostream>
#include <cstring>

int main() {
    const char* message = "Hello from Process A!";
    size_t message_size = strlen(message) + 1; // Including the null terminator

    // Create a file mapping object for shared memory
    HANDLE hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,    // Use paging file
        NULL,                    // Default security
        PAGE_READWRITE,          // Read/write access
        0,                       // Maximum object size (high-order DWORD)
        1024,                    // Maximum object size (low-order DWORD) - 1KB
        "MySharedMemory");        // Name of the mapping object

    if (hMapFile == NULL) {
        std::cerr << "Could not create file mapping object (" << GetLastError() << ")." << std::endl;
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

    // Write the message to the shared memory
    CopyMemory(pBuf, message, message_size);
    std::cout << "Process A wrote message: " << message << std::endl;

    // Store the message size at the end of the shared memory
    size_t* message_size_ptr = (size_t*)((char*)pBuf + 1024 - sizeof(size_t));
    *message_size_ptr = message_size;

    // Cleanup
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    std::cout << "Press Enter to continue...";
    std::cin.get();
    
    return 0;
}