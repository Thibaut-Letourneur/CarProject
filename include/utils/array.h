#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"


/**
 * @brief Clear memory of an array
 *
 * @param tab The Array we want to free.
 * @param dimX Dimenssion of the tab allocated (X axis).
 * @param dimY Dimenssion of the tab allocated (Y axis).
 */
extern void freeArray(void **tab, int dimY);


/**
 * @brief Allocate new int of char.
 *
 * @param dimX Dimenssion of the tab allocated (X axis).
 * @param dimY Dimenssion of the tab allocated (Y axis).
 * 
 * @return The pointer of the int table.
 */
extern int** CreateEmptyIntArray(int dimX, int dimY);


/**
 * @brief Allocate new table of char.
 *
 * @param dimX Dimenssion of the tab allocated (X axis).
 * @param dimY Dimenssion of the tab allocated (Y axis).
 * 
 * @return The pointer of the char table.
 */
extern char** CreateEmptyCharArray(int dimX, int dimY);


#endif 



