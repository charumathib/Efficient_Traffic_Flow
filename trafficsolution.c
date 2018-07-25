//
// Created by Charumathi Badrinath on 7/23/18.
//


#include <stdio.h>
#include "trafficsolution.h"

//creates an enum with up to 4 usable road names

int conflicts = 0; //measures the number of times cars have to cross paths

road outgoingRoads[5]; //a temporary array that the twoWayIntersection() method will be working on

typedef struct intersection{
    int incoming[5]; //maximum of 4 roads will be going into each intersection
    int outgoing[5]; //maximum of 4 roads will be exiting each intersection
    int numRoads; //stores the number of roads that connect at the intersection
}intersection;

short roadsArray[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //initializes all 38 roads to 0 at the start of the program

int main(){
    initializeVertices();
    return 0;
}

//the outgoingRoads array is cleared immediately after the corresponding values are stored in roadsArray
//the conflicts counter is reset after every completed DFS of the implicit tree and the conflict number for that round
//is stored
//add enums

void initializeVertices(){
    intersection int1 = {.incoming = {2, 29, 4, 33}, .outgoing = {30, 3, 2, 34}, .numRoads = 4};
    intersection int2 = {.incoming = {32, 27, 34}, .outgoing = {28, 31, 33}, .numRoads = 3};
    intersection int3 = {.incoming = {28, 25, 30}, .outgoing = {29, 26, 27}, .numRoads = 3};
    intersection int4 = {.incoming = {26, 35, 19}, .outgoing = {36, 20, 25}, .numRoads = 3};
    intersection int5 = {.incoming = {24, 21, 36}, .outgoing = {22, 23, 35}, .numRoads = 3};
    intersection int6 = {.incoming = {22, 20, 17}, .outgoing = {21, 19, 18}, .numRoads = 3};
    intersection int7 = {.incoming = {18, 38, 13, 16}, .outgoing = {15, 17, 14, 37}, .numRoads = 4};
    intersection int8 = {.incoming = {10, 12, 5}, .outgoing = {11, 9, 6}, .numRoads = 3 };
    intersection int9 = {.incoming = {6, 7, 3}, .outgoing = {4, 8, 5}, .numRoads = 3};
}

void threeWayIntersection(enum road a, enum road b, enum road c, short option){
    switch (option){
        case 1:
            threeWayOption1(a, b, c);
            break;
        case 2:
            threeWayOption2(a, b, c);
            break;
        case 3:
            threeWayOption3(a, b, c);
            break;
        case 4:
            threeWayOption4(a, b, c);
            break;
        case 5:
            threeWayOption5(a, b, c);
            break;
        case 6:
            threeWayOption6(a, b, c);
            break;
        case 7:
            threeWayOption7(a, b, c);
            break;
        default : return;
    }
}

void fourWayIntersection(enum road a, enum road b, enum road c, enum road d, short option){
    switch(option){
        case 1:
            fourWayOption1(a, b, c, d);
            break;
        case 2:
            fourWayOption2(a, b, c, d);
            break;
        case 3:
            fourWayOption3(a, b, c, d);
            break;
        case 4:
            fourWayOption4(a, b, c, d);
            break;
        case 5:
            fourWayOption5(a, b, c, d);
            break;
        case 6:
            fourWayOption6(a, b, c, d);
            break;
        case 7:
            fourWayOption7(a, b, c, d);
            break;
        case 8:
            fourWayOption8(a, b, c, d);
            break;
        case 9:
            fourWayOption9(a, b, c, d);
            break;
        default : return;
    }
}

void threeWayConflicts(int num){
    outgoingRoads[0] = A;
    outgoingRoads[1] = B;
    outgoingRoads[2] = C;
    conflicts += num;
}

void threeWayOption1(enum road a, enum road b, enum road c) {
    if (c == C && b == B && a == A)
        threeWayConflicts (2);
    else {
        if (a == A)
            outgoingRoads[0] = B;
        if (b == B) {
            outgoingRoads[1] = A;
            outgoingRoads[2] = C;
        }
        if (c == C && b!= B && a!= A){
            outgoingRoads[0] = B;
            outgoingRoads[1] = A;
        } else if (c == C && a == A){
            outgoingRoads[1] = A;
            conflicts++;
        } else conflicts++;

    }
    return;
}

void threeWayOption2(enum road a, enum road b, enum road c) {
    if (c == C && b == B && a == A)
        threeWayConflicts (2);
    else {
        if (c == C)
            outgoingRoads[0] = A;
        if (a == A) {
            outgoingRoads[1] = C;
            outgoingRoads[2] = B;
        }
        if (b == B && a!= A && c!= C){
            outgoingRoads[0] = A;
            outgoingRoads[1] = C;
        } else if (b == B && c == C){
            outgoingRoads[1] = C;
            conflicts++;
        } else conflicts++;
    }
    return;
}

void threeWayOption3(enum road a, enum road b, enum road c) {
    if (c == C && b == B && a == A)
        threeWayConflicts (2);
    else {
        if (b == B)
            outgoingRoads[0] = C;
        if (c == C) {
            outgoingRoads[1] = B;
            outgoingRoads[2] = A;
        }
        if ( c == C && b!= B && a!= A){
            outgoingRoads[1] = B;
            outgoingRoads[2] = A;
        } else if (c == C && b == B){
            outgoingRoads[1] = B;
            conflicts++;
        } else conflicts++;

    }
    return;
}

void threeWayOption4(enum road a, enum road b, enum road c){
    if(c == C && b == B && a == A)
        threeWayConflicts(1);
    else {
        if(b == B)
            outgoingRoads[0] = C;
        if(c == C)
            outgoingRoads[1] = A;
        if(a == A && b == B){
            outgoingRoads[2] = B;
            conflicts++;
        } else if(a == A){
            outgoingRoads[2] = B;
            outgoingRoads[0] = C;
        }
    }
    return;
}

void threeWayOption5(enum road a, enum road b, enum road c){
    if(c == C && b == B && a == A)
        threeWayConflicts(1);
    else {
        if(b == B)
            outgoingRoads[0] = C;
        if(a == A)
            outgoingRoads[1] = B;
        if(c == C && a == A){
            outgoingRoads[2] = A;
            conflicts++;
        } else if(c == C){
            outgoingRoads[2] = A;
            outgoingRoads[1] = B;
        }
    }
    return;
}

void threeWayOption6(enum road a, enum road b, enum road c){
    if(c == C && b == B && a == A)
        threeWayConflicts(1);
    else {
        if(a == A)
            outgoingRoads[0] = B;
        if(c == C)
            outgoingRoads[1] = A;
        if(b == B && c == C){
            outgoingRoads[2] = C;
            conflicts++;
        } else if(b == B){
            outgoingRoads[1] = A;
            outgoingRoads[2] = C;
        }
    }
    return;
}

void threeWayOption7(enum road a, enum road b, enum road c){
    if(a == A)
        outgoingRoads[0] = B;
    if(b == B)
        outgoingRoads[1] = C;
    if(c == C)
        outgoingRoads[2] = A;
    return;
}

void fourWayOption1(enum road a, enum road b, enum road c, enum road d){
    if(a == A)
        outgoingRoads[0] = B;
    if(b == B)
        outgoingRoads[1] = C;
    if(c == C)
        outgoingRoads[2] = D;
    if(d == D)
        outgoingRoads[3] = A;
    return;
}

void fourWayOption2(enum road a, enum road b, enum road c, enum road d){
    if(a == A)
        outgoingRoads[0] = B;
    if(c == C)
        outgoingRoads[2] = D;
    if(d == D)
        outgoingRoads[3] = A;
    if(b == B && d == D){
        outgoingRoads[1] = C;
        conflicts++;
    } else if(b == B) {
        outgoingRoads[3] = A;
        outgoingRoads[1] = C;
    }
    return;
}

void fourWayOption3(enum road a, enum road b, enum road c, enum road d){//NOT DONE
    if(a == A)
        outgoingRoads[0] = B;
    if(b == B)
        outgoingRoads[2] = C;
    if(d == D)
        outgoingRoads[3] = A;
    if(c == C && a == A){
        outgoingRoads[1] = D;
        conflicts++;
    } else if(b == B) {
        outgoingRoads[0] = B;
        outgoingRoads[1] = D;
    }
    return;
}

void fourWayOption4(enum road a, enum road b, enum road c, enum road d){
    if(b == B)
        outgoingRoads[0] = C;
    if(c == C)
        outgoingRoads[2] = D;
    if(d == D)
        outgoingRoads[3] = A;
    if(a == A && b == B){
        outgoingRoads[1] = B;
        conflicts++;
    } else if(a == A) {
        outgoingRoads[1] = B;
        outgoingRoads[0] = C;
    }
    return;
}



void fourWayOption5(enum road a, enum road b, enum road c, enum road d){
    if(a == A)
        outgoingRoads[0] = B;
    if(c == C)
        outgoingRoads[2] = D;
    if(d == D)
        outgoingRoads[3] = A;
    if(b == B && c == C){
        outgoingRoads[1] = C;
        conflicts++;
    } else if(b == B) {
        outgoingRoads[2] = D;
        outgoingRoads[1] = C;
    }
    return;
}

void fourWayOption6(enum road a, enum road b, enum road c, enum road d){
    if(a == A)
        outgoingRoads[0] = B;
    if(b == B)
        outgoingRoads[2] = C;
    if(d == D)
        outgoingRoads[3] = A;
    if(c == B && d == D){
        outgoingRoads[1] = D;
        conflicts++;
    } else if(b == B) {
        outgoingRoads[3] = A;
        outgoingRoads[1] = D;
    }
    return;
}

void fourWayOption7(enum road a, enum road b, enum road c, enum road d){
    if(a == A)
        outgoingRoads[0] = B;
    if(c == C)
        outgoingRoads[2] = D;
    if(b == B)
        outgoingRoads[3] = C;
    if(d == D && a == A){
        outgoingRoads[1] = A;
        conflicts++;
    } else if(b == B) {
        outgoingRoads[0] = B;
        outgoingRoads[1] = A;
    }
    return;
}

void fourWayOption8(enum road a, enum road b, enum road c, enum road d){
    if(b == B)
        outgoingRoads[0] = C;
    if(c == C)
        outgoingRoads[2] = D;
    if(d == D)
        outgoingRoads[3] = A;
    if(a == A && c == C){
        outgoingRoads[1] = B;
        conflicts++;
    } else if(b == B) {
        outgoingRoads[2] = D;
        outgoingRoads[1] = B;
    }
    return;
}

void fourWayOption9(enum road a, enum road b, enum road c, enum road d){
    if(a == A)
        outgoingRoads[0] = B;
    if(c == C)
        outgoingRoads[2] = D;
    if(b == B)
        outgoingRoads[3] = C;
    if(d == D && b == B){
        outgoingRoads[1] = A;
        conflicts++;
    } else if(b == B) {
        outgoingRoads[3] = C;
        outgoingRoads[1] = A;
    }
    return;
}






