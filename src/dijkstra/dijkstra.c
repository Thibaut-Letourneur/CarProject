#include "dijkstra.h"

static void addVoisinToOpen(Track track, Node* current, List open, int goInSand);
static List findVoisin(Track track, Node* current, int goInSand);
static void checkVoisin(List* neighbord, Track track, Node* current, int accX, int accY, int goInSand);


List dijkstra(Track track, int startX, int startY, int fuel, int goInSand) {
    Node* current;

    List open = createList(track.largeur, track.hauteur);
    addNode(&open, startX, startY, NULL, 0, 0, 650);

    while(open.current != NULL) {
        current = open.current;

        if(track.map[current->y][current->x] == ARRIVAL) {
            open.current = current;
            return reconstructPath(open);
        }

        addVoisinToOpen(track, current, open, goInSand);
        nextNode(&open);
    }

    if(!goInSand) {
        return dijkstra(track, startX, startY, fuel, 1);
    }
    return createList(0, 0);
}


void addVoisinToOpen(Track track, Node* current, List open, int goInSand) {
    int x;
    int y;

    List v = findVoisin(track, current, goInSand);
    while(v.current != NULL) {
        x = v.current->x;
        y = v.current->y;

        if(searchNode(open, x, y) == 0) {
            addNode(&open, x, y, current, v.current->Vx, v.current->Vy, v.current->fuel);
        }
        nextNode(&v);
        
    }

    freeList(v);
}


List findVoisin(Track track, Node* current, int goInSand) {
    List neighbord = createList(0, 0);
    int accX;
    int accY;
    for(accX = -1; accX <= 1; accX++) {
        for(accY = -1; accY <= 1; accY++) {
            if(!(accX == 0 && accY == 0)) {
                checkVoisin(&neighbord, track, current, accX, accY, goInSand);
            }
        }
    }

    return neighbord;
}

void checkVoisin(List* neighbord, Track track, Node* current, int accX, int accY, int goInSand) {
    int newFuel;
    if(current->x + accX < 0 ||
        current->y + accY < 0 ||
        current->y + accY >= track.hauteur ||
        current->x + accX >= track.largeur) {
            return;
    }

    if(goInSand) {
        if(track.map[current->y +  accY][current->x + accX] != ROAD &&
            track.map[current->y + accY][current->x + accX] != ARRIVAL &&
            track.map[current->y + accY][current->x + accX] != SAND) {
                return;
        }
    } else {
        if(track.map[current->y +  accY][current->x + accX] != ROAD &&
            track.map[current->y + accY][current->x + accX] != ARRIVAL) {
                return;
        }
    }

    newFuel = gasConsumption(accX - current->Vx, accY - current->Vy, current->Vx, current->Vy, 0);
    addNode(neighbord, current->x + accX, current->y + accY, NULL, accX, accY, current->fuel + newFuel);

}


List reconstructPath(List list) {
    int finalFuel = list.current->fuel;
    List path = createList(0 ,0);

    while(list.current != NULL) {
        addNodeHead(&path, list.current->x, list.current->y, NULL);
        path.head->fuel = list.current->fuel - finalFuel;
        if(path.head->next != NULL) {
            path.head->next->parent = path.head;
        }
        parentNode(&list);
    }
    
    freeList(list);
    headNode(&path);
    return path;
}