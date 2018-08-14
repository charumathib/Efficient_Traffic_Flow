/* Created by Charumathi Badrinath */

#include <stdio.h>

/**
 * A temporary array that the threeWayIntersection() and fourWayIntersection() methods will be working on. It is
 * cleared by the clearRoads() function immediately after it's contents have been translated into roadsArray[]
**/
road outgoingRoads[5] = {0, 0, 0, 0, 0};

/**
 * Counter variable which is incremented every time a given traffic flow causes cars to either merge or cross paths.
 * This counter is reset after every cycle of DFS through the implicit tree
**/
int conflicts = 0;

short roadsArray[NUM_ROADS * BIDIRECTIONAL];

void printRoads () {
    for (int i = 0; i < 38; i++) {
        printf ("%i", roadsArray[i]);
    }
    puts (" ");
    return;
}

/* Initializes the values of roads (number of roads * number of lanes) to unused at the start of the program */
void initialiseRoadArray (int noOfRoads, int lanes, short roads[]) {
    for (int i = 0; i < lanes * noOfRoads; i++) {
        roads[i] = 0;
    }
    return;
}

