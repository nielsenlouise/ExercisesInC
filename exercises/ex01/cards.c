/* A program that counts cards.
 */

#include <stdio.h>
#include <stdlib.h>

int value(char card_name[]) {
  /*
    Finds value of played card.
    Takes in name of played card.
    Returns value of card.
  */
  int val = 0;
  switch(card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    case 'X':
      break;
    default:
      val = atoi(card_name);
      if ((val < 1) || (val > 10)) {
        puts("I don't understand that value!");
        break;
      }
  }
  return val;
}

int counter(int val, int count) {
  /*
    Updates the current count.
    Takes in value of played card,
    current count.
    Returns updated count.
  */
  if ((val > 2) && (val < 7)) {
    count++;
  } else if (val == 10) {
    count --;
  }
  return count;
}

int main() {
  /*
    Main function.
    Runs count in a loop.
    Ends when user enters 'X' instead of
    card name.
  */
  char card_name[3];
  int count = 0;
  while (card_name[0] != 'X') {
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    int val = value(card_name);
    count = counter(val, count);
    printf("Current count: %i\n", count);
  }
  return 0;
}
