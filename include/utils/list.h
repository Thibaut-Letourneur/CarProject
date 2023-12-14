#ifndef LIST_h
#define LIST_h

#include <stdio.h>
#include <stdlib.h>

#include "track.h"
#include "array.h"


typedef struct {
    int dimX;
    int dimY;
    int** tab;
} Table;

typedef struct _node {
    int x;
    int y;
    int Vx;
    int Vy;
    int fuel;
    struct _node* next;
    struct _node* parent;
} Node;

typedef struct _list {
    Node* current;
    Node* head;
    Table* count;   /* cell[x, y] contain the number of elements (node[x, y]) in the list*/
} List;



/**
 * @brief Free a list pointer.
 *
 * @param list Variable with type List.
 */
extern void freeList(List list);


/**
 * @brief Allocate the memory for a list.
 *
 * @param list Variable with type List
 */
extern List createList(int dimX, int dimY);


/**
 * @brief Add a new node at the end of the list.
 *
 * @param list The list who add a new node.
 * @param x The location of the visited case (X axis).
 * @param y The location of the visited case (Y axis).
 * @param Vx Speed of the pilot (x axis) before the acceleration.
 * @param Vy Speed of the pilot (y axis) before the acceleration.
 * @param fuel Total fuel.
 */
void addNode(List* list, int x, int y, Node* prev, int Vx, int Vy, int fuel);


/**
 * @brief Add a new node at the head of the list.
 *
 * @param list The list who add a new node.
 * @param x The location of the visited case (X axis).
 * @param y The location of the visited case (Y axis).
 */
extern void addNodeHead(List* list, int x, int y, Node* prev);


/**
 * @brief Add a new node at the current of the list.
 *
 * @param list The list who add a new node.
 * @param x The location of the visited case (X axis).
 * @param y The location of the visited case (Y axis).
 * @param Vx Speed of the pilot (x axis) before the acceleration.
 * @param Vy Speed of the pilot (y axis) before the acceleration.
 * @param fuel Total fuel.
 */
void addNodeCurrent(List* list, int x, int y, Node* prev, int Vx, int Vy, int fuel);


/**
 * @brief Go to the next node of a list.
 *
 * @param list The list we want to pass to the next node.
 */
extern void nextNode(List* list);


/**
 * @brief Go to the parent node of the current node.
 *
 * @param list The list we want to pass to the previous node.
 */
extern void parentNode(List* list);


/**
 * @brief Go to the head node of a list.
 *
 * @param list The list we want to pass to the head node.
 */
extern void headNode(List* list);


/**
 * @brief Get if a position is in the list.
 *
 * @param list The list we want to serch a position.
 * 
 * @return Return 1 if the position is in the list, 0 otherwise.
 */
extern int searchNode(List list, int x, int y);


/**
 * @brief Show the list pass in parameter.
 *
 * @param list The list we want to show.
 */
extern void printList(List list);

#endif