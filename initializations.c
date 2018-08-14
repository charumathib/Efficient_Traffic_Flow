//
// Created by Charumathi Badrinath on 7/30/18.
//

#include <stdio.h>

int counter = 0;

/**
 * Defines the structure which represents road intersections. It consists of 3 fields, namely an array storing the
 * assigned numbers of incoming roads, another array storing the assigned numbers of outgoing roads, and an integer
 * which stores the overall number of roads that meet at the given intersection
**/
typedef struct intersection {
    int incoming[5];
    int outgoing[5];
    int numRoads;
    int connection;
} intersection;

intersection int1 = {.incoming = {1, 4, 25, 32}, .outgoing = {2, 3, 26, 31}, .numRoads = 4, .connection = 2};
intersection int2 = {.incoming = {35, 19, 26}, .outgoing = {36, 20, 25}, .numRoads = 3, .connection = 0};
intersection int3 = {.incoming = {36, 24, 21}, .outgoing = {35, 23, 22}, .numRoads = 3, .connection = 2};
intersection int4 = {.incoming = {17, 20, 22}, .outgoing = {18, 19, 21}, .numRoads = 3, .connection = 0};
intersection int5 = {.incoming = {18, 16, 13, 9}, .outgoing = {17, 15, 14, 10}, .numRoads = 4, .connection = 2};
intersection int6 = {.incoming = {5, 11, 14}, .outgoing = {6, 12, 13}, .numRoads = 3, .connection = 0};
intersection int7 = {.incoming = {6, 3, 7}, .outgoing = {5, 4, 8}, .numRoads = 3, .connection = 1};

int storage[] = {0, 0, 0, 0, 0, 0, 0};

/* Translates enum values into changes in roadsArray[] based on which intersection is calling it. Based on an
 * illustration in which all intersections have been numbered and all roads have been numbered and named (A,B,C,D) */

void convertLettersToRoadNames (intersection intersect) {
    for (int i = 0; i < 4; i++) {
        if (isValidRoad (outgoingRoads[i])) {
            roadsArray[intersect.outgoing[i]] = 1;
        }
    }
    return;
}

void printSolution () {
    for (int i = 0; i < 7; i++) {
        printf ("%i", storage[i]);
    }
    puts (" ");
    return;
}

int optionNumber (intersection i) {
    switch (i.numRoads) {
        case 3:
            return 7;
        case 4:
            return 9;
        default :
            return 0;
    }
}

intersection convertIntToIntersection (int i) {
    switch (i) {
        case 1:
            return int1;
        case 2:
            return int2;
        case 3:
            return int3;
        case 4:
            return int4;
        case 5:
            return int5;
        case 6:
            return int6;
        case 7:
            return int7;
        default :
            return int1;
    }
}


/* Depending on what road connects a specified intersection to it's predecessor, this method executes the appropriate
 * traffic flow method call */
void callMethodFromEnum (intersection i, int option) {
    if (i.numRoads == 3 && roadsArray[i.incoming[i.connection]] != 0) {
        switch (i.connection) {
            case 0:
                threeWayIntersection (ROAD, NO_ROAD, NO_ROAD, option);
                return;
            case 1:
                threeWayIntersection (NO_ROAD, ROAD, NO_ROAD, option);
                return;
            case 2:
                threeWayIntersection (NO_ROAD, NO_ROAD, ROAD, option);
                return;
            default:
                threeWayIntersection (NO_ROAD, NO_ROAD, NO_ROAD, option);

        }
    }
    if (i.numRoads == 4 && roadsArray[i.incoming[i.connection]] != 0) {
        switch (i.connection) {
            case 0:
                fourWayIntersection (ROAD, NO_ROAD, NO_ROAD, NO_ROAD, option);
                return;
            case 1:
                fourWayIntersection (NO_ROAD, ROAD, NO_ROAD, NO_ROAD, option);
                return;
            case 2:
                fourWayIntersection (NO_ROAD, NO_ROAD, ROAD, NO_ROAD, option);
                return;
            default :
                fourWayIntersection (NO_ROAD, NO_ROAD, NO_ROAD, NO_ROAD, option);
        }
    }
}