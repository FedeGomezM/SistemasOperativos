#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    static int sttc = 2;
    printf("Data: %d | Location of data : %p\n", sttc, (void*) &sttc);
    memset(&sttc, 123456789, 9*sizeof(int)); 
    printf("Data: %d | Location of data : %p\n", sttc, (void*) &sttc);
    printf("%d\n", mprotect((void*) &sttc, 10));
    memset(&sttc, 123456789, 9*sizeof(int)); 
    printf("Data: %d | Location of data : %p\n", sttc, (void*) &sttc);
    return 0;
}