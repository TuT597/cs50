#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardNumber = get_long("Enter card number: ");

    // Variables i will use for running my checks and generating a response
    int numberLength;
    string cardType;
    int firstNumbers;
    bool passedLuhns;

    // Variables i will use for my Luhn's algorithm
    long multi = 1;
    int luhnOdd = 0;
    int luhnEven = 0;

    // Check if the card is of a valid length
    if (cardNumber >= 1000000000000000 && cardNumber < 10000000000000000)
    {
        // Assign variables
        numberLength = 16;
        // Pick out the first numbers
        firstNumbers = cardNumber / 100000000000000;

        // If the first numbers match a card supplier assign that card type
        if ((firstNumbers > 50 && firstNumbers < 56) || firstNumbers / 10 == 4)
        {
            // Check which card it is
            if (firstNumbers > 50)
            {
                cardType = "MASTERCARD";
            } 

            else if (firstNumbers / 10 == 4)
            {
                cardType = "VISA";
            }

            // Check if the number passes Luhn's algorithm
            for (int i = 0; i < numberLength; i++)
            {
                // Grab the last digit moving left 1 spot every loop
                int x = (cardNumber / multi) % 10;
                // Check for odd or even
                if (i % 2 == 1)
                {
                    // Check to see if the number is higher than 9
                    int doubled = x * 2;
                    if (doubled > 9)
                    {
                        luhnOdd += doubled - 9;
                    }

                    else 
                    {
                        luhnOdd += x * 2;
                    }
                }
                
                else
                {
                    luhnEven += x;
                }

                // Increase multi so we go a digit to the left
                multi *= 10;    
            }

            // Check to see if the test has been passed
            if ((luhnOdd + luhnEven) % 10 == 0)
            {
                printf("%s\n", cardType);
            }

            // If not print invalid
            else
            {
                printf("INVALID\n");
            }
        }

        // If these checks fail print INVALID
        else
        {
            printf("INVALID\n");
        }
    }

    // Check for different card lengths
    else if (cardNumber >= 100000000000000 && cardNumber < 1000000000000000)
    {
        numberLength = 15;
        firstNumbers = cardNumber / 10000000000000;

        // Assign right card
        if (firstNumbers == 34 || firstNumbers == 37)
        {
            cardType = "AMEX";

            // Check if the number passes Luhn's algorithm
            for (int i = 0; i < numberLength; i++)
            {
                int x = (cardNumber / multi) % 10;
                if (i % 2 == 1)
                {
                    int doubled = x * 2;
                    if (doubled > 9)
                    {
                        luhnOdd += doubled - 9;
                    }

                    else 
                    {
                        luhnOdd += x * 2;
                    }
                }
                
                else
                {
                    luhnEven += x;
                }

                multi *= 10;    
            }

            if ((luhnOdd + luhnEven) % 10 == 0)
            {
                printf("%s\n", cardType);
            }

            else
            {
                printf("INVALID\n");
            }        
        }

        else
        {
            printf("INVALID\n");
        } 
    }

    else if (cardNumber >= 1000000000000 && cardNumber < 10000000000000)
    {
        numberLength = 13;
        firstNumbers = cardNumber / 1000000000000;

        if (firstNumbers == 4)
        {
            cardType = "VISA";

            // Check if the number passes Luhn's algorithm
            for (int i = 0; i < numberLength; i++)
            {
                int x = (cardNumber / multi) % 10;
                if (i % 2 == 1)
                {
                    int doubled = x * 2;
                    if (doubled > 9)
                    {
                        luhnOdd += doubled - 9;
                    }

                    else 
                    {
                        luhnOdd += x * 2;
                    }
                }
                
                else
                {
                    luhnEven += x;
                }

                multi *= 10;    
            }

            if ((luhnOdd + luhnEven) % 10 == 0)
            {
                printf("%s\n", cardType);
            }

            else
            {
                printf("INVALID\n");
            }
        }

        else
        {
            printf("INVALID\n");
        }
    }

    // Card number is not of a valid length so INVALID is printed
    else
    {
        printf("INVALID\n");
    }
}