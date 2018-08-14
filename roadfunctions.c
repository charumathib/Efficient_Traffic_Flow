//
// Created by Charumathi Badrinath on 7/30/18.
//

#include <stdio.h>
#include <stdbool.h>
#include "initializations.c"

void clearRoadsArray () {
    for (int i = 0; i < 39; i++) {
        roadsArray[i] = 0;
    }
}

void clearOutgoingRoads () {
    for (int i = 0; i < 5; i++) {
        outgoingRoads[i] = NO_ROAD;
    }
}

int checkNumConflicts () {
    conflicts = 0;
    threeWayIntersection (ROAD, ROAD, ROAD, storage[6]);
    threeWayIntersection (ROAD, ROAD, ROAD, storage[5]);
    fourWayIntersection (ROAD, ROAD, ROAD, ROAD, storage[4]);
    threeWayIntersection (ROAD, ROAD, ROAD, storage[3]);
    threeWayIntersection (ROAD, ROAD, ROAD, storage[2]);
    threeWayIntersection (ROAD, ROAD, ROAD, storage[1]);
    fourWayIntersection (ROAD, ROAD, ROAD, ROAD, storage[0]);
    return conflicts;
}

/* Caller method which when given three road names and a traffic flow option, calls the corresponding method */
void threeWayIntersection (road a, road b, road c, int option) {
    clearOutgoingRoads ();
    switch (option) {
        case 1:
            threeWayOption1 (a, b, c);
            break;
        case 2:
            threeWayOption2 (a, b, c);
            break;
        case 3:
            threeWayOption3 (a, b, c);
            break;
        case 4:
            threeWayOption4 (a, b, c);
            break;
        case 5:
            threeWayOption5 (a, b, c);
            break;
        case 6:
            threeWayOption6 (a, b, c);
            break;
        case 7:
            threeWayOption7 (a, b, c);
            break;
        default :
            return;
    }
}

/* Caller method which when given four road names and a traffic flow option, calls the corresponding method */
void fourWayIntersection (road a, road b, road c, road d, int option) {
    clearOutgoingRoads ();
    switch (option) {
        case 1:
            fourWayOption1 (a, b, c, d);
            break;
        case 2:
            fourWayOption2 (a, b, c, d);
            break;
        case 3:
            fourWayOption3 (a, b, c, d);
            break;
        case 4:
            fourWayOption4 (a, b, c, d);
            break;
        case 5:
            fourWayOption5 (a, b, c, d);
            break;
        case 6:
            fourWayOption6 (a, b, c, d);
            break;
        case 7:
            fourWayOption7 (a, b, c, d);
            break;
        case 8:
            fourWayOption8 (a, b, c, d);
            break;
        case 9:
            fourWayOption9 (a, b, c, d);
            break;
        default :
            return;
    }
}

bool isValidRoad (road r) {
    return r != NO_ROAD;
}

/* When all three entered roads have a value other than NO_ROAD, this method modifies the outgoingRoads[] array with
 * the appropriate values and increments the conflicts counter by a specified amount depending on the method from which
 * it is called */
void threeWayConflicts (int num) {
    for (int i = 0; i < 3; i++) {
        outgoingRoads[i] = ROAD;
    }
    conflicts += num;
}


//test all of these methods


/* Represents the road connections : A-B, B-A, B-C, C-B, and C-A. A-C is left unconnected */

void threeWayOption1 (road a, road b, road c) {
    if (isValidRoad (a) && isValidRoad (b) && isValidRoad (c))
        threeWayConflicts (2);
    else {
        if (isValidRoad (a))
            outgoingRoads[1] = ROAD;
        if (isValidRoad (b)) {
            outgoingRoads[0] = ROAD;
            outgoingRoads[2] = ROAD;
        }
        if (isValidRoad (c) && !isValidRoad (b) && !isValidRoad (a)) {
            outgoingRoads[1] = ROAD;
            outgoingRoads[0] = ROAD;
        } else if (isValidRoad (c) && isValidRoad (a)) {
            outgoingRoads[0] = ROAD;
            conflicts++;
        } else if (isValidRoad (c) && isValidRoad (b)) {
            outgoingRoads[1] = ROAD;
            conflicts++;
        }
    }
    return;
}

