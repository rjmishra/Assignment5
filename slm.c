/*
 *
 *		Program Desc: A simple linear regression model implementation in C
 *		Author : Ranjan Mishra
 *		Date : 26th Aug 2016
 *
 */


 #include <stdio.h>


 #define alpha 0.05					// learning rate of the gradient descent
 #define epsiolon 0.0001			// the tolerance limit of the error


 typedef struct dataPoint{
 	double x;
 	double y;
 }  data;



 double computeError(unsigned int numPoints, data points[], double beta0, double beta1){

 	double totalError = 0, temp = 0;
 	unsigned int i=0;

 	for(i = 0;i < numPoints; i++){
 		temp = (points[i].y - beta1* points[i].x - beta0);
 		temp = temp * temp;
 		totalError += temp;
 	}

 	return totalError;

 }



 data stepGradient(unsigned int numPoints, double beta0, double beta1, data points[]){
 	data beta;
 	double gradientZero = 0;
 	double gradientOne = 0;
 	unsigned int i = 0;
 	double newBeta0 = 0;
 	double newBeta1 = 0;
 	
 	for(i = 0; i < numPoints; i++){ 
 		gradientZero += -2.0*((points[i].y - beta1*points[i].x - beta0)/numPoints); 
 		gradientOne += gradientZero * points[i].x;
 	}

 	newBeta0 = beta0 - alpha*gradientZero;
 	newBeta1 = beta1 - alpha*gradientOne;

 	beta.x = newBeta0;
 	beta.y = newBeta1;

 	return beta;

 } 



 data computeBetaByFormula(unsigned int numPoints, data points[]){

 	double sumX = 0;
 	double sumY =0;
 	double sumXY = 0;
 	double sumX2 = 0;
 	unsigned int i = 0;
 
 	data beta;
 	for(i = 0; i < numPoints; i++){

 		sumX += points[i].x;
 		sumY += points[i].y;
 		sumXY += points[i].x*points[i].y;
 		sumX2 += points[i].x*points[i].x;

 	}

 	beta.y = (sumXY - (sumY*sumX)/numPoints)/(sumX2 - (sumX*sumX)/numPoints);
 	beta.x = (sumY/numPoints) - beta.y*(sumX/numPoints);

 	return beta;

 }




 int main(int argc, char *argv[]){

 	FILE *fp;
 	fp = fopen(argv[1], "r");
 	data points[1000], beta;
 	unsigned int i = 0;
 	unsigned int numPoints = 0;
 	double error = 0;


 	while(fscanf(fp, "%lf %lf", &points[i].x, &points[i].y) && i < 1000){
 		i++;
 		printf("Value of i: %u\n",i);
 	}

 	numPoints = i;
 	beta.x = 1.2; beta.y = 1.4;

 	error = computeError(numPoints, points, beta.x, beta.y);
 	
 	while(error > epsiolon){
 		beta = stepGradient(numPoints, beta.x,beta.y, points);
 		error = computeError(numPoints, points, beta.x, beta.y);
 	}

 	printf("Estimated values are beta0: %lf , beta1 : %lf\n", beta.x, beta.y);
	
 	beta = computeBetaByFormula(numPoints, points);
 	printf("Estimated values are beta0: %lf , beta1 : %lf\n", beta.x, beta.y);
 	return 0;
 }