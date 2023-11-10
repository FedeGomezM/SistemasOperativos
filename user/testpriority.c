#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
  int priority = 0;
  int x, z;

  int pid1 = fork();
  priority += 1;
  if (pid1 < 0) {
    printf("Fork failed!\n");
  }
  int pid2 = fork();
  int pid2_2 = chprty(pid2, priority);
  if (pid2 < 0) {
    printf("Fork failed!\n");
  } else if (pid2_2 < 0) {
    printf("Priority Chande Failed!\n");
  }
  priority += 1;
  int pid3 = fork();
  int pid3_2 = chprty(pid3, priority);
  if (pid3 < 0) {
    printf("Fork failed!\n");
  } else if (pid3_2 < 0) {
    printf("Priority Chande Failed!\n");
  }
  priority += 1;
  int pid4 = fork();
  int pid4_2 = chprty(pid4, priority);
  if (pid4 < 0) {
    printf("Fork failed!\n");
  } else if (pid4_2 < 0) {
    printf("Priority Chande Failed!\n");
  }
  priority += 1;
  int pid5 = fork();
  int pid5_2 = chprty(pid5, priority);
  if (pid5 < 0) {
    printf("Fork failed!\n");
  } else if (pid5_2 < 0) {
    printf("Priority Chande Failed!\n");
  }
  
  for (int j = 1; j <= 60; j++) {
    printf("PID %d - PRTY %d: %d seg\n", getpid(), getprty(getpid()), j);
    for(z = 0; z < 400000000; z+=1){
      x = x + 3.14*89.64;
    }
  }

  return 0;
}