
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main()
{

    int i;
    int j = 0;
    int k;
    int l;
    int m;                  // Declaration of variables.
    int deck[28];
    int var;
    int array1[100];
    int array2[100];
    int arraysum[100];
    int array3[100];
    int array4[100];

    int x, y, temp = 0;

    char message[100], redefined_message[100];

    char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";        // The array of English alphabets.

    srand(time(NULL));              // Generating random seed.

    puts("\n+---------------------+");
    puts("| Solitaire Algorithm |");
    puts("+---------------------+ \n \n");

    printf("Input message. ");
    gets(message);              // Taking an input string from the user.

    printf("\n");

    puts("ENCRYPTION PASS... \n");          // Encryption Pass.

    for (i = 0; i < strlen(message); i++)
    {
        if ( isalpha(message[i]) )
        {
            redefined_message[j] = message[i];    // Removing special characters and only getting the array of desired alphabets.
            j++;
        }

    }

    redefined_message[j] = '\0';  // Closing the array of the desired characters.

    for (k = 0; k < strlen(redefined_message); k++)
    {
        if (islower(redefined_message[k]))             // Converting the lower cases redefined message into uppercase characters.
        {
            redefined_message[k] = toupper(redefined_message[k]);
        }
        else
        {
            redefined_message[k] = redefined_message[k];
        }
    }

    printf("Cleaned Message.        ");     // Displaying the redefined message.

    for (l = 0; l < strlen(redefined_message); l++)
    {
        printf("%c    ", redefined_message[l]);
    }

    printf("\nLetters to Numbers.     ");       // Converting and displaying each letter into their corresponding numbers. e.g A=1, B=2 etc.

    for (l = 0; l < strlen(redefined_message); l++)
    {
        array1[l] = redefined_message[l] - 64;
        printf("%d   ", array1[l]);
    }

    printf("\nGenerated Keystreams.   ");   // Generating the deck and the keystream values.

    for (l = 0; l < strlen(redefined_message); l++)
    {
        for (x = 0; x <= 27; x++)
        {
            temp = 1 + rand() % 28;

            for (y = 0; y <= x - 1; y++)
            {
                if (deck[y] == temp)
                    break;
            }
            if (x == y)
                deck[x] = temp;
            else
                x--;
        }
        var = deck[0];
        array2[l] = deck[var+1];
        printf("%d   ", deck[var+1]);
    }

    printf("\n");

    printf("Encoded Numbers.        ");     // Encoding the message into unreadable form by first generating the integer values.

    for (l = 0; l < strlen(redefined_message); l++)
    {
        arraysum[l] = array1[l] + array2[l];
        if ( arraysum[l] > 26 )
        {
            array3[l] = arraysum[l] - 26;
            printf("%d   ", array3[l]);
        }
        else
        {
            array3[l] = arraysum[l];
            printf("%d   ", array3[l]);
        }
    }

    printf("\n");

    printf("Encoded Message.        ");     // Now, converting the encoded numbers to their respective alphabets. e.g 1=A, 2=B etc.

    for (l = 0; l < strlen(redefined_message); l++)
    {
        array4[l] = array3[l] + 64;
        printf("%c    ", array4[l]);
    }

    printf("\n \n");

    printf("DECRYPTION PASS... \n \n");     // Decryption pass.

    printf("Encoded Message.        ");     // It will show the encoded message in the form of unreadable array of characters.

    for (i = 0; i < strlen(redefined_message); i++)
    {
        printf("%c    ", array4[i]);
    }

    printf("\nLetters to Numbers.     ");   // The encoded alphabets will now be converted into their respective numbers like A=1, B=2 etc

    for (i = 0; i < strlen(redefined_message); i++)
    {
        printf("%d   ", array4[i] - 64);
    }

    printf("\nGenerated Keystreams.   ");   // Now, it will display the corresponding keystream values against each number.

    for (i = 0; i < strlen(redefined_message); i++)
    {
        printf("%d   ", array2[i]);
    }

    printf("\nDecoded Numbers.        ");       // From the keystream values, the message would be decoded in the form of numbers.

    for (i = 0; i < strlen(redefined_message); i++)
    {
        printf("%d   ", array1[i]);
    }

    printf("\nDecoded Message.        ");   // Now, each number would be converted into its respective alphabet like 1=A, 2=B etc.

    for (i = 0; i < strlen(redefined_message); i++)
    {
        printf("%c    ", redefined_message[i]);
    }

    getchar();

    return 0;
}
