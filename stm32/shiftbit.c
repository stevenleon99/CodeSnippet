#include <cstdio>

int main(int argc, char const *argv[])
{
    unsigned char data = 0x10;
    printf("this is binary: %d \n", data);
    for (int i=0; i<8; i++) {
        printf("this is binary: %d\n", data);
        data = data << 1;
    }
    return 0;
}
