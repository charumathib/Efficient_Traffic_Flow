//
// Created by Charumathi Badrinath on 7/30/18.
//

#include <stdio.h>
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
    threeWayIntersection (A, B, C, storage[6]);
    threeWayIntersection (A, B, C, storage[5]);
    fourWayIntersection (A, B, C, D, storage[4]);
    threeWayIntersection (A, B, C, storage[3]);
    threeWayIntersection (A, B, C, storage[2]);
    threeWayIntersection (A, B, C, storage[1]);
    fourWayIntersection (A, B, C, D, storage[0]);
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

/* When all three entered roads have a value other than NO_ROAD, this method modifies the outgoingRoads[] array with
 * the appropriate values and increments the conflicts counter by a specified amount depending on the method from which
 * it is called */
void threeWayConflicts (int num) {
    outgoingRoads[0] = A;
    outgoingRoads[1] = B;
    outgoingRoads[2] = C;
    conflicts += num;
}


//test all of these methods


/* Represents the road connections : A-B, B-A, B-C, C-B, and C-A. A-C is left unconnected */

void threeWayOption1 (road a, road b, road c) { //FUNCTIONAL
    if (c == C && b == B && a == A)
        threeWayConflicts (2);
    else {
        if (a == A)
            outgoingRoads[1] = B;
        if (b == B) {
            outgoingRoads[0] = A;
            outgoingRoads[2] = C;
        }
        if (c == C && b != B && a != A) {
            outgoingRoads[1] = B;
            outgoingRoads[0] = A;
        } else if (c == C && a == A) {
            outgoingRoads[0] = A;
            conflicts++;
        } else if (c == C && b == B) {
            outgoingRoads[1] = B;
            conflicts++;
        }
    }
    return;
}

/* Represents the road connections : A-B, B-A, A-C, C-A, and B-C. C-B is left unconnected */
void threeWayOption2 (road a, road b, road c) { //FUNCTIONAL
    if (c == C && b == B && a == A)
        threeWayConflicts (2);
    else {
        if (c == C)
            outgoingRoads[0] = A;
        if (a == A) {
            outgoingRoads[2] = C;
            outgoingRoads[1] = B;
        }
        if (b == B && a != A && c != C) {
            outgoingRoads[0] = A;
            outgoingRoads[2] = C;
        } else if (b == B && c == C) {
            outgoingRoads[2] = C;
            conflicts++;
        } else if (b == B && a == A) {
            outgoingRoads[0] = A;
            conflicts++;
        }
    }
    return;
}

/* Represents the road connections : A-B, A-C, C-A, B-C, and C-B. B-A is left unconnected */
void threeWayOption3 (road a, road b, road c) { //FUNCTIONAL
    if (c == C && b == B && a == A)
        threeWayConflicts (2);
    else {
        if (b == B)
            outgoingRoads[2] = C;
        if (a == A) {
            outgoingRoads[1] = B;
            outgoingRoads[2] = C;
        }
        if (c == C && b != B && a != A) {
            outgoingRoads[1] = B;
            outgoingRoads[0] = A;
        } else if (c == C && b == B) {
            outgoingRoads[1] = B;
            conflicts++;
        } else if (c == C && a == A) {
            outgoingRoads[0] = A;
            conflicts++;
        }

    }
    return;
}

/* Represents the road connections : A-B, B-C, A-C, and C-A. C-B and B-A are left unconnected */
void threeWayOption4 (road a, road b, road c) { //FUNCTIONAL
    if (c == C && b == B && a == A)
        threeWayConflicts (1);
    else {
        if (b == B)
            outgoingRoads[2] = C;
        if (c == C)
            outgoingRoads[0] = A;
        if (a == A && b == B) {
            outgoingRoads[1] = B;
            conflicts++;
        } else if (a == A) {
            outgoingRoads[1] = B;
            outgoingRoads[2] = C;
        }
    }
    return;
}

/* Represents the road connections : A-B, C-B, C-A, and B-C. B-A and A-C are left unconnected */
void threeWayOption5 (road a, road b, road c) { //FUNCTIONAL
    if (c == C && b == B && a == A)
        threeWayConflicts (1);
    else {
        if (b == B)
            outgoingRoads[2] = C;
        if (a == A)
            outgoingRoads[1] = B;
        if (c == C && a == A) {
            outgoingRoads[0] = A;
            conflicts++;
        } else if (c == C && b == B) {
            outgoingRoads[1] = B;
        } else if (c == C && a != A && b != B) {
            outgoingRoads[0] = A;
            outgoingRoads[1] = B;
        }
    }
    return;
}

/* Represents the road connections : A-B, B-C, B-A, and C-A. C-B and A-C are left unconnected */
void threeWayOption6 (road a, road b, road c) { //FUNCTIONAL
    if (c == C && b == B && a == A)
        threeWayConflicts (1);
    else {
        if (a == A)
            outgoingRoads[1] = B;
        if (c == C)
            outgoingRoads[0] = A;
        if (b == B && c == C) {
            outgoingRoads[2] = C;
            conflicts++;
        } else if (b == B && a == A) {
            outgoingRoads[0] = A;
        } else if (b == B && c != C && a != A) {
            outgoingRoads[0] = A;
            outgoingRoads[2] = C;
        }
    }
    return;
}

