/* Created by Charumathi Badrinath */

#include <stdio.h>
#include "trafficsolution.h"

/* Defines the structure which represents road intersections. It consists of 3 fields, namely an array storing the
 * assigned numbers of incoming roads, another array storing the assigned numbers of outgoing roads, and an integer
 * which stores the overall number of roads that meet at the given intersection*/
typedef struct intersection{
    int incoming[5];
    int outgoing[5];
    int numRoads;
}intersection;

/* Counter variable which is incremented every time a given traffic flow causes cars to either merge or cross paths.
 * This counter is reset after every cycle of DFS through the implicit tree */
int conflicts = 0;

/* A temporary array that the threeWayIntersection() and fourWayIntersection() methods will be working on. It is
 * cleared by the clearRoads() function immediately after it's contents have been translated into roadsArray[]*/
road outgoingRoads[5];

/* Initializes the values of all 19 2-way roads (38 overall) to unused at the start of the program */
short roadsArray[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

/* Program driver */
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

/* Translates enum values into changes in roadsArray[] based on which intersection is calling it. Based on an
 * illustration in which all intersections have been numbered and all roads have been numbered and named (A,B,C,D) */
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

/* Utility function which sets all the values in outgoingRoads[] to NO_ROAD signifying a NULL value */
void clearOutgoingRoads() {
    for (int i = 0; i < sizeof (outgoingRoads); i++) {
        outgoingRoads[i] = NO_ROAD;
    }
}

/* Caller method which when given three road names and a traffic flow option, calls the corresponding method */
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

/* Caller method which when given four road names and a traffic flow option, calls the corresponding method */
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

/* When all three entered roads have a value other than NO_ROAD, this method modifies the outgoingRoads[] array with
 * the appropriate values and increments the conflicts counter by a specified amount depending on the method from which
 * it is called */
void threeWayConflicts(int num){
    outgoingRoads[0] = A;
    outgoingRoads[1] = B;
    outgoingRoads[2] = C;
    conflicts += num;
}

/* Represents the road connections : A-B, B-A, B-C, C-B, and C-A. A-C is left unconnected */
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

/* Represents the road connections : A-B, B-A, A-C, C-A, and B-C. C-B is left unconnected */
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

/* Represents the road connections : A-B, A-C, C-A, B-C, and C-B. B-A is left unconnected */
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

/* Represents the road connections : A-B, C-B, A-C, and C-A. C-B and B-A are left unconnected */
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

/* Represents the road connections : A-B, C-B, C-A, and B-C. B-A and A-C are left unconnected */
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

/* Represents the road connections : A-B, B-C, B-A, and C-A. C-B and A-C are left unconnected */
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

/* Represents the road connections : A-B, B-C, and C-A. C-B, A-C and B-A are left unconnected */
void threeWayOption7(road a, road b, road c){
    if(a == A)
        outgoingRoads[1] = B;
    if(b == B)
        outgoingRoads[2] = C;
    if(c == C)
        outgoingRoads[0] = A;
    return;
}

/* Represents the road connections : B-C, C-D, D-A, and A-B. B-A, C-B, A-C, B-D, C-A, D-B, A-D, and DC are left
 * unconnected */
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

/* Represents the road connections : B-C, C-D, D-A, A-B and B-A. C-B, A-C, B-D, C-A, D-B, A-D, and D-C are left
 * unconnected */
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

/* Represents the road connections : B-C, C-D, D-A, A-B, and C-B. A-C, B-D, C-A, D-B, A-D, D-C, and B-A are left
 * unconnected */
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

/* Represents the road connections : B-C, C-D, D-A, A-B, and A-C. B-A, C-B, B-D, C-A, D-B, A-D, and D-C are left
 * unconnected */
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

 /* Represents the road connections : B-C, C-D, D-A, A-B, and B-D. A-C, C-A, D-B, A-D, D-C, B-A, and C-B are left
  * unconnected */
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

 /* Represents the road connections : B-C, C-D, D-A, A-B, and C-A. B-A, C-B, A-C, B-D, D-B, A-D, and D-C are left
  * unconnected */
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

 /* Represents the road connections : B-C, C-D, D-A, A-B, and D-B. B-A, C-B, A-C, B-D, C-A, A-D, and D-C are left
  * unconnected */
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

 /* Represents the road connections : B-C, C-D, D-A, A-B, and A-D. B-A, C-B, A-C, B-D, C-A, D-B, and D-C are left
  * unconnected */
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

 /* Represents the road connections : B-C, C-D, D-A, A-B, and D-C. B-A, C-B, A-C, B-D, C-A, D-B, and A-D are left
  * unconnected */
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