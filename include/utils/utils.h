/**
 * @file utils.h
 * @brief Header file dealing with wrapping functions that add an error checking layer to standard functions.
 * It helps to refactor the code.
 *
 * @author Lucas Ollier 
 * @author Basile Pichereau
 * @author Thibaut Letourneur
 *
 * @date February 2023
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



/**
 * @brief This funciton is simply a wrapper of the standard library malloc function. It checks if the return value is NULL. If it is the
 * case, it prints the error on standard error output.
 *
 * @param fonc Name of the function in which we allocate memory.
 * @param size Size we want to allocate in the heap.
 * 
 * @return A pointer to the allocated memory.
 */
void* ec_malloc(char* fonc, int size);


/**
 * @brief Compute the gas consumption according to the current acceleration and speed of the pilot.
 *
 * @param accX X coordinate of the acceleration.
 * @param accY Y coordinate of the acceleration.
 * @param speedX Speed of the pilot (x axis) before the acceleration.
 * @param speedY Speed of the pilot (y axis) before the acceleration.
 * @param inSand Boolean value telling if the pilot is currently driving in sand.
 * 
 * @return The gas consumption as an integer
 */
int gasConsumption(int accX, int accY, int speedX, int speedY, int inSand);


#endif