/* Represents the road connections : A-B, B-C, and C-A. C-B, A-C and B-A are left unconnected */
void threeWayOption7 (road a, road b, road c) { //FUNCTIONAL
    if (a == A)
        outgoingRoads[1] = B;
    if (b == B)
        outgoingRoads[2] = C;
    if (c == C)
        outgoingRoads[0] = A;
    return;
}

/* Represents the road connections : B-C, C-D, D-A, and A-B. B-A, C-B, A-C, B-D, C-A, D-B, A-D, and DC are left
 * unconnected */
void fourWayOption1 (road a, road b, road c, road d) { //FUNCTIONAL
    if (a == A)
        outgoingRoads[1] = B;
    if (b == B)
        outgoingRoads[2] = C;
    if (c == C)
        outgoingRoads[3] = D;
    if (d == D)
        outgoingRoads[0] = A;
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B and B-A. C-B, A-C, B-D, C-A, D-B, A-D, and D-C are left
 * unconnected */
void fourWayOption2 (road a, road b, road c, road d) { //FUNCTIONAL (2B)
    if (a == A)
        outgoingRoads[1] = B;
    if (c == C)
        outgoingRoads[3] = D;
    if (d == D)
        outgoingRoads[0] = A;
    if (b == B && d == D) {
        outgoingRoads[2] = C;
        conflicts++;
    } else if (b == B) {
        outgoingRoads[0] = A;
        outgoingRoads[2] = C;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and C-B. A-C, B-D, C-A, D-B, A-D, D-C, and B-A are left
 * unconnected */
void fourWayOption3 (road a, road b, road c, road d) {//FUNCTIONAL (2C)
    if (a == A)
        outgoingRoads[1] = B;
    if (b == B)
        outgoingRoads[2] = C;
    if (d == D)
        outgoingRoads[0] = A;
    if (c == C && a == A) {
        outgoingRoads[3] = D;
        conflicts++;
    } else if (c == C) {
        outgoingRoads[1] = B;
        outgoingRoads[3] = D;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and A-C. B-A, C-B, B-D, C-A, D-B, A-D, and D-C are left
 * unconnected */
void fourWayOption4 (road a, road b, road c, road d) {//FUNCTIONAL (2A)
    if (b == B)
        outgoingRoads[2] = C;
    if (c == C)
        outgoingRoads[3] = D;
    if (d == D)
        outgoingRoads[0] = A;
    if (a == A && b == B) {
        outgoingRoads[1] = B;
        conflicts++;
    } else if (a == A) {
        outgoingRoads[1] = B;
        outgoingRoads[2] = C;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and B-D. A-C, C-A, D-B, A-D, D-C, B-A, and C-B are left
 * unconnected */
void fourWayOption5 (road a, road b, road c, road d) {//FUNCTIONAL (2B)
    if (a == A)
        outgoingRoads[1] = B;
    if (c == C)
        outgoingRoads[3] = D;
    if (d == D)
        outgoingRoads[0] = A;
    if (b == B && c == C) {
        outgoingRoads[2] = C;
        conflicts++;
    } else if (b == B) {
        outgoingRoads[3] = D;
        outgoingRoads[2] = C;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and C-A. B-A, C-B, A-C, B-D, D-B, A-D, and D-C are left
 * unconnected */
void fourWayOption6 (road a, road b, road c, road d) {//FUNCTIONAL (2C)
    if (a == A)
        outgoingRoads[1] = B;
    if (b == B)
        outgoingRoads[2] = C;
    if (d == D)
        outgoingRoads[0] = A;
    if (c == C && d == D) {
        outgoingRoads[3] = D;
        conflicts++;
    } else if (c == C) {
        outgoingRoads[0] = A;
        outgoingRoads[3] = D;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and D-B. B-A, C-B, A-C, B-D, C-A, A-D, and D-C are left
 * unconnected */
void fourWayOption7 (road a, road b, road c, road d) {//FUNCTIONAL (2D)
    if (a == A)
        outgoingRoads[1] = B;
    if (c == C)
        outgoingRoads[3] = D;
    if (b == B)
        outgoingRoads[2] = C;
    if (d == D && a == A) {
        outgoingRoads[0] = A;
        conflicts++;
    } else if (d == D) {
        outgoingRoads[1] = B;
        outgoingRoads[0] = A;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and A-D. B-A, C-B, A-C, B-D, C-A, D-B, and D-C are left
 * unconnected */
void fourWayOption8 (road a, road b, road c, road d) {//FUNCTIONAL (2A)
    if (b == B)
        outgoingRoads[2] = C;
    if (c == C)
        outgoingRoads[3] = D;
    if (d == D)
        outgoingRoads[0] = A;
    if (a == A && c == C) {
        outgoingRoads[1] = B;
        conflicts++;
    } else if (a == A) {
        outgoingRoads[3] = D;
        outgoingRoads[1] = B;
    }
    return;
}

/* Represents the road connections : B-C, C-D, D-A, A-B, and D-C. B-A, C-B, A-C, B-D, C-A, D-B, and A-D are left
 * unconnected */
void fourWayOption9 (road a, road b, road c, road d) {//FUNCTIONAL (2D)
    if (a == A)
        outgoingRoads[1] = B;
    if (c == C)
        outgoingRoads[3] = D;
    if (b == B)
        outgoingRoads[2] = C;
    if (d == D && b == B) {
        outgoingRoads[0] = A;
        conflicts++;
    } else if (d == D) {
        outgoingRoads[2] = C;
        outgoingRoads[0] = A;
    }
    return;
}
