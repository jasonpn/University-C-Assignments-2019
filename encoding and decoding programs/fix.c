#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define DATA_BITS    8
#define PARITY_BITS  4
#define CHAR_LIMIT   100




// Given a brokenSequence of bits representing a corrupted 12-bit (i.e., DATA_BITS + PARITY_BITS)
// hamming code sequence, determine which bit had been flipped and then flip it back and store
// the repaired sequence in fixedSequence.    Note that both bit sequences may be very large,
// but this function should only examine the first 12 bits of the sequence (i.e., the first
// 12 characters in the incoming and outgoing char array).
void fix(char brokenSequence[], char fixedSequence[]) {
  // ...
  // Replace the code below with your own code
  // ...
  int match[4] = {0,0,0,0};
  int count = 0;

  if((brokenSequence[2]+brokenSequence[4]+brokenSequence[6]+brokenSequence[8]+brokenSequence[10])%2 == 0 && brokenSequence[0] == '1'){
    match[0] = 1;
    count++;
  } 
  if((brokenSequence[2]+brokenSequence[5]+brokenSequence[6]+brokenSequence[9]+brokenSequence[10])%2 == 0 && brokenSequence[1] == '1'){
    match[1]= 1;
    count++;
  }
  
  if((brokenSequence[4]+brokenSequence[5]+brokenSequence[6]+brokenSequence[11])%2 == 0 && brokenSequence[3] == '1'){
    match[2]= 1;
    count++;
  }
  
  if((brokenSequence[8]+brokenSequence[9]+brokenSequence[10]+brokenSequence[11])%2 == 0 && brokenSequence[7] == '1'){
    match[3]= 1;
    count++;
  }

  for (int i = 0; i < 4; i++){
    printf("%d\n", match[i]);
  }
  
  printf("count %d\n", count);

  if(count == 1){
    if (match[0] == 1){
      if(brokenSequence[0] == '1'){
	brokenSequence[0] = '0';
      }
      else{
	brokenSequence[0] = '1';
      }
    }
    if (match[1] == 1){
      if(brokenSequence[1] == '1'){
	brokenSequence[1] = '0';
      }
      else{
	brokenSequence[1] = '1';
      }
    }
    if (match[2] == 1){
      if(brokenSequence[3] == '1'){
	brokenSequence[3] = '0';
      }
      else{
	brokenSequence[3] = '1';
      }
    }
    if (match[3] == 1){
      if(brokenSequence[7] == '1'){
	brokenSequence[7] = '0';
      }
      else{
	brokenSequence[7] = '1';
      }
    }
    }

  if (count > 1){
    if (match[0] == 1 && match[1] == 1){
      if(brokenSequence[3] == '1'){
	brokenSequence[3] = '0';
      }
      else{
	brokenSequence[3] = '1';
      }
    }
    if (match[0] == 1 && match[2] == 1){
      if(brokenSequence[5] == '1'){
	brokenSequence[5] = '0';
      }
      else{
	brokenSequence[5] = '1';
      }
    }
     
    if (match[0] == 1 && match[3] == 1){
      if(brokenSequence[9] == '1'){
	brokenSequence[9] = '0';
      }
      else{
	brokenSequence[9] = '1';
      }
    }
     
    if (match[1] == 1 && match[2] == 1){
      if(brokenSequence[6] == '1'){
	brokenSequence[6] = '0';
      }
      else{
	brokenSequence[6] = '1';
      }
    }
     
    if (match[1] == 1 && match[3] == 1){
      if(brokenSequence[10] == '1'){
	brokenSequence[10] = '0';
      }
      else{
	brokenSequence[10] = '1';
      }
    }
    if (match[2] == 1 && match[3] == 1){
      if(brokenSequence[12] == '1'){
	brokenSequence[12] = '0';
      }
      else{
	brokenSequence[12] = '1';
      }
    }   
   }
   
  for (int i=0; i<DATA_BITS+PARITY_BITS; i++){ 
    fixedSequence[i] = brokenSequence[i];
  }
}






// This program takes in a corrupted 12-bit hamming code sequence from the user and then
// attempts to correct the corrupted bits.   It is assumed that exactly one bit in each
// of the 12-bit sequences has been flipped.   The input is a large array of characters
// which are all 1's or 0's.   The incoming sequence MUST be a multiple of 12 characters.
// For example, if a data string was entered originally as "ABCD" ... then each character
// in the string would be encoded as 12-bits.  So we would need 48 bits to represent the
// input string.   These 48 bits would be coded as 48 characters consisiting of 1's or
// 0's.   So, the expected input to this program would be a large 48 character string of
// '1' and '0' chars.
int main() {
  unsigned char   brokenString[12*CHAR_LIMIT+1];
  unsigned char   fixedString[12*CHAR_LIMIT+1];
  int             charCount;

  // Get the string to decode
  char formatString[10];
  sprintf(formatString, "%%%ds", 12*CHAR_LIMIT);
  scanf(formatString, (char *)brokenString);
  charCount = strlen(brokenString);

  // Make sure that the string size is a multiple of 12 characters, otherwise something is wrong
  if (charCount%12 != 0) {
    printf("The entered bit sequence must have a multiple of 12 bits.\nThis sequence has %d bits left over.\n", charCount%12);
    exit(-1);
  }

  // Fix the bits in the brokenString by identifying the single flipped bit in each of
  // the sequential sets of 12 bits
  for (int i=0; i<charCount/12; i++)
    fix(&brokenString[i*12], &fixedString[i*12]);
  fixedString[12*(charCount/12)] = '\0';
  printf("%s\n", fixedString);  
}
