/*****+*---**----*-**--*-*---**-----**-*-*-**-******************************
*
*  Lab #: 7
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: Given a user inputted seed value, this program generates two integers that will be used to draw 
*
******+*---**----*-**--*-*---**-----**-*-*-**-*****************************/
#include <stdio.h>
#include <stdlib.h>
#define MAXIMUM 16

void userInput(int* seed_value);
void dealerDraw(int* first_ace, int seed_value, int card_number, int face_number, int suit_number, int* iteration, int* score);
void userOutput(int first_ace, int iteration, int card_number, int suit_number, int face_number,  int score);

int main(void) 
{
  int seed_value;   //Declaration of the variable used to store the user inputted seed value.
  int iteration;    //Declaration of the variable used to keep track of the number of iterations.
  int score;        //Declaration of the variable used to keep track of the score as it changes.
  int card_number;  //Declaration of the variable used to identify the card number (1-52).  
  int face_number;  //Declaration of the variable used to identify which card number in the suit.
  int suit_number;  //Declaration of the variable used to identify which suit the card is in.
  int first_ace;    //Declaration of the variable used as a boolean to determine if the first drawn card is an ace (0 if false, 1 if true).

  iteration = 0;
  score = 0;
  card_number = 0;
  face_number = 0;
  suit_number = 0;
  first_ace = 0;

  userInput(&seed_value); //Calls the user input function and stores the seed_value number.
  srand(seed_value); //Creates a random number using the seed_value number.

  dealerDraw(&first_ace, seed_value, card_number, face_number, suit_number, &iteration, &score);  //Calls the dealerDraw function. 
  dealerDraw(&first_ace, seed_value, card_number, face_number, suit_number, &iteration, &score);  //Calls the dealerDraw function.

  if (score < MAXIMUM)
  {
      dealerDraw(&first_ace, seed_value, card_number, face_number, suit_number, &iteration, &score);  //Calls the dealerDraw function.
      if (score < MAXIMUM) 
      {
        dealerDraw(&first_ace, seed_value, card_number, face_number, suit_number, &iteration, &score);  //Calls the dealerDraw function.
        if (score < MAXIMUM)
        {
          dealerDraw(&first_ace, seed_value, card_number, face_number, suit_number, &iteration, &score);  //Calls the dealerDraw function.
        }
      }
  }
  
  return 0;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: userInput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int* seed_value: user inputted seed value; to be used in the random number generator.
*
*  Function Description: Asks the user for input and stores the value so that it can be accessed later.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void userInput(int* seed_value) 
{
  printf("Enter the seed value -> ");
  scanf("%d", seed_value);  //Stores the user input and passes the value back into main. 
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: dealerDraw
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int* first_ace: boolean to determine if the first drawn card is an ace (0 if false, 1 if true).
*    2. int seed_value: user inputted seed value.
*    3. int card_number: number of the card on a scale of 1-52.
*    4. int face_number: face value of the card; used while determining the score.
*    5. int suit_number: determines which suit the card is from.
*    6. int* iteration: the iteration number.
*    7. int* score: total score the user has.
*
*  Function Description: Uses all of the above values to then draw a card. Once the card is drawn, the function determines the value of the card, what suit the card is in,
*                        and updates the score. 
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void dealerDraw(int* first_ace, int seed_value, int card_number, int face_number, int suit_number, int* iteration, int* score)
{
  card_number = rand() % 52 + 1;  //Determines the card number
  face_number = card_number % 13; //Determines the face value of the card using the card number.
  suit_number = card_number / 13; //Determines the suit number of the card (0-13 are Clubs, 14-26 are Diamonds, 27-39 are Hearts, 40-52 are Spades).

  if (*iteration == 0 && face_number == 1) //If the first drawn is an ace, sets the value of the card to be 11. 
  {
    *score += 11;
    *first_ace = 1;
  }
  else if (face_number >= 10 || face_number == 0) 
  {
    *score += 10;
  }
  else
  {
    *score += face_number;
  }

  *iteration += 1;

  userOutput(*first_ace, *iteration, card_number, suit_number, face_number, *score);
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: userOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int first_ace: boolean to determine if the first drawn card is an ace (0 if false, 1 if true).
*    2. int iteration: the iteration number.
*    3. int card_number: number of the card on a scale of 1-52.
*    4. int suit_number: determines which suit the card is from.
*    5. int face_number: face value of the card; used while determining the score.
*    6. int score: total score the user has.
*
*  Function Description: creates the output for the user based off the seed value that they previously entered.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void userOutput(int first_ace, int iteration, int card_number, int suit_number, int face_number,  int score)
{
  switch (iteration) 
  {
    case 1: printf("\nThe first card is #: %d ", card_number);
    break;

    case 2: printf("\nThe second card is #: %d ", card_number);
    break;

    case 3: printf("\nThe third card is #: %d ", card_number);
    break;

    case 4: printf("\nThe fourth card is #: %d ", card_number);
    break;

    case 5: printf("\nThe fifth card is #: %d ", card_number);
    break;
  }

  switch (face_number)
    {
      case 11: printf("(Jack of ");
      break;

      case 12: printf("(Queen of ");
      break;

      case 0: printf("(King of ");
      break;

      case 1: printf("(Ace of ");
      break;

      default: printf("(%d of ", face_number);
      break;
    }
  
  switch (suit_number)
    {
      case 0: printf("Clubs) ");
      break;

      case 1: printf("Diamonds) ");
      break;

      case 2: printf("Hearts) ");
      break;

      case 3: printf("Spades) ");
      break;

      default: printf("Spades) ");
      break;
    }

  if (score > 21 && first_ace == 1) 
  {
    score -= 10;
  }
  printf("Current score: %d", score);

  if (score > 21) 
  {
    printf("\n\nDealer busts");
  }
  else if (score >= 16)
  {
    if (score == 21)
    {
      printf("\n\nDealer wins");
    }
    else
    {
      printf("\n\nDealer holds");
    }
    
  }

  else
  {
    if (iteration == 5)
    {
      printf("\n\nDealer holds");
    }
  }
}