/* Represents the road connections : A-B, B-A, A-C, C-A, and B-C. C-B is left unconnected */
void threeWayOption2 (road a, road b, road c) { //FUNCTIONAL
    if (isValidRoad (a) && isValidRoad (b) && isValidRoad (c))
        threeWayConflicts (2);
    else {
        if (isValidRoad (c))
            outgoingRoads[0] = ROAD;
        if (isValidRoad (a)) {
            outgoingRoads[2] = ROAD;
            outgoingRoads[1] = ROAD;
        }
        if (isValidRoad (b) && !isValidRoad (a) && !isValidRoad (c)) {
            outgoingRoads[0] = ROAD;
            outgoingRoads[2] = ROAD;
        } else if (isValidRoad (b) && isValidRoad (c)) {
            outgoingRoads[2] = ROAD;
            conflicts++;
        } else if (isValidRoad (b) && isValidRoad (a)) {
            outgoingRoads[0] = ROAD;
            conflicts++;
        }
    }
    return;
}


/* Represents the road connections : A-B, A-C, C-A, B-C, and C-B. B-A is left unconnected */
void threeWayOption3 (road a, road b, road c) { //FUNCTIONAL
    if (isValidRoad (a) && isValidRoad (b) && isValidRoad (c))
        threeWayConflicts (2);
    else {
        if (isValidRoad (b))
            outgoingRoads[2] = ROAD;
        if (isValidRoad (a)) {
            outgoingRoads[1] = ROAD;
            outgoingRoads[2] = ROAD;
        }
        if (isValidRoad (c) && isValidRoad (b) && isValidRoad (a)) {
            outgoingRoads[1] = ROAD;
            outgoingRoads[0] = ROAD;
        } else if (isValidRoad (c) && isValidRoad (b)) {
            outgoingRoads[1] = ROAD;
            conflicts++;
        } else if (isValidRoad (c) && isValidRoad (a)) {
            outgoingRoads[0] = ROAD;
            conflicts++;
        }

    }
    return;
}

/* Represents the road connections : A-B, B-C, A-C, and C-A. C-B and B-A are left unconnected */
void threeWayOption4 (road a, road b, road c) { //FUNCTIONAL
    if (isValidRoad (c) && isValidRoad (b) && isValidRoad (a))
        threeWayConflicts (1);
    else {
        if (isValidRoad (b))
            outgoingRoads[2] = ROAD;
        if (isValidRoad (c))
            outgoingRoads[0] = ROAD;
        if (isValidRoad (a) && isValidRoad (b)) {
            outgoingRoads[1] = ROAD;
            conflicts++;
        } else if (isValidRoad (a)) {
            outgoingRoads[1] = ROAD;
            outgoingRoads[2] = ROAD;
        }
    }
    return;
}

/* Represents the road connections : A-B, C-B, C-A, and B-C. B-A and A-C are left unconnected */
void threeWayOption5 (road a, road b, road c) { //FUNCTIONAL
    if (isValidRoad (c) && isValidRoad (b) && isValidRoad (a))
        threeWayConflicts (1);
    else {
        if (isValidRoad (b))
            outgoingRoads[2] = ROAD;
        if (isValidRoad (a))
            outgoingRoads[1] = ROAD;
        if (isValidRoad (c) && isValidRoad (a)) {
            outgoingRoads[0] = ROAD;
            conflicts++;
        } else if (isValidRoad (c) && isValidRoad (b)) {
            outgoingRoads[1] = ROAD;
        } else if (isValidRoad (c) && !isValidRoad (a) && !isValidRoad (b)) {
            outgoingRoads[0] = ROAD;
            outgoingRoads[1] = ROAD;
        }
    }
    return;
}

