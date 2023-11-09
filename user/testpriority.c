#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
  int priority = 0;

  for (int i = 0; i < 5; i++) {
    int pid = fork(priority);
    if (pid < 0) {
      printf(1, "Fork failed!\n");
    } else if (pid == 0) {
      // Proceso hijo
      for (int j = 1; j <= 60; j++) {
        printf("PID %d: %d seg\n", getpid(), j);
        sleep(1000);
      }
      exit();
    }
    priority += 1;
  }

  // Esperar a que todos los hijos terminen
  for (int i = 0; i < 5; i++) {
    wait();
  }

  exit();
}