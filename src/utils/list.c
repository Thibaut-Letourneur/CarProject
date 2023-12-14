#include "list.h"

static Node* createNode(int x, int y, int Vx, int Vy, int fuel);


void freeList(List list) {
    Node* tmp;
    Node* curr = list.head;
    while (curr != NULL) {
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }

    if(list.count->dimX != 0 && list.count->dimY != 0) {
        freeArray((void**)list.count->tab, list.count->dimY);
    }
    free(list.count);
}


List createList(int dimX, int dimY) {
    List newList;
    newList.current = NULL;
    newList.head = NULL;
    newList.count = ec_malloc("createList()", sizeof(Table));
    newList.count->dimX = dimX;
    newList.count->dimY = dimY;
    newList.count->tab = NULL;

    if(dimX != 0 && dimY != 0) {
        newList.count->tab = CreateEmptyIntArray(dimX, dimY);
    }
    return newList;
}


Node* createNode(int x, int y, int Vx, int Vy, int fuel) {
    Node* newNode = (Node*)ec_malloc("addNode()", sizeof(Node));
    newNode->next = NULL;
    newNode->parent = NULL;
    newNode->x = x;
    newNode->y = y;
    newNode->Vx = Vx;
    newNode->Vy = Vy;
    newNode->fuel = fuel;
    return newNode;
}


void addNode(List* list, int x, int y, Node* parent, int Vx, int Vy, int fuel) {
    Node* curr;
    Node* newNode = createNode(x, y, Vx, Vy, fuel);

    newNode->parent = parent;
    if(list->head == NULL) {
        list->current = newNode;
        list->head = newNode;
    } else {

        curr = list->current;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        
        curr->next = newNode;
        newNode->next = NULL;
    }

    if(list->count->tab != NULL) {
        list->count->tab[y][x] += 1;
    }
}


void addNodeHead(List* list, int x, int y, Node* parent) {
    Node* newNode = createNode(x, y, 0, 0, 0);

    newNode->parent = parent;
    if(list->head == NULL) {
        list->current = newNode;
        list->head = newNode;
    } else {

        newNode->next = list->head;
        list->head = newNode;
    }

    if(list->count->tab != NULL) {
        list->count->tab[y][x] += 1;
    }
}


void addNodeCurrent(List* list, int x, int y, Node* parent, int Vx, int Vy, int fuel) {
    Node *newNode, *curr, *temp;
    newNode = createNode(x, y, Vx, Vy, fuel);

    newNode->parent = parent;
    if(list->head == NULL) {
        list->current = newNode;
        list->head = newNode;
    } else {

        curr = list->current;
        temp = curr->next;
        curr->next = newNode;
        newNode->next = temp;
    }

    if(list->count->tab != NULL) {
        list->count->tab[y][x] += 1;
    }
}


void nextNode(List* list) {
    if(list->current != NULL) {
        list->current = list->current->next;
    }
}


void parentNode(List* list) {
    if(list->current != NULL) {
        list->current = list->current->parent;
    }
}


void headNode(List* list) {
    list->current = list->head;
}


int searchNode(List list, int x, int y) {
    if(list.head != NULL) {
        if(list.count->tab[y][x] != 0) {
            return 1;
        }
    }

    return 0;
}


void printList(List list) {
   List echo;
   echo.current = list.head;
   while(echo.current != NULL) {
      printf("(%d, %d) -> ", echo.current->x, echo.current->y);
      nextNode(&echo);
   }
   printf("NULL\n");
}