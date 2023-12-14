#include "speed.h"

static int isInList(List list, int newPosX, int newPosY, int fuel);
static int isInRoad(Track track, int posX, int posY, int newPosX, int newPosY);
static List getVoisin(int currX, int currY, int Vx, int Vy, int fuel);



List getBestPathWithSpeed(List list, Track track, int speedX, int speedY, int startFuel) {
    List v;
    Node *current;
    int currX, currY;
    int Vx;
    int Vy;
    int fuel;

    List path = createList(0, 0);
    headNode(&list);

    addNode(&path, list.head->x, list.head->y, NULL, speedX, speedY, startFuel);
    while(track.map[path.current->y][path.current->x] != ARRIVAL) {
        current = path.current;
        if(current == NULL) {
            return createList(0, 0);
        }

        currX = current->x;
        currY = current->y;
        Vx = current->Vx;
        Vy = current->Vy;
        fuel = current->fuel;

        v = getVoisin(currX, currY, Vx, Vy, fuel);
        headNode(&v);
        while(v.current != NULL) {
            if(isInList(list, v.current->x, v.current->y, v.current->fuel)) {
                if(isInRoad(track, currX, currY, v.current->x, v.current->y)) {
                    addNodeCurrent(&path, v.current->x, v.current->y, path.current, v.current->Vx, v.current->Vy, v.current->fuel);
                } 
            }
            nextNode(&v);
        }

        nextNode(&path);
    }
    return reconstructPath(path);
}


List getVoisin(int currX, int currY, int Vx, int Vy, int fuel) {
    List v = createList(0,0);
    int tempFuel;
    int accX;
    int accY;

    for(accX = -1; accX <= 1; accX++) {
        for(accY = -1; accY <= 1; accY++) {

            if(sqrt((Vx + accX)*(Vx + accX) + (Vy + accY)*(Vy + accY)) <= 5) {
                if(!((currX + Vx + accX == currX) && (currY + Vy + accY == currY))) {
                    tempFuel = gasConsumption(accX, accY, Vx, Vy, 0);
                    if(fuel + tempFuel >= 0) {
                        v.current = v.head;
                        if(v.current != NULL) {
                            while(v.current->next != NULL) {
                                if(((v.current->next->x - currX) * (v.current->next->x - currX)) + ((v.current->next->y - currY) * (v.current->next->y - currY)) > ((currX + Vx + accX - currX) * (currX + Vx + accX - currX)) + ((currY + Vy + accY - currY) * (currY + Vy + accY - currY))) {
                                    break;
                                }
                                v.current = v.current->next;
                            }
                        }
                        addNodeCurrent(&v, currX + Vx + accX, currY + Vy + accY, NULL, Vx + accX, Vy + accY, fuel + tempFuel);
                    }
                }
            }
        }
        
    }
    return v;

}


int isInRoad(Track track, int posX, int posY, int newPosX, int newPosY) {
  InfoLine vline;
  Pos2Dint p;

  Pos2Dint start;
  Pos2Dint stop;

  start.x = posX;
  start.y = posY;
  stop.x = newPosX;
  stop.y = newPosY;

  initLine(start.x, start.y, stop.x, stop.y, &vline);
  while (nextPoint(&vline, &p, +1) > 0) {
    if (p.x == start.x && p.y == start.y) {
      continue;
    }
    if(track.map[p.y][p.x] == OFF_ROAD) {
        return 0;
    }
  }

  if(track.map[newPosY][newPosX] == SAND) {
      return 0;
  }
  return 1;
}


int isInList(List list, int newPosX, int newPosY, int fuel) {
    Node* currNode = list.head;
    while(currNode != NULL) {
        if(currNode->x - (newPosX) == 0 && currNode->y - (newPosY) == 0) {
            break;
        }
        currNode = currNode->next;
    }
    
    if(currNode == NULL) {
        return 0;
    }

    if(fuel <= currNode->fuel) {
        return 0;
    }

    return 1;
}