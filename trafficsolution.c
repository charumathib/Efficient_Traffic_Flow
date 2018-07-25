//
// Created by Charumathi Badrinath on 7/23/18.
//


#include <stdio.h>
#include "trafficsolution.h"

//creates an enum with up to 4 usable road names
typedef struct intersection{
    int incoming[5]; //maximum of 4 roads will be going into each intersection
    int outgoing[5]; //maximum of 4 roads will be exiting each intersection
    int numRoads; //stores the number of roads that connect at the intersection
}intersection;

int conflicts = 0; //measures the number of times cars have to cross paths

road outgoingRoads[5]; //a temporary array that the threeWayIntersection() and fourWayIntersection() methods will be working on

short roadsArray[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //initializes all 38 roads to 0 at the start of the program


//the outgoingRoads array is cleared immediately after the corresponding values are stored in roadsArray
//the conflicts counter is reset after every completed DFS of the implicit tree and the conflict number for that round
//is stored

void convertLettersToRoadNames(intersection i){
    if(outgoingRoads[0] == A)
        roadsArray[i.outgoing[0]] = 1;
    if(outgoingRoads[1] == B)
        roadsArray[i.outgoing[1]] = 1;
    if(outgoingRoads[2] == C)
        roadsArray[i.outgoing[2]] = 1;
    if(outgoingRoads[3] == D)
        roadsArray[i.outgoing[3]] = 1;
    clearOutgoingRoads();
    return;
}

int main(){
    intersection int1 = {.incoming = {4, 29, 33, 1}, .outgoing = {3, 30, 34, 2}, .numRoads = 4}; //roads are arranged in the order A, B, C, D
    intersection int2 = {.incoming = {27, 32, 34}, .outgoing = {28, 31, 33}, .numRoads = 3};
    intersection int3 = {.incoming = {28, 30, 25}, .outgoing = {27, 29, 26}, .numRoads = 3};
    intersection int4 = {.incoming = {35, 19, 26}, .outgoing = {36, 20, 25}, .numRoads = 3};
    intersection int5 = {.incoming = {36, 24, 21}, .outgoing = {35, 22, 23}, .numRoads = 3};
    intersection int6 = {.incoming = {17, 20, 22}, .outgoing = {18, 19, 21}, .numRoads = 3};
    intersection int7 = {.incoming = {18, 16, 13, 9}, .outgoing = {17, 15, 14, 10}, .numRoads = 4};
    intersection int8 = {.incoming = {12, 5, 14}, .outgoing = {11, 6, 13}, .numRoads = 3 };
    intersection int9 = {.incoming = {3, 6, 7}, .outgoing = {4, 5, 8}, .numRoads = 3};
    intersection intersections[] = {int1, int2, int3, int4, int5, int6, int7, int8, int9};
    return 0;
}

void clearOutgoingRoads() {
    for (int i = 0; i < sizeof (outgoingRoads); i++) {
        outgoingRoads[i] = NO_ROAD;
    }
}

void threeWayIntersection(road a, road b, road c, short option){
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

void fourWayIntersection(road a, road b, road c, road d, short option){
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

void threeWayOption1(road a, road b, road c) {
    if (c == C && b == B && a == A)
        threeWayConflicts (2);
    else {
        if (a == A)
            outgoingRoads[1] = B;
        if (b == B) {
            outgoingRoads[0] = A;
            outgoingRoads[2] = C;
        }
        if (c == C && b!= B && a!= A){
            outgoingRoads[1] = B;
            outgoingRoads[0] = A;
        } else if (c == C && a == A){
            outgoingRoads[0] = A;
            conflicts++;
        } else conflicts++;

    }
    return;
}

void threeWayOption2(road a, road b, road c) {
    if (c == C && b == B && a == A)
        threeWayConflicts (2);
    else {
        if (c == C)
            outgoingRoads[0] = A;
        if (a == A) {
            outgoingRoads[2] = C;
            outgoingRoads[1] = B;
        }
        if (b == B && a!= A && c!= C){
            outgoingRoads[0] = A;
            outgoingRoads[2] = C;
        } else if (b == B && c == C){
            outgoingRoads[2] = C;
            conflicts++;
        } else conflicts++;
    }
    return;
}

void threeWayOption3(road a, road b, road c) {
    if (c == C && b == B && a == A)
        threeWayConflicts (2);
    else {
        if (b == B)
            outgoingRoads[2] = C;
        if (c == C) {
            outgoingRoads[1] = B;
            outgoingRoads[0] = A;
        }
        if ( c == C && b!= B && a!= A){
            outgoingRoads[1] = B;
            outgoingRoads[0] = A;
        } else if (c == C && b == B){
            outgoingRoads[1] = B;
            conflicts++;
        } else conflicts++;

    }
    return;
}

void threeWayOption4(road a, road b, road c){
    if(c == C && b == B && a == A)
        threeWayConflicts(1);
    else {
        if(b == B)
            outgoingRoads[2] = C;
        if(c == C)
            outgoingRoads[0] = A;
        if(a == A && b == B){
            outgoingRoads[1] = B;
            conflicts++;
        } else if(a == A){
            outgoingRoads[1] = B;
            outgoingRoads[2] = C;
        }
    }
    return;
}

void threeWayOption5(road a, road b, road c){
    if(c == C && b == B && a == A)
        threeWayConflicts(1);
    else {
        if(b == B)
            outgoingRoads[2] = C;
        if(a == A)
            outgoingRoads[1] = B;
        if(c == C && a == A){
            outgoingRoads[0] = A;
            conflicts++;
        } else if(c == C){
            outgoingRoads[0] = A;
            outgoingRoads[1] = B;
        }
    }
    return;
}

void threeWayOption6(road a, road b, road c){
    if(c == C && b == B && a == A)
        threeWayConflicts(1);
    else {
        if(a == A)
            outgoingRoads[1] = B;
        if(c == C)
            outgoingRoads[0] = A;
        if(b == B && c == C){
            outgoingRoads[2] = C;
            conflicts++;
        } else if(b == B){
            outgoingRoads[0] = A;
            outgoingRoads[2] = C;
        }
    }
    return;
}

void threeWayOption7(road a, road b, road c){
    if(a == A)
        outgoingRoads[1] = B;
    if(b == B)
        outgoingRoads[2] = C;
    if(c == C)
        outgoingRoads[0] = A;
    return;
}

void fourWayOption1(road a, road b, road c, road d){
    if(a == A)
        outgoingRoads[1] = B;
    if(b == B)
        outgoingRoads[2] = C;
    if(c == C)
        outgoingRoads[3] = D;
    if(d == D)
        outgoingRoads[0] = A;
    return;
}

void fourWayOption2(road a, road b, road c, road d){
    if(a == A)
        outgoingRoads[1] = B;
    if(c == C)
        outgoingRoads[3] = D;
    if(d == D)
        outgoingRoads[0] = A;
    if(b == B && d == D){
        outgoingRoads[2] = C;
        conflicts++;
    } else if(b == B) {
        outgoingRoads[0] = A;
        outgoingRoads[2] = C;
    }
    return;
}

void fourWayOption3(road a, road b, road c, road d){//NOT DONE
    if(a == A)
        outgoingRoads[1] = B;
    if(b == B)
        outgoingRoads[2] = C;
    if(d == D)
        outgoingRoads[0] = A;
    if(c == C && a == A){
        outgoingRoads[3] = D;
        conflicts++;
    } else if(b == B) {
        outgoingRoads[1] = B;
        outgoingRoads[3] = D;
    }
    return;
}

void fourWayOption4(road a, road b, road c, road d){
    if(b == B)
        outgoingRoads[2] = C;
    if(c == C)
        outgoingRoads[3] = D;
    if(d == D)
        outgoingRoads[0] = A;
    if(a == A && b == B){
        outgoingRoads[1] = B;
        conflicts++;
    } else if(a == A) {
        outgoingRoads[1] = B;
        outgoingRoads[2] = C;
    }
    return;
}

void fourWayOption5(road a, road b, road c, road d){
    if(a == A)
        outgoingRoads[1] = B;
    if(c == C)
        outgoingRoads[3] = D;
    if(d == D)
        outgoingRoads[0] = A;
    if(b == B && c == C){
        outgoingRoads[2] = C;
        conflicts++;
    } else if(b == B) {
        outgoingRoads[3] = D;
        outgoingRoads[2] = C;
    }
    return;
}

void fourWayOption6(road a, road b, road c, road d){
    if(a == A)
        outgoingRoads[1] = B;
    if(b == B)
        outgoingRoads[2] = C;
    if(d == D)
        outgoingRoads[0] = A;
    if(c == B && d == D){
        outgoingRoads[3] = D;
        conflicts++;
    } else if(b == B) {
        outgoingRoads[0] = A;
        outgoingRoads[3] = D;
    }
    return;
}

void fourWayOption7(road a, road b, road c, road d){
    if(a == A)
        outgoingRoads[1] = B;
    if(c == C)
        outgoingRoads[3] = D;
    if(b == B)
        outgoingRoads[2] = C;
    if(d == D && a == A){
        outgoingRoads[0] = A;
        conflicts++;
    } else if(b == B) {
        outgoingRoads[1] = B;
        outgoingRoads[0] = A;
    }
    return;
}

void fourWayOption8(road a, road b, road c, road d){
    if(b == B)
        outgoingRoads[2] = C;
    if(c == C)
        outgoingRoads[3] = D;
    if(d == D)
        outgoingRoads[0] = A;
    if(a == A && c == C){
        outgoingRoads[1] = B;
        conflicts++;
    } else if(b == B) {
        outgoingRoads[3] = D;
        outgoingRoads[1] = B;
    }
    return;
}

void fourWayOption9(road a, road b, road c, road d) {
    if (a == A)
        outgoingRoads[1] = B;
    if (c == C)
        outgoingRoads[3] = D;
    if (b == B)
        outgoingRoads[2] = C;
    if (d == D && b == B) {
        outgoingRoads[0] = A;
        conflicts++;
    } else if (b == B) {
        outgoingRoads[2] = C;
        outgoingRoads[0] = A;
    }
    return;
}