/* Represents the road connections : A-B, B-C, B-A, and C-A. C-B and A-C are left unconnected */
void threeWayOption6 (road a, road b, road c) { //FUNCTIONAL
    if (isValidRoad (c) && isValidRoad (b) && isValidRoad (a))
        threeWayConflicts (1);
    else {
        if (isValidRoad (a))
            outgoingRoads[1] = ROAD;
        if (isValidRoad (c))
            outgoingRoads[0] = ROAD;
        if (isValidRoad (b) && isValidRoad (c)) {
            outgoingRoads[2] = ROAD;
            conflicts++;
        } else if (isValidRoad (b) && isValidRoad (a)) {
            outgoingRoads[0] = ROAD;
        } else if (isValidRoad (b) && !isValidRoad (c) && !isValidRoad (a)) {
            outgoingRoads[0] = ROAD;
            outgoingRoads[2] = ROAD;
        }
    }
    return;
}

/* Represents the road connections : A-B, B-C, and C-A. C-B, A-C and B-A are left unconnected
 * This is a NO CONFLICT scenario
 **/
void threeWayOption7 (road a, road b, road c) { //FUNCTIONAL
    if (isValidRoad (a))
        outgoingRoads[1] = ROAD;
    if (isValidRoad (b))
        outgoingRoads[2] = ROAD;
    if (isValidRoad (c))
        outgoingRoads[0] = ROAD;
    return;
}

/* Represents the road connections : B-C, C-D, D-A, and A-B. B-A, C-B, A-C, B-D, C-A, D-B, A-D, and DC are left
 * unconnected */
