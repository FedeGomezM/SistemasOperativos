#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
    printf("Yo soy un hijo - dijo el proceso %d\n", getpid());
    printf("Yo soy tu padre - dijo el proceso %d\n", getppid());
    for (int i = 0; i < 5; i++){
        printf("Mi ancestro número %d es %d - dijo el proceso %d\n", i, getancestor(i), getpid());    
    };
    exit(0);
}