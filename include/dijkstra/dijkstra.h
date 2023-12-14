#ifndef ASTAR_H
#define ASTAR_H

#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "list.h"
#include "track.h"


/**
 * @brief The implementation of the Dijkstra algorithm.
 *
 * @param track The maps of the track.
 * @param startX The emplacement of the car start (X axis).
 * @param startY The emplacement of the car start (Y axis).
 * @param fuel Total fuel.
 * @param goInSand Boolean telling if the pilot can drive in sand.
 * 
 * @return The best path of the track set as parameter.
 */
extern List dijkstra(Track track, int startX, int startY, int fuel, int goInSand);


/**
 * @brief Reconstrct the best path with the return list of Dijkstra algorithm.
 *
 * @param list The return List of Dijkstra algorithm.
 * 
 * @return The path with the start point in head of list.
 */
extern List reconstructPath(List list);


#endif