void fourWayOption1 (road a, road b, road c, road d) { //FUNCTIONAL
    if (isValidRoad (a))
        outgoingRoads[1] = ROAD;
    if (isValidRoad (b))
        outgoingRoads[2] = ROAD;
    if (isValidRoad (c))
        outgoingRoads[3] = ROAD;
    if (isValidRoad (d))
        outgoingRoads[0] = ROAD;
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B and B-A. C-B, A-C, B-D, C-A, D-B, A-D, and D-C are left
 * unconnected */
void fourWayOption2 (road a, road b, road c, road d) { //FUNCTIONAL (2B)
    if (isValidRoad (a))
        outgoingRoads[1] = ROAD;
    if (isValidRoad (c))
        outgoingRoads[3] = ROAD;
    if (isValidRoad (d))
        outgoingRoads[0] = ROAD;
    if (isValidRoad (b) && isValidRoad (d)) {
        outgoingRoads[2] = ROAD;
        conflicts++;
    } else if (isValidRoad (b)) {
        outgoingRoads[0] = ROAD;
        outgoingRoads[2] = ROAD;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and C-B. A-C, B-D, C-A, D-B, A-D, D-C, and B-A are left
 * unconnected */
void fourWayOption3 (road a, road b, road c, road d) {//FUNCTIONAL (2C)
    if (isValidRoad (a))
        outgoingRoads[1] = ROAD;
    if (isValidRoad (b))
        outgoingRoads[2] = ROAD;
    if (isValidRoad (d))
        outgoingRoads[0] = ROAD;
    if (isValidRoad (c) && isValidRoad (a)) {
        outgoingRoads[3] = ROAD;
        conflicts++;
    } else if (isValidRoad (c)) {
        outgoingRoads[1] = ROAD;
        outgoingRoads[3] = ROAD;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and A-C. B-A, C-B, B-D, C-A, D-B, A-D, and D-C are left
 * unconnected */
void fourWayOption4 (road a, road b, road c, road d) {//FUNCTIONAL (2A)
    if (isValidRoad (b))
        outgoingRoads[2] = ROAD;
    if (isValidRoad (c))
        outgoingRoads[3] = ROAD;
    if (isValidRoad (d))
        outgoingRoads[0] = ROAD;
    if (isValidRoad (a) && isValidRoad (b)) {
        outgoingRoads[1] = ROAD;
        conflicts++;
    } else if (isValidRoad (a)) {
        outgoingRoads[1] = ROAD;
        outgoingRoads[2] = ROAD;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and B-D. A-C, C-A, D-B, A-D, D-C, B-A, and C-B are left
 * unconnected */
void fourWayOption5 (road a, road b, road c, road d) {//FUNCTIONAL (2B)
    if (isValidRoad (a))
        outgoingRoads[1] = ROAD;
    if (isValidRoad (c))
        outgoingRoads[3] = ROAD;
    if (isValidRoad (d))
        outgoingRoads[0] = ROAD;
    if (isValidRoad (b) && isValidRoad (c)) {
        outgoingRoads[2] = ROAD;
        conflicts++;
    } else if (isValidRoad (b)) {
        outgoingRoads[3] = ROAD;
        outgoingRoads[2] = ROAD;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and C-A. B-A, C-B, A-C, B-D, D-B, A-D, and D-C are left
 * unconnected */
void fourWayOption6 (road a, road b, road c, road d) {//FUNCTIONAL (2C)
    if (isValidRoad (a))
        outgoingRoads[1] = ROAD;
    if (isValidRoad (b))
        outgoingRoads[2] = ROAD;
    if (isValidRoad (d))
        outgoingRoads[0] = ROAD;
    if (isValidRoad (c) && isValidRoad (d)) {
        outgoingRoads[3] = ROAD;
        conflicts++;
    } else if (isValidRoad (c)) {
        outgoingRoads[0] = ROAD;
        outgoingRoads[3] = ROAD;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and D-B. B-A, C-B, A-C, B-D, C-A, A-D, and D-C are left
 * unconnected */
void fourWayOption7 (road a, road b, road c, road d) {//FUNCTIONAL (2D)
    if (isValidRoad (a))
        outgoingRoads[1] = ROAD;
    if (isValidRoad (c))
        outgoingRoads[3] = ROAD;
    if (isValidRoad (b))
        outgoingRoads[2] = ROAD;
    if (isValidRoad (d) && isValidRoad (a)) {
        outgoingRoads[0] = ROAD;
        conflicts++;
    } else if (isValidRoad (d)) {
        outgoingRoads[1] = ROAD;
        outgoingRoads[0] = ROAD;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and A-D. B-A, C-B, A-C, B-D, C-A, D-B, and D-C are left
 * unconnected */
void fourWayOption8 (road a, road b, road c, road d) {//FUNCTIONAL (2A)
    if (isValidRoad (b))
        outgoingRoads[2] = ROAD;
    if (isValidRoad (c))
        outgoingRoads[3] = ROAD;
    if (isValidRoad (d))
        outgoingRoads[0] = ROAD;
    if (isValidRoad (a) && isValidRoad (c)) {
        outgoingRoads[1] = ROAD;
        conflicts++;
    } else if (isValidRoad (a)) {
        outgoingRoads[3] = ROAD;
        outgoingRoads[1] = ROAD;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and D-C. B-A, C-B, A-C, B-D, C-A, D-B, and A-D are left
 * unconnected */
void fourWayOption9 (road a, road b, road c, road d) {//FUNCTIONAL (2D)
    if (isValidRoad (a))
        outgoingRoads[1] = ROAD;
    if (isValidRoad (c))
        outgoingRoads[3] = ROAD;
    if (isValidRoad (b))
        outgoingRoads[2] = ROAD;
    if (isValidRoad (d) && isValidRoad (b)) {
        outgoingRoads[0] = ROAD;
        conflicts++;
    } else if (isValidRoad (d)) {
        outgoingRoads[2] = ROAD;
        outgoingRoads[0] = ROAD;
    }
    return;
}
