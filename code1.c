/*Hannah Prosch 
EECS 148 Lab4
October 5, 2024*/

#include <stdio.h>

int main() {
    float counter = 0;
    float td8 = 8;
    float td7 = 7;
    float td6 = 6;
    float fg3 = 3;
    float s2 = 2; 


    float score = -1;

    do {
        printf("\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%f", &score);

        /*Ends loop if user enters a 0 or 1.*/
        if (score == 0 || score == 1) {
             break;
        }

        printf("\nPossible combinations of scoring if a team's score is %.0f\n", score);

        /*Loop for Touch Down work 8 points*/
        for (int f = 0; f <= score; f++) {

            /*Loop for Touch Down worth 7 points*/
            for (int g = 0; g <= score; g++) {

                /*Loop for Touch Down worth 6 points*/
                for (int h = 0; h <= score; h++) {

                    /*Loop for Field Goals*/
                    for (int i = 0; i <= score; i++) {

                        /*Loop for Safety*/
                        for (int j = 0; j <= score; j++) {

                            /*Calculates the score as we loop through*/
                            counter = (f * td8) + (g * td7) + (h * td6) + (i * fg3) + (j * s2);
                            
                            /*Prints resulting line only if counter equals
                            the total of the score entered by user*/
                            if (counter == score) {
                                printf("\n%i TD + 2pt, %i TD + FG, %i TD, %i 3pt FG, %i Safety", f, g, h, i, j);
                                counter = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        
    } while (score !=0 && score != 1);
}