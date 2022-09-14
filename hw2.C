#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double dist_km, dist_mile;

	printf("Please enter kilometers: ");
	scanf(" %lf", &dist_km);

	dist_mile = dist_km / 1.609f;
	
	printf("%.1f km is equal to %.1f miles.", dist_km, dist_mile);


	return 0;
}