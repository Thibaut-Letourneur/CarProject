#include <math.h>
#include "track.h"


Track getTrackStdin() {
    Track track;
    char line_buffer[MAX_LINE_LENGTH];
    int row;
    int x;

    fgets(line_buffer, MAX_LINE_LENGTH, stdin);
    sscanf(line_buffer, "%d %d %d", &track.largeur, &track.hauteur, &track.gazLevel);

    fprintf(stderr, "=== >Map< ===\n");
    fprintf(stderr, "Size %d x %d\n", track.largeur, track.hauteur);
    fprintf(stderr, "Gas at start %d \n\n", track.gazLevel);
    
    track.map = CreateEmptyCharArray(track.largeur, track.hauteur);

    for (row = 0; row < track.hauteur; ++row) {
        fgets(line_buffer, MAX_LINE_LENGTH, stdin);

        for (x = 0; x < track.largeur; x++) {
            track.map[row][x] = line_buffer[x];
        }

        fputs(line_buffer, stderr);
    }
    fflush(stderr);

    return track;
}