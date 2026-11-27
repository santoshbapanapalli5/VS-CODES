#include <stdio.h>
#include <string.h> // Added to find the string length easily

int main()
{
    printf("give a string: ");
    char string[100];
    // FIX 1: Removed the '&' from string (arrays don't need it) and read spaces using %[^\n]
    scanf(" %[^\n]", string);

    // Track the new length of our cleansed string
    int new_len = 0;

    // FIX 2: Loop until the end of the string ('\0') rather than exactly 100 times
    for (int i = 0; string[i] != '\0'; i++)
    {

        // FIX 3: Changed 91 to 90 ('Z' is 90)
        if (string[i] >= 65 && string[i] <= 90)
        {
            string[new_len] = string[i] + 32;
            new_len++;
        }
        // FIX 4: Kept valid lowercase letters and numbers
        else if ((string[i] >= 97 && string[i] <= 122) || (string[i] >= 48 && string[i] <= 57))
        {
            string[new_len] = string[i];
            new_len++;
        }
        // FIX 5: If it is a symbol, we don't increase 'new_len' (overwriting the symbol)
    }
    string[new_len] = '\0'; // Properly terminate the cleansed string

    printf("Cleansed: %s\n", string);

    // FIX 6: Added the required Palindrome Check using basics
    int is_palindrome = 1;
    for (int i = 0; i < new_len / 2; i++)
    {
        if (string[i] != string[new_len - 1 - i])
        {
            is_palindrome = 0; // Mismatch found
            break;
        }
    }

    // Output the final requirement
    if (is_palindrome && new_len > 0)
    {
        printf("symmetric signature detected\n");
    }
    else
    {
        printf("standard payload\n");
    }

    return 0;
}