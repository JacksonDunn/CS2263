#include <stdio.h>
#include <stdlib.h>

void findClosestFlight(int desiredTime, int *departureTime, int *arrivalTime){
  FILE *f = fopen("flights.dat", "r");
  fscanf(f,"%d:%d\t%d:%d", *departureTime, *arrivalTime);

  //while( )
}

int main(int argc, char * * argv){
  int desiredTime, hour, min;
  int departureTime, arrivalTime = 0;

  printf("Enter a 24-hour time:\n");

  if(scanf("%d:%d", &hour, &min) != 2){
    printf("Please use proper input values.\n");
    return EXIT_FAILURE;
  }

  desiredTime = (hour*60) + min;

  findClosestFlight(desiredTime, &departureTime, &arrivalTime);

  printf("Closest departure time is &d, arriving at &d\n", departureTime, arrivalTime);

}
