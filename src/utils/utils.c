#include "utils.h"


void* ec_malloc(char* fonc, int size) {
    void* var = malloc(size);
    if(var == NULL) {
        printf("malloc error in %s\n", fonc);
        exit(EXIT_FAILURE);
    }
    return var;
}


int gasConsumption(int accX, int accY, int speedX, int speedY, int inSand)
{
  int gas = accX * accX + accY * accY;
  gas += (int)(sqrt(speedX * speedX + speedY * speedY) * 3.0 / 2.0);
  if (inSand) {
    gas += 1;
  }
  return -gas;
}