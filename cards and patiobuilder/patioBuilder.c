#include <stdio.h>
#include <stdlib.h>

//initialize variables
float min = 0.24;
float curbW = 4.3;
float curbL = 11.8;
float paver = 7.75;
float curbPrice = 2.48;
float paverPrice = 3.90;
float hst = 0.13;
float patioWu;
float patioLu;
float patioW;
float patioL;
float curbCost;
float paverCost;
float totalCost;
int countCurbW = 0;
int countPaverW = 0;
int totalCurb = 0;
int countCurbL = 0;
int countPaverL = 0;
int totalPaver = 0;

int main(){
  //prompt user to enter patio length and width
  printf("Enter desired patio length\n");
  //check for incorrect input
  if(scanf("%f", &patioLu) != 1){
    printf("Enter real patio length next time\n");
    exit(0);
  };
  printf("Enter desired patio width\n");
  if(scanf("%f", &patioWu)!= 1){
      printf("Enter real patio width next time\n");
      exit(0);
  };

  //convert user input width and length from feet into inches
  patioW = patioWu * 12.0;
  patioL = patioLu * 12.0;
  /*
  printf("%s%f\n", "Patio Length: ",patioL);
  printf("%s%f\n", "Patio width: ",patioW);
  */

  //check if user input dimensions is at least minimum requirement
  if ((patioW <= min)||(patioL <= min)){
    printf("Patio dimensions not big enough.\n");
    exit(0);
  }

  //calculate number of curbs and pavers needed lengthwise
  countCurbL = (int)((patioL/curbL)+1)*2;
  countPaverL = (int)((patioL-(curbW+curbW))/paver)+1;
  /*
  printf("%f\n",(patioL/curbL));
  printf("%f\n",((patioL-(curbW+curbW))/paver));
  printf("%s%d\n","Number of curbs length: ",countCurbL);
  printf("%s%d\n","Number of pavers length: ",countPaverL);
  */

  //calculate number of curbs and pavers needed for patio width
  countCurbW = (int)(((patioW-(curbW+curbW))/curbL)+1)*2;
  countPaverW = (int)((patioW-(curbW+curbW))/paver)+1;
  /*
  printf("%s%d\n","Number of curbs width: ",countCurbW);
  printf("%s%d\n","Number of pavers width: ",countPaverW);
  */

  //total number of curbs and pavers
  totalCurb = countCurbL+countCurbW;
  totalPaver = countPaverL*countPaverW;
  //display number of curbs and pavers
  printf("%s%d\n","Total number of curbs: ",totalCurb);
  printf("%s%d\n","Total number of pavers: ",totalPaver);

  //price of curbs and pavers before tax
  curbCost = curbPrice*totalCurb;
  paverCost = paverPrice*totalPaver;

  //total cost plus tax
  totalCost = ((curbCost+paverCost)*hst) + (curbCost+paverCost);

  //display costs
  printf("%s%0.1f\n","Cost of curbs: $",curbCost);
  printf("%s%0.1f\n","Cost of pavers: $",paverCost);
  printf("%s%0.1f\n","Total cost plux tax: $", totalCost);
 
  return 0;
}
