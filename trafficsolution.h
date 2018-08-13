//
// Created by Charumathi Badrinath on 7/24/18.
//

#include <stdio.h>

#ifndef LEARNING_C_TRAFFICSOLUTION_H
#define LEARNING_C_TRAFFICSOLUTION_H

#endif //LEARNING_C_TRAFFICSOLUTION_H

#define BIDIRECTIONAL 2
#define NUM_ROADS 19

typedef enum road {NO_ROAD, A, B, C, D}road;

void threeWayIntersection(road a, road b, road c, int option);
void threeWayOption1(road a, road b, road c);
void threeWayOption2(road a, road b, road c);
void threeWayOption3(road a, road b, road c);
void threeWayOption4(road a, road b, road c);
void threeWayOption5(road a, road b, road c);
void threeWayOption6(road a, road b, road c);
void threeWayOption7(road a, road b, road c);

void fourWayIntersection(road a, road b, road c, road d, int option);
void fourWayOption1(road a, road b, road c, road d);
void fourWayOption2(road a, road b, road c, road d);
void fourWayOption3(road a, road b, road c, road d);
void fourWayOption4(road a, road b, road c, road d);
void fourWayOption5(road a, road b, road c, road d);
void fourWayOption6(road a, road b, road c, road d);
void fourWayOption7(road a, road b, road c, road d);
void fourWayOption8(road a, road b, road c, road d);
void fourWayOption9(road a, road b, road c, road d);

void threeWayConflicts(int num);
void clearOutgoingRoads();
void initialiseRoadArray(int noOfRoads, int lanes, short roads[]);
void traversePaths();
void reverse();
void revTraversePaths();

void storeAllVals ();

void traverse ();


