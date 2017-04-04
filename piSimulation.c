
/* This is simulation program to calculate the value of pi
Author : Ranjan Mishra
*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define SEED 7634579846
int main(){
long iterations = 10;
double x, y; // point in first quadrant
long int i = 0, count = 0;
double pi, z = 0; // z is distance from origin of point (x,y)
// printf("Enter the number of iterations used to estimate pi: ");
// scanf("%d",&iterations);
srand(time(NULL));
while(iterations < 10000000000){
iterations *= 10;
count = 0;
for(i = 0; i < iterations; i++){
x = (double)rand()/RAND_MAX;
y = (double)rand()/RAND_MAX;
z = x*x + y*y;
if(z <= 1)
count++;
}
pi=(double)count/iterations*4;
printf("# of trials= %ld , estimate of pi is %g \n",iterations,pi);
}
return 0;
}
