#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "dijkstra.h"
#include "track.h"
#include "array.h"
#include "speed.h"

#define MAX_LINE_LENGTH 1024


int main()
{
    int round = 0;
    int accelerationX = 0, accelerationY = 0;
    int speedX = 0, speedY = 0;
    char action[100];
    char line_buffer[MAX_LINE_LENGTH];
    List meilleur_chemin;

    Track track = getTrackStdin();

    fprintf(stderr, "\n=== Race start ===\n");
    while (!feof(stdin)) {
        int myX, myY, secondX, secondY, thirdX, thirdY;
        round++;
        fprintf(stderr, "=== ROUND %d\n", round);
        fflush(stderr);
        fgets(line_buffer, MAX_LINE_LENGTH, stdin);
        sscanf(line_buffer, "%d %d %d %d %d %d",
                &myX, &myY, &secondX, &secondY, &thirdX, &thirdY);
        fprintf(stderr, "    Positions: Me(%d,%d)  A(%d,%d), B(%d,%d)\n",
                myX, myY, secondX, secondY, thirdX, thirdY);
        fflush(stderr);

        /* Get best path with disjktra */
        meilleur_chemin = dijkstra(track, myX, myY, track.gazLevel, 0);
        meilleur_chemin = getBestPathWithSpeed(meilleur_chemin, track, speedX, speedY, track.gazLevel);
        headNode(&meilleur_chemin);
        
        /* Get all needed variable for the race manager */
        accelerationX = meilleur_chemin.current->next->x - meilleur_chemin.current->x - speedX;
        accelerationY = meilleur_chemin.current->next->y - meilleur_chemin.current->y - speedY;
        track.gazLevel += gasConsumption(accelerationX, accelerationY, speedX, speedY, 0);
        
        speedX = meilleur_chemin.current->next->x - meilleur_chemin.current->x;
        speedY = meilleur_chemin.current->next->y - meilleur_chemin.current->y;

        /* Write the acceleration request to the race manager (stdout). */
        sprintf(action, "%d %d", accelerationX, accelerationY);
        fprintf(stdout, "%s", action);
        fflush(stdout);
        fprintf(stderr, "    Action: %s   Gas remaining: %d    Speed: %d %d\n", action, track.gazLevel, speedX, speedY);
        fflush(stderr);
    }

    freeArray((void*)track.map, track.hauteur);
    return EXIT_SUCCESS;
}
