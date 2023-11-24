#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    int fd;

    if((fd = open(argv[1], 0x200)) < 0){
      printf("Cannot open %s\n", argv[1]);
      exit(1);
    }
    printf("texto_prueba is opened");

    printf(fd);
    
    close(fd);

    return 0;
}