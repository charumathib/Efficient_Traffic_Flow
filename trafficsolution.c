/* Created by Charumathi Badrinath */

#include <stdio.h>
#include "trafficsolution.h"
#include "util.c"
#include "roadfunctions.c"
#include <stdbool.h>

int main() {
    initialiseRoadArray (NUM_ROADS, BIDIRECTIONAL, roadsArray);
	storeAllVals (1);
    printf("\nThe number of solutions is : %i", counter);
    return 0;
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

road convertConnectionToEnum (intersection i) {
	switch (i.connection) {
		case 0:
			return A;
		case 1:
			return B;
		case 2:
			return C;
		default :
			return NO_ROAD;
	}
}

void callMethodFromEnum (intersection i, int option) {
	road rdLetter = convertConnectionToEnum (i);
	if (i.numRoads == 3) {
		if (roadsArray[i.incoming[i.connection]] != 0) {
			//puts("here");
			if (rdLetter == A) {
				threeWayIntersection (A, NO_ROAD, NO_ROAD, option);
			} else if (rdLetter == B) {
				threeWayIntersection (NO_ROAD, B, NO_ROAD, option);
			} else if (rdLetter == C) {
				threeWayIntersection (NO_ROAD, NO_ROAD, C, option);
			}
		} else {
			threeWayIntersection (NO_ROAD, NO_ROAD, NO_ROAD, option);
		}
	} else if (i.numRoads == 4) {
		if (roadsArray[i.incoming[i.connection]] != 0) {
			if (rdLetter == A) {
				fourWayIntersection (A, NO_ROAD, NO_ROAD, NO_ROAD, option);
			} else if (rdLetter == B) {
				fourWayIntersection (NO_ROAD, B, NO_ROAD, NO_ROAD, option);
			} else if (rdLetter == C) {
				fourWayIntersection (NO_ROAD, NO_ROAD, C, NO_ROAD, option);
			}
		} else {
			fourWayIntersection (NO_ROAD, NO_ROAD, NO_ROAD, NO_ROAD, option);
		}
	}
	return;
}

int optionNumber (intersection i) {
	switch (i.numRoads) {
		case 3:
			return 7;
		case 4:
			return 9;
	}
	return 0;
}

bool allIntersectionsFullyTraversed () {
	return (storage[0] == 9 && storage[1] == 7 && storage[2] == 7 && storage[3] == 7 && storage[4] == 9 &&
			storage[5] == 7 && storage[6] == 7);
}

void clearStorage () {
	for (int i = 0; i < 7; i++) {
		storage[i] = 0;
	}
}


void traverseStoredVals () {
	threeWayIntersection (NO_ROAD, B, NO_ROAD, storage[6]);
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

void storeAllVals (int intersectionNum) {
	intersection current = convertIntToIntersection (intersectionNum);
	int opNums = optionNumber (current);
	if (intersectionNum == 8) {
		return;
	} else {
		for (int i = 1; i <= opNums; i++) {
			storage[intersectionNum - 1] = i;
			storeAllVals (intersectionNum + 1);
			traverseStoredVals ();
		}
	}
}
