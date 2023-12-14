/**
 * @file map.h
 * @brief Header file dealing with the map(track) of the Grand Prix
 *
 * This file contains the declaration of the map data structure
 * and its associated functions.
 *
 * @author Lucas Ollier 
 * @author Basile Pichereau
 * @author Thibaut Letourneur
 *
 * @date February 2023
 */

#ifndef TRACK_H
#define TRACK_H

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#include "array.h"

#define ROAD '#'
#define SAND '~'
#define OFF_ROAD '.'
#define ARRIVAL  '='

#define DRIVER1 '1'
#define DRIVER2 '2'
#define DRIVER3 '3'

#define MAX_LINE_LENGTH 1024
#define BOOSTS_AT_START 5

typedef struct _Track
{
    int largeur;
    int hauteur;
    int gazLevel;
    char **map;

} Track;


/**
 * @brief This function is used to retrieve the track given by the race manager. To do so, it
 * reads the characters on the standard ouput.
 * 
 * @return A structure representing the track given by the race manager. It contains the track itslef , its size, etc.
 *  
 */
extern Track getTrackStdin();


#endif 