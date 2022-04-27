#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool uChars(string str);

int main(int argc, string argv[])
{
    string Pt;
    //get key

    if (argc != 2)
    {
            printf("usage: ./substitution key\n");
            return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for(int i = 0; i < strlen(argv[1]); i++ )
            {
                if (isdigit(argv[1][i])||uChars(argv[1])==false)
                {
                    printf("Key must contain 26 unique alphabetical characters.\n");
                    return 1;
                }

            }


        Pt = get_string("plaintext: ");

    }
    int x = 0;
    int KEY;
    char Key[26];
    strcpy(Key,argv[1]);

    while (Key[x])
    {
        KEY = Key[x];
        int UP = toupper(KEY)-65-x;
        Key[x] = UP;
        x++;
    }
    int ii = 0;
    int Ct;
    int Ctx[strlen(Pt)];

    while (Pt[ii])
        {
            Ct = Pt[ii];
            if(isalpha(Pt[ii]))
            {
                int Up = (Pt[ii] + Key[toupper(Pt[ii])-65]);
                Pt[ii] = Up;
            }
        ii++;
        }


    //printf("Ct: %d\n", Ct);
   printf("ciphertext: %s\n", Pt);
   //printf("Key: %i, %i\n",Key[0], Key[25]);

}


bool uChars(string str)
{

    // If at any time we encounter 2
    // same characters, return false
    for (int i = 0; i < strlen(str) - 1; i++) {
        for (int j = i + 1; j < strlen(str); j++) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }
    return true;
}