/* Created by Charumathi Badrinath */

#include <stdio.h>
#include "trafficsolution.h"
#include "util.c"
#include "roadfunctions.c"
#include <stdbool.h>

int main() {
    initialiseRoadArray (NUM_ROADS, BIDIRECTIONAL, roadsArray);
	traverseIntersections (1);
    printf("\nThe number of solutions is : %i", counter);
    return 0;
}

/* Main logic of the program. Recursively traverses through all intersections and temporarily stores all possible
 * combinations of traffic flows. */
void traverseIntersections (int intersectionNum) {
	intersection current = convertIntToIntersection (intersectionNum);
	int opNums = optionNumber (current);
	if (intersectionNum == 8) {
		return;
	} else {
		for (int i = 1; i <= opNums; i++) {
			storage[intersectionNum - 1] = i;
			traverseIntersections (intersectionNum + 1);
			traverseStoredVals ();
		}
	}
}

/* Helper method which executes traffic flows at each intersection depending on what has been stored in the storage
 * array. */
void traverseStoredVals () {
	threeWayIntersection (NO_ROAD, ROAD, NO_ROAD, storage[6]);
	convertLettersToRoadNames (int7);
	for (int i = 5; i >= 0; i--) {
		intersection curr = convertIntToIntersection (i + 1);
		if (roadsArray[curr.incoming[curr.connection]] != 0) {
			callMethodFromEnum (curr, storage[i]);
			convertLettersToRoadNames (curr);
		}
	}
	if (roadsArray[3] != 0 && checkNumConflicts () < 9) {
		printf ("%i\n", conflicts);
		printSolution ();
		counter++;
		conflicts = 0;
	}
	clearRoadsArray ();
}

