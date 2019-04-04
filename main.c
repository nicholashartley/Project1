#include <stdio.h>

void menu(char c);
void rotencrypt(char encrypt, int shift);
void rotdecrypt(char decrypt, int shift);
void subencrypt(char encrypt, int shift);
void subdecrypt(char decrypt, int shift);

int main() {

char encrypt[1024];
char c;  

   
printf("Please select a menu option: \n");
printf("a) Encrypt a rotation cipher: \n");
printf("b) Decrypt a rotation cipher: \n");
printf("c) Encrypt a substitution cipher: \n");
printf("d) Decrypt a substitution cipher: \n");

scanf("%c", &c);
printf(" You have chosen option %c\n", c);


}

void menu(char c)
{
    switch(c)
    {
        case 'a':
        rotencrypt();
        break;
        
        case 'b':
        rotdecrypt();
        break;
        
        case 'c':
        subencrypt();
        break;
        
        case 'd':
        subdecrypt();
        break;
        
        default:
        printf("Unknown option %c\n Please enter a, b, c, d\n", c);
        
        
    }
    
    
    
}

