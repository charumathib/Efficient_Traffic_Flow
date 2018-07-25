//
// Created by Charumathi Badrinath on 7/24/18.
//

#include <stdio.h>

#ifndef LEARNING_C_TRAFFICSOLUTION_H
#define LEARNING_C_TRAFFICSOLUTION_H

#endif //LEARNING_C_TRAFFICSOLUTION_H

typedef enum road {A, B, C, D, NO_ROAD}road;

void threeWayIntersection(road a, road b, road c, short option);
void threeWayOption1(road a, road b, road c);
void threeWayOption2(road a, road b, road c);
void threeWayOption3(road a, road b, road c);
void threeWayOption4(road a, road b, road c);
void threeWayOption5(road a, road b, road c);
void threeWayOption6(road a, road b, road c);
void threeWayOption7(road a, road b, road c);

void fourWayIntersection(road a, road b, road c, road d, short option);
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
void initializeVertices();

