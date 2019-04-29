
#include <stdio.h>
#include <stdlib.h>

char message[100], newword;                                                     //initiliase to strings to use for encrypting/decrypting words  
int shift, i;                                                                   // initilaise two integers to use for encryption/decryption
void encryption();                                                              // function prototype for encryption
void decryption();                                                              // function prototype for decryption
void text_input();                                                              // function prototype for entering text
void shift_input();                                                             // function prototype for entering shift



int main()


{
      int menu;                                                                 // call manu function
      text_input();                                                             // call text input function
      shift_input();                                                            // call shift function
      while(1)                                                                  // infinite loop so that you can encrypt and decrypt more then once
      {
            printf("\n1. Encryption\n2. Decryption\n3. Exit\n");                // print menu options
            printf("\nEnter You Selection:\t");
            scanf("%d", &menu);                                                 // scan for an integer for menu selection
            switch(menu)                                                        // switch/case for menu choice
            {
                  case 1: encryption();
                          break;
                  case 2: decryption();
                          break;
                  case 3: exit(0);
                  default: printf("\nPlease select a correct option:\n");
            }
      }
      printf("\n");
      
      
      return 0;
}


void text_input()                                                               // Function body for text input
{	
      printf("Enter a message:\t");                             
      scanf("%[^\n]s", message);                                                // scan for message including white spaces.  Will scan till new line
}

void shift_input()                                                              // function body for shift input 
{
      printf("Enter a shift:\t");
      scanf("%d", &shift);
}

void encryption()                                                               // function body for encryption
{
      for(i = 0; message[i] != '\0'; i++)                                       // for each letter that is not whitespace increment char by 1
      {
            newword = message[i];                                               // newword equals the entered message
            if(newword >= 'a' && newword <= 'z')                                // check to see if word entered is in lower case usic ASCII values
            {
                  newword = newword + shift;                                    //add the shift to each letter increment
                  if(newword > 'z')                                             
                  {
                        newword = newword - 'z' + 'a' - 1;                      // if newword is greater then z rotate back around
                  }
                  message[i] = newword;                                         // message equals newword into each char
            }
            else if(newword >= 'A' && newword <= 'Z')                           // check to see if text entered is in Upper case
            {
                  newword = newword + shift;                                    //add the shift to each letter increment
                  if(newword > 'Z')
                  {
                        newword = newword - 'Z' + 'A' - 1;                      //if newword is greater then Z rotate back around
                  }
                  message[i] = newword;                                         // message equals newword into each char
            }
      }
      printf("\nEncrypted Message:\t%s\n", message);                            // print the encrypted messaage
}

void decryption()                                                               //function body for decryption
{
      for(i = 0; message[i] != '\0'; i++)                                       // for each letter that is not whitespace increment char by 1
      {
            newword = message[i];
            if(newword >= 'a' && newword <= 'z')                                // check to see if word entered is in lower case usic ASCII values
            {
                  newword = newword - shift;                                    // minus the shift to each letter increment
                  if(newword < 'a')
                  {
                        newword = newword + 'z' - 'a' + 1;                      // if value is less then a rotate back around
                  }
                  message[i] = newword;
            }
            else if(newword >= 'A' && newword <= 'Z')                           // // check to see if word entered is in upper case usic ASCII values
            {
                  newword = newword - shift;                                    // minus the shift to each letter increment
                  if(newword < 'A')
                  {
                        newword = newword + 'Z' - 'A' + 1;                      // if the value is less then A roate back around
                  }
                  message[i] = newword;                                         //message equals the newword calculated
            }
      }
      printf("\nDecrypted Message:\t%s\n", message);                            // print the decrypted message
}
