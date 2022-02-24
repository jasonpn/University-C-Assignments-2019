#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define DATA_BITS    8
#define PARITY_BITS  4
#define CHAR_LIMIT   100


// Encode the given character c into a bitSequence of size (DATA_BITS + PARITY_BITS).
// Each character in bitSequence must be a '1' or '0' character corresponding to one of the
// proper hamming code data bits or parity bits.  For example, if c='A', then the
// resulting string "100010010001" should be stored in bitSequence.
void encode(unsigned char c, char bitSequence[]) {
  // Replace the code below with your own code.

  int toBits[8];
  int p1,p2,p4,p8;
  // ...

  //Converting char c into binary
  for (int j = 7; j >= 0; j--){
    if ((int)(c/pow(2,j)) > 0){
      toBits[j] = 1;
      c = c - pow(2,j);
    }
    else{
      toBits[j] = 0;
    }
    toBits[8] = '\0';
    //printf("%d", toBits[j]);
  }
  //printf("\n");

  //storing 8 bits into 12 bit bitSequence array individually

  bitSequence[2] = toBits[7]+'0';
  bitSequence[4] = toBits[6]+'0';
  bitSequence[5] = toBits[5]+'0';
  bitSequence[6] = toBits[4]+'0';
  bitSequence[8] = toBits[3]+'0';
  bitSequence[9] = toBits[2]+'0';
  bitSequence[10]= toBits[1]+'0';
  bitSequence[11]= toBits[0]+'0';


  //Calculating parity bits
  if((toBits[7]+toBits[6]+toBits[4]+toBits[3]+toBits[1])%2 != 0){
    p1 = 1;
  }
  else{
    p1 = 0;
  }
  
  if((toBits[7]+toBits[5]+toBits[4]+toBits[2]+toBits[1])%2 != 0){
    p2 = 1;
  }
  else{
    p2 = 0;
  }

  if((toBits[6]+toBits[5]+toBits[4]+toBits[0])%2 != 0){
    p4 = 1;
  }
  else{
    p4 = 0;
  }
  
  if((toBits[3]+toBits[2]+toBits[1]+toBits[0])%2 != 0){
    p8 = 1;
  }
  else{
    p8=0;
  }

  //storing parity bits 
  bitSequence[0] = p1+'0';
  bitSequence[1] = p2+'0';
  bitSequence[3] = p4+'0';
  bitSequence[7] = p8+'0';
 
  bitSequence[12] = '\0';


  for (int i=0; i<PARITY_BITS + DATA_BITS; i++){

  // ...
    //printf("%c\n",bitSequence[i]);
  }

}


// This program gets a string of ASCII characters from the user and then encodes each character
// using a 12-bit hamming code scheme, which uses 4 parity bits.  The output is displayed as a single
// string that represents a sequence of bits which has length of 12 times the number of characters
// entered.  The resulting string output consists solely of '1' and '0' characters.
int main() {
  unsigned char   transmitString[CHAR_LIMIT+1];
  unsigned char   encodedCharacters[(12+1)*(CHAR_LIMIT+1)];
  int             charCount;

  // Get the string to encode
  char formatString[10];
  sprintf(formatString, "%%%ds", CHAR_LIMIT);
  scanf(formatString, (char *)transmitString);
  charCount = strlen(transmitString);

  // Encode each character in the string by using a 12-bit hamming code
  for (int i=0; i<charCount; i++) {
    encode(transmitString[i], &encodedCharacters[13*i]);
    printf("%s", &encodedCharacters[13*i]);
  }
  printf("\n");
}
