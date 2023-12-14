#ifndef SPEED_H
#define SPEED_H

#include "utils.h"
#include "list.h"
#include "follow_line.h"
#include "dijkstra.h"


/**
 * @brief This function determines the speed variations given a specific list. It tries to compute
 * the best use of speed on a track.
 * 
 * @param list This list is the actual best path on the track given by the Dijkstra algorithm
 * @param track The current track
 * @param Vx Speed of the pilot (x axis) before the acceleration.
 * @param Vy Speed of the pilot (y axis) before the acceleration.
 * @param fuel Total fuel.
 * 
 */
List getBestPathWithSpeed(List list, Track track, int Vx, int Vy, int fuel);

#endif