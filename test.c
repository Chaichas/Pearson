#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "rdtsc.h"

#define N_sum 5

//
int timeSteps;

//
unsigned long long rdtsc(void) {
  unsigned long long a, d;

  __asm__ volatile("rdtsc": "=a"(a), "=d"(d));

  return (d << 32) | a;
}

//Fonction de Pearson Correlation
double Pearson_Correlation(double *x, double *y)
{
  //Initialisation des sommes
  double sumX = 0; double sumY = 0; double sumXY = 0;
  double sumX2 = 0; double sumY2 = 0;

  for(int i=0;i<=N_sum;i++){
      
      //Somme de xi
      sumX += x[i];

      //Somme de yi
      sumY += y[i];

      //Somme de xi*yi
      sumXY += x[i]*y[i];

      //Somme de pow(xi,2) et pow(yi,2)
      sumX2 += x[i]*x[i];
      sumY2 += y[i]*y[i];
  }

  //Calcul du coefficient de Correlation
  double e = (N_sum*sumXY-sumX*sumY)/
                    (sqrt(N_sum*sumX2-pow(sumX,2))*sqrt(N_sum*sumY2-pow(sumY,2)));

  return e;
}

//
int main()
{
  int i;

    double x[]={15, 18, 21, 24, 27};
    double y[]={15, 18, 21, 24, 27};

    for (int i = 0; i < 100; i++)
    {	  
      //
      double before = (double)rdtsc();

      //Function call to correlationCoefficient
      printf("Le coefficient de Correlation de Pearson est egal a: %lf \n",Pearson_Correlation(x,y));
      double after = (double)rdtsc();
      
      //
      printf("%d %lf\n", i, (after - before));
  
    return 0;
}}