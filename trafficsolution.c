/* Created by Charumathi Badrinath */

#include <stdio.h>
#include "trafficsolution.h"
#include "util.c"
#include "roadfunctions.c"

int main() {
    initialiseRoadArray (NUM_ROADS, BIDIRECTIONAL, roadsArray);
    revTraversePaths();
    printf("\nThe number of solutions is : %i", counter);
    return 0;
}

void revTraversePaths() {
    for (int i = 1; i <= 7; i++) {
        storage[6] = i;
        threeWayIntersection (NO_ROAD, B, NO_ROAD, i);
        convertLettersToRoadNames(int7);
        if (roadsArray[5] != 0) {
            for (int j = 1; j <= 7; j++) {
                storage[5] = j;
                threeWayIntersection (A, NO_ROAD, NO_ROAD, j);
                convertLettersToRoadNames(int6);
                if (roadsArray[13] != 0) {
                    for (int k = 1; k <= 9; k++) {
                        storage[4] = k;
                        fourWayIntersection(NO_ROAD, NO_ROAD, C, NO_ROAD, k);
                        convertLettersToRoadNames(int5);
                        if(roadsArray[17] != 0){
                            for(int l = 1; l <= 7; l++) {
                                storage[3] = l;
                                threeWayIntersection (A, NO_ROAD, NO_ROAD, l);
                                convertLettersToRoadNames(int4);
                                if(roadsArray[21] != 0){
                                    for(int m = 1; m <= 7; m++) {
                                        storage[2] = m;
                                        threeWayIntersection (NO_ROAD, NO_ROAD, C, m);
                                        convertLettersToRoadNames(int3);
                                        if(roadsArray[35] != 0){
                                            for(int n = 1; n <= 7; n++) {
                                                storage[1] = n;
                                                threeWayIntersection (A, NO_ROAD, NO_ROAD, n);
                                                convertLettersToRoadNames(int2);
                                                if(roadsArray[25] != 0){
                                                    for(int q = 1; q <= 9; q++) {
                                                        storage[0] = q;
                                                        fourWayIntersection (NO_ROAD, NO_ROAD, C, NO_ROAD, q);
                                                        convertLettersToRoadNames(int1);
                                                        if(roadsArray[3] != 0 && checkNumConflicts() < 9 && roadsArray[4] == NO_ROAD) {
                                                            printf ("%i\n", conflicts);
                                                            printSolution ();
                                                            counter++;
                                                            conflicts = 0;
                                                        }
                                                        clearRoadsArray();
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
