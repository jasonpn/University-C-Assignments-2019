#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//declare variables
char rank[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
char suit[] = {'H','D','S','C'};
char trump[1]; 
char end = '.';
char p1[4];
char p2[4];
char p3[4];
char p4[4];

//check if input c exists rank array
char  isValidRank(char c){
  char val;
  char inval;
  val = 1;
  inval = 0;
  
  //check if c is uppercase letter, then compare c to rank array elements
  if (isalpha(c)&&(c>='A'&&c<='Z')){
    for (int i = 0; i < 13; i++){
       if (rank[i] == c){
	 return val;
       }
    }
  }
  //check if c is a number, compare c to first 8 number  elements of rank array
  else if(isdigit(c)){
    for (int j = 0;j<8; j++){
      if(rank[j]==c){
	return val;
      }
    }
  }
  //check if c is lowercase
  if(isalpha(c)&&c>='a'&&c<='z'){
    //printf("Invalid input\n");
    return inval;
  }
  return inval; 
}

//check if c exists in suit array
char isValidSuit(char c){
  char val;
  char inval;
  val = 1;
  inval = 0;
  
  for (int i = 0; i < 4; i++){
    if (suit[i] == c){
      return val;
    }
  }

  if(c>='a'&&c<='z'){
    printf("Invalid input\n");
    return inval;
  }
  return inval;
}

//get trump card from user and checks if it is a valid trump card using isValidSuit
char getTrump(){
  do{
    printf("Input trump suit (H, D, S or C)\n");
    scanf("%s", trump);
    //check if user entered correct number of characters
    if (strlen(trump)>1 || strlen(trump)<1){
      while(strlen(trump)>1 || strlen(trump)<1){
	printf("Invalid card, please re-enter\n");
	scanf("%s",trump);
	if(trump[0]==end){
	  exit(0);
	}
      }
    }
    if(isValidSuit(trump[0])==0){
      printf("Invalid trump suit\n");
    }
  }while(isValidSuit(trump[0])==0);
  
  return trump[0];
}


int main(){
  //infinite loop that asks players to enter cards and determines the best card
  do{
    getTrump();
    printf("Player 1: Enter card rank and suit\n");
    scanf("%s", p1);
    if(p1[0]==end){
      exit(0);
    }
    //check if user entered correct number of characters
    if (strlen(p1)>2 || strlen(p1)<2){
      while(strlen(p1)>2 || strlen(p1)<2){
	printf("Invalid card, please re-enter\n");
	scanf("%s",p1);
	if(p1[0]==end){
	  exit(0);
	}
      }
    }
        

    //check players card to see if valid, loop prompts user again until valid card entered
    if(isValidRank(p1[0])== 0 || isValidSuit(p1[1]) == 0){
      while(isValidRank(p1[0])==0 || isValidSuit(p1[1]) == 0){
	printf("Invalid card, please re-enter\n");
	scanf("%s", p1);
	if(p1[0]==end){
	  exit(0);
	}
      }
    }
    
    printf("Player 2: Enter card rank and suit\n");
    scanf("%s", p2); 
    if(p2[0]==end){
      exit(0);
    }
    
    if (strlen(p2)>2 || strlen(p2)<2){
      while(strlen(p2)>2 || strlen(p2)<2){
	printf("Invalid card, please re-enter\n");
	scanf("%s",p2);
	if(p2[0]==end){
	  exit(0);
	}
      }
    }

    if(isValidRank(p2[0])== 0 || isValidSuit(p2[1]) == 0){
      while(isValidRank(p2[0])==0 || isValidSuit(p2[1]) == 0){
	printf("Invalid card, please re-enter\n");
	scanf("%s", p2);
	if(p2[0]==end){
	  exit(0);
	}
      }
    }
    
    printf("Player 3: Enter card rank and suit\n");
    scanf("%s", p3);
    if(p3[0]==end){
      exit(0);
    }

    if (strlen(p3)>2 || strlen(p3)<2){
      while(strlen(p3)>2 || strlen(p3)<2){
	printf("Invalid card, please re-enter\n");
	scanf("%s",p3);
	if(p3[0]==end){
	  exit(0);
	}
      }
    }
    
    if(isValidRank(p3[0])== 0 || isValidSuit(p3[1]) == 0){
      while(isValidRank(p3[0])==0 || isValidSuit(p3[1]) == 0){
	printf("Invalid card, please re-enter\n");
	scanf("%s", p3);
	if(p3[0]==end){
	  exit(0);
	}
      }
    }
    
    printf("Player 4: Enter card rank and suit\n");
    scanf("%s", p4);
    if(p4[0]==end){
      exit(0);
    }
  
    if (strlen(p4)>2 || strlen(p4)<2){
      while(strlen(p4)>2 || strlen(p4)<2){
	printf("Invalid card, please re-enter\n");
	scanf("%s",p4);
	if(p4[0]==end){
	  exit(0);
	}
      }
    }
   
  
    if(isValidRank(p4[0])== 0 || isValidSuit(p4[1]) == 0){
      while(isValidRank(p4[0])==0 || isValidSuit(p4[1]) == 0){
	printf("Invalid card, please re-enter\n");
	scanf("%s", p4);
	if(p4[0]==end){
	  exit(0);
	}
      }
    }

    //displays cards
    printf("%s %c%c\n","Player 1 card: ",p1[0],p1[1]);
    printf("%s %c%c\n","Player 2 card: ",p2[0],p2[1]);
    printf("%s %c%c\n","Player 3 card: ",p3[0],p3[1]);
    printf("%s %c%c\n","Player 4 card: ",p4[0],p4[1]);

    //change suit letters to consecutive letters so they can be compared using their ascii numbers
    if (p1[0] == 'T'){
      p1[0] = 'A';
    }
    if (p1[0] == 'J'){
      p1[0] = 'B';
    }
    if (p1[0] == 'Q'){
      p1[0] = 'C';
    }
    if (p1[0] == 'K'){
      p1[0] = 'D';
    }
    if (p1[0] == 'A'){
      p1[0] = 'E';
    }
    if (p2[0] == 'T'){
      p2[0] = 'A';
    }
    if (p2[0] == 'J'){
      p2[0] = 'B';
    }
    if (p2[0] == 'Q'){
      p2[0] = 'C';
    }
    if (p2[0] == 'K'){
      p2[0] = 'D';
    }
    if (p2[0] == 'A'){
      p2[0] = 'E';
    }
    if (p3[0] == 'T'){
      p3[0] = 'A';
    }
    if (p3[0] == 'J'){
      p3[0] = 'B';
    }
    if (p3[0] == 'Q'){
      p3[0] = 'C';
    }
    if (p3[0] == 'K'){
      p3[0] = 'D';
    }
    if (p3[0] == 'A'){
      p3[0] = 'E';
    }
    if (p4[0] == 'T'){
      p4[0] = 'A';
    }
    if (p4[0] == 'J'){
      p4[0] = 'B';
    }
    if (p4[0] == 'Q'){
      p4[0] = 'C';
    }
    if (p4[0] == 'K'){
      p4[0] = 'D';
    }
    if (p4[0] == 'A'){
      p4[0] = 'E';
    }

    //win conditions, declare the best card from the 4 players
    if(p1[1]!=trump[0] && p2[1]!=trump[0] && p3[1]!=trump[0] && p4[1]!=trump[0]){
      if(p1[1] == p2[1] || p1[1] == p3[1] || p1[1] == p4[1]){
	if(p1[0]>p2[0] && p1[0]>p3[0] && p1[0]>p4[0]){
	  printf("Player 1 wins!\n");
	}
	else if(p2[0]>p1[0] && p2[0]>p3[0] && p2[0]>p4[0]){
	  printf("Player 2 wins!\n");
	}
	else if(p3[0]>p1[0] && p3[0]>p2[0] && p3[0]>p4[0]){	
	  printf("Player 3 wins!\n");
	}
	else if(p4[0]>p1[0] && p4[0]>p3[0] && p4[0]>p2[0]){	
	  printf("Player 4 wins!\n");
	}
      }
      else{
	printf("Player 1 wins!\n");
      }
    }
    
    if(p1[1]==trump[0] && p2[1]==trump[0] && p3[1]==trump[0] && p4[1]==trump[0]){
      if(p1[0]>p2[0] && p1[0]>p3[0] && p1[0]>p4[0]){
	printf("Player 1 wins!\n");
      }
      else if(p2[0]>p1[0] && p2[0]>p3[0] && p2[0]>p4[0]){
	printf("Player 2 wins!\n");
      }
      else if(p3[0]>p1[0] && p3[0]>p2[0] && p3[0]>p4[0]){	
	printf("Player 3 wins!\n");
      }
      else if(p4[0]>p1[0] && p4[0]>p3[0] && p4[0]>p2[0]){	
	printf("Player 4 wins!\n");
      }
    }
    if(p1[1]==trump[0] && p2[1]!=trump[0] && p3[1]!=trump[0] && p4[1]!=trump[0]){
      printf("Player 1 wins!\n");
    }
    if(p1[1]!=trump[0] && p2[1]==trump[0] && p3[1]!=trump[0] && p4[1]!=trump[0]){
      printf("Player 2 wins!\n");
    }
    if(p1[1]!=trump[0] && p2[1]!=trump[0] && p3[1]==trump[0] && p4[1]!=trump[0]){
      printf("Player 3 wins!\n");
    }
    if(p1[1]!=trump[0] && p2[1]!=trump[0] && p3[1]!=trump[0] && p4[1]==trump[0]){
      printf("Player 4 wins!\n");
    }
    if(p1[1]==trump[0] && p2[1]==trump[0] && p3[1]!=trump[0] && p4[1]!=trump[0]){
      if(p1[0]>p2[0]){
	printf("Player 1 wins!\n");
      }
      else if (p2[0]>p1[0]){
	printf("Player 2 wins!\n");
      }
    }
    if(p1[1]==trump[0] && p2[1]==trump[0] && p3[1]==trump[0] && p4[1]!=trump[0]){
      if(p1[0]>p2[0] && p1[0]>p3[0]){
	printf("Player 1 wins!\n");
      }
      else if (p2[0]>p1[0] && p2[0]>p3[0]){
	printf("Player 2 wins!\n");
      }
      else if (p3[0]>p1[0] && p3[0] > p2[0]){
	printf("Player 3 wins!\n");
      }
    }
    if(p1[1]!=trump[0] && p2[1]==trump[0] && p3[1]==trump[0] && p4[1]!=trump[0]){
      if(p2[0]>p3[0]){
	printf("Player 2 wins!\n");
      }
      else if (p3[0]>p2[0]){
	printf("Player 3 wins!\n");
      }
    }
    if(p1[1]!=trump[0] && p2[1]==trump[0] && p3[1]==trump[0] && p4[1]==trump[0]){
      if(p2[0]>p3[0] && p2[0]>p4[0]){
	printf("Player 2 wins!\n");
      }
      else if (p3[0]>p2[0] && p3[0]>p4[0]){
	printf("Player 3 wins!\n");
      }
      else if (p4[0]>p2[0] && p4[0] > p3[0]){
	printf("Player 4 wins!\n");
      }
    }
    if(p1[1]==trump[0] && p2[1]!=trump[0] && p3[1]==trump[0] && p4[1]!=trump[0]){
      if(p1[0]>p3[0]){
	printf("Player 1 wins!\n");
      }
      else if (p3[0]>p1[0]){
	printf("Player 3 wins!\n");
      }
    }
    if(p1[1]==trump[0] && p2[1]!=trump[0] && p3[1]!=trump[0] && p4[1]==trump[0]){
      if(p1[0]>p4[0]){
	printf("Player 1 wins!\n");
      }
      else if (p4[0]>p1[0]){
	printf("Player 4 wins!\n");
      }
    }
    if(p1[1]==trump[0] && p2[1]!=trump[0] && p3[1]==trump[0] && p4[1]==trump[0]){
      if(p1[0]>p3[0] && p1[0]>p4[0]){
	printf("Player 1 wins!\n");
      }
      else if (p3[0]>p1[0] && p3[0]>p4[0]){
	printf("Player 3 wins!\n");
      }
      else if (p4[0]>p1[0] && p4[0] > p3[0]){
	printf("Player 4 wins!\n");
      }
    }
    if(p1[1]==trump[0] && p2[1]==trump[0] && p3[1]!=trump[0] && p4[1]==trump[0]){
      if(p1[0]>p2[0] && p1[0]>p4[0]){
	printf("Player 1 wins!\n");
      }
      else if (p2[0]>p1[0] && p2[0]>p4[0]){
	printf("Player 2 wins!\n");
      }
      else if (p4[0]>p1[0] && p4[0] > p2[0]){
	printf("Player 4 wins!\n");
      }
    }
    if(p1[1]!=trump[0] && p2[1]==trump[0] && p3[1]!=trump[0] && p4[1]==trump[0]){
      if(p2[0]>p4[0]){
	printf("Player 2 wins!\n");
      }
      else if (p4[0]>p2[0]){
	printf("Player 4 wins!\n");
      }
    }


    //if any player enters end character '.', exit program
    if (p1[0]==end || p2[0]==end || p3[0]==end || p4[0]==end){
      exit(0);
    }
      
  }while(p1[0] !=  end || p2[0]!=end || p3[0]!=end || p4[0]!=end);//loops until a player inputs end characters
				 
  return 0;
}
