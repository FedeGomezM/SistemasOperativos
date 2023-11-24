#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#define O_RDONLY  0x000
#define O_WRONLY  0x001
#define O_RDWR    0x002
#define O_CREATE  0x200
#define O_TRUNC   0x400

int main(int argc, char *argv[]) {
  int fd;

  if(argc == 1){
    printf("\nPor favor ingresar como argumento el nombre del archivo que desea crear para la prueba...\n");
    exit(1);
  }

  printf("\nTrying to create %s...\n", argv[1]);
  if((fd = open(argv[1], O_CREATE)) < 0){
    printf("Cannot open %s\n", argv[1]);
    exit(1);
  } else {
    printf("%s is created.\n", argv[1]);
    close(fd);
    printf("%s is closed.\n", argv[1]);
  }

  for(int i = 0; i <= 4; i++) {
    if(chmod(argv[1], i) < 0){
      printf("\nError cambiando protección de %s\n", argv[1]);
    } else {
      printf("\n%s protection changed to %d.\n", argv[1], i);
    }

    printf("\nTrying to open %s in Read Only...\n", argv[1]);
    if((fd = open(argv[1], O_RDONLY)) < 0){
      printf("Cannot open %s\n", argv[1]);
    } else {
      printf("%s is opened.\n", argv[1]);
      close(fd);
      printf("%s is closed.\n", argv[1]); 
    }

    printf("\nTrying to open %s in Write Only...\n", argv[1]);
    if((fd = open(argv[1], O_WRONLY)) < 0){
      printf("Cannot open %s\n", argv[1]);
    } else {
      printf("%s is opened.\n", argv[1]);
      close(fd);
      printf("%s is closed.\n", argv[1]); 
    }

    printf("\nTrying to open %s in Read-Write...\n", argv[1]);
    if((fd = open(argv[1], O_RDWR)) < 0){
      printf("Cannot open %s\n", argv[1]);
    } else {
      printf("%s is opened.\n", argv[1]);
      close(fd);
      printf("%s is closed.\n", argv[1]); 
    }
  }

  return 0;
}