#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("How high should the pyramids be: ");
    if (height < 1)
    {
        do
        {
            height = get_int("Please enter a number above 1");
        }

        while (height < 1);
    }

    // Every loop here generates a row
    for (int row = 0; row < height; row++)
    {
        // This i use for the left and right side of the pyramid
        for (int i = 0; i < 2; i++) 
        {
            // Check if i'm on the left or right
            if (i == 0)
            {
                // This generates the spaces and #
                for (int j = 0; j < height; j++)
                {
                    if (j < height - (row + 1))
                    {
                        printf(" ");
                    }

                    else
                    {
                        printf("#");
                    }
                }
                // Pyramid gap should only follow the left side
                printf("  ");
            }
            else if (i == 1) 
            {
                for (int k = 0; k < height; k++)
                {
                    if (k < row + 1)
                    {
                        printf("#");
                    }

                    else
                    {
                        continue;
                    }
                }
            }
        }
        // To finish the row i go to the next line
        printf("\n");
    }
}