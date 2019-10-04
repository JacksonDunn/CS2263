#include <stdio.h>
#include <stdlib.h>

void findClosestFlight(int desiredTime, int *departureTime, int *arrivalTime){
  int h,m,h1,m1;
  int nxtDepartureTime, nxtArrivalTime;
  int closestDepHour, closestDepMin, closestArrHour, closestArrMin;
  int numFlights = 8;
  int closest[2];

  FILE *f = fopen("flights.dat", "r");
  fscanf(f,"%d:%d\t%d:%d", &h, &m, &h1, &m1);
  //assumes first is closest, will check the rest next
  *departureTime = (h*60)+ m;
  *arrivalTime = (h1*60)+ m1;
  closest[0] = *departureTime;
  closest[1] = *arrivalTime;

  //finds the closest departing flight to the desired flight
  for(int i=0; i<(numFlights-1); i++){
    fscanf(f,"%d:%d\t%d:%d", &h, &m, &h1, &m1);
    nxtDepartureTime = (h*60)+ m;
    nxtArrivalTime = (h1*60)+ m1;
    if(abs(desiredTime-nxtDepartureTime) < abs(desiredTime-*departureTime)){
      closest[0] = nxtDepartureTime;
      closest[1] = nxtArrivalTime;
    }
  }
  //goes from minutes back to 24 hour representation
  closestDepHour = closest[0]/60;
  closestDepMin = closest[0]%60;
  closestArrHour = closest[1]/60;
  closestArrMin = closest[1]%60;
  printf("Closest departure time is %d:%02d, arriving %d:%02d\n", closestDepHour, closestDepMin, closestArrHour, closestArrMin);
  }


int main(int argc, char * * argv){
  int desiredTime, hour, min = 0;
  int departureTime, arrivalTime = 0;

  printf("Enter a 24-hour time:\n");

  if(scanf("%d:%d", &hour, &min) != 2){
    printf("Please use proper input values.\n");
    return EXIT_FAILURE;
  }

  //24-hour to time in just minutes
  desiredTime = (hour*60) + min;

  findClosestFlight(desiredTime, &departureTime, &arrivalTime);

}
