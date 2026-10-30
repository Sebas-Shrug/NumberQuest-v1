#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void errorMessage(){
    printf("Not a valid number! Please only input 1-100!\n");
}

int main () {

    int num, counter = 0; 
    int choice, guess = 0, turn = 0,cutChoice,oeChoice,diceChoice,dice,gambleNum;
    int twoTrue = 0, threeTrue = 0;
    char second [50];
    char third [50];
    int score = 100;
    

    printf("Lets play a game!\n");
    printf("I will generate a number from 1-100, you must guess which number it is!\n");
    printf("Theres a twist! You can use questions to narrow it down.\n");
    printf("But asking questions will deduct your final points!\n");
    printf("Lets start!\n");

    srand(time(NULL));
    num = rand() % 100 + 1;

    do{

        if(twoTrue == 1 && threeTrue == 1){
        printf("\n================================\n");
        printf("Turn: %d\n", turn);
        printf("What would you like to do?\n");
        printf("1. Guess the number\n");
        printf("2. You already used this! The number is %s 50\n",second);
        printf("3. You already used this! The number is an %s number\n",third);
        printf("4. Gamble gamble gamble!!\n");
        printf("What would you like to do(1 or 4)? ");
        scanf("%d", &choice);

        if(choice != 1 && choice != 4){
        
            do{
                printf("Invalid answer!");
                printf("Only 1 or 4!!: ");
                scanf("%d", &choice);

            }while(choice != 1 && choice != 4);

        }

        }

        else if(twoTrue == 1){
        printf("\n================================\n");
        printf("Turn: %d\n", turn);
        printf("What would you like to do?\n");
        printf("1. Guess the number\n");
        printf("2. You already used this! The number is %s 50\n",second);
        printf("3. Odd or Even!\n");
        printf("4. Gamble gamble gamble!!\n");
        printf("What would you like to do(1, 3 or 4)? ");
        scanf("%d", &choice);

        if(choice != 1 && choice != 4 && choice != 3){
        
            do{
                printf("Invalid answer!");
                printf("Only 1, 3 or 4!!: ");
                scanf("%d", &choice);

            }while(choice != 1 && choice != 4 && choice != 3);

        }

        }

        else if(threeTrue == 1){
        printf("\n================================\n");
        printf("Turn: %d\n", turn);
        printf("What would you like to do?\n");
        printf("1. Guess the number\n");
        printf("2. Cut in half!\n");
        printf("3. You already used this! The number is an %s number\n",third);
        printf("4. Gamble gamble gamble!!\n");
        printf("What would you like to do(1, 3 or 4)? ");
        scanf("%d", &choice);

        if(choice != 1 && choice != 4 && choice != 2){
        
            do{
                printf("Invalid answer!");
                printf("Only 1, 2 or 4!!: ");
                scanf("%d", &choice);

            }while(choice != 1 && choice != 4 && choice != 2);

        }

        }

        else{

        printf("\n================================\n");
        printf("Turn: %d\n", turn);
        printf("What would you like to do?\n");
        printf("1. Guess the number\n");
        printf("2. Cut in half!\n");
        printf("3. Odd or Even!\n");
        printf("4. Gamble gamble gamble!!\n");
        printf("What would you like to do? ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 4){
        
            do{
                printf("Invalid answer!");
                printf("Only 1, 2, 3 or 4!!: ");
                scanf("%d", &choice);

            }while(choice < 1 || choice > 4);

        }

        }

        if(choice == 1){

            do{

            printf("\nWhat would your guess be? ");
            scanf("%d", &guess);

            if(guess < 1 || guess > 100){
                errorMessage();
            }

            }while(guess < 1 || guess > 100);

            if(guess != num){
                printf("You got it wrong! Try again!\n");
                turn+=1;
            }

        }

        if(choice == 2){

                printf("\nCut in Half!\n");
                printf("If you pick the right side you wont get any score deductions!!\n");

                do{

                printf("Would you like to go (1)Higher or (2)Lower than 50 (Type the number): ");
                scanf("%d", &cutChoice);

                if(cutChoice <=0 || cutChoice >= 3){
                    printf("Only answer 1 or 2!!\n");
                }

                }while(cutChoice <=0 || cutChoice >= 3);

                if(num == 50){
                    printf("NO WAYYY!!! YOU GOT SO LUCKY!!!\n");
                    printf("ITS RIGHT IN BETWEEN! THE NUMBER IS 50!!\n");

                    guess = num;

                }

                else if(cutChoice == 1){

                    if(num > 50){
                        printf("The number IS higher than 50!\n");
                        printf("No point deduction for getting it right!!\n");
                    }
                    else{
                        printf("The number IS lower than 50!\n");
                        printf("Point deduction for getting it wrong!!\n");
                        score-=15;
                    }

                    turn+=1;

                }

                else if(cutChoice == 2){

                    if(num > 50){
                        printf("The number IS higher than 50!\n");
                        printf("Point deduction for getting it wrong!!\n");
                        score-=15;
                    }
                    else{
                        printf("The number IS lower than 50!\n");
                        printf("No point deduction for getting it right!!\n");
                    }

                    turn+=1;

                }

                if(num > 50) {
                    strcpy(second, "MORE THAN");
                }
                else{
                    strcpy(second, "LESS THAN");
                }

                twoTrue+=1;

            }

            if(choice == 3){

                printf("\nOdd or Even!\n");
                printf("If you pick the right side you wont get any score deductions!!\n");

                do{

                printf("Would you like to go (1)Even or (2)Odd (Type the number): ");
                scanf("%d", &oeChoice);

                if(oeChoice <=0 || oeChoice >= 3){
                    printf("Only answer 1 or 2!!\n");
                }

                }while(oeChoice <=0 || oeChoice >= 3);

                if(oeChoice == 1){

                    if(num % 2 == 0){
                        printf("The number IS an even number!\n");
                        printf("No point deduction for getting it right!!\n");
                    }
                    else{
                        printf("The number IS an odd number!\n");
                        printf("Point deduction for getting it wrong!!\n");
                        score-=15;
                    }

                    turn+=1;

                }

                if(oeChoice == 2){

                    if(num % 2 == 0){
                        printf("The number IS an even number!\n");
                        printf("Point deduction for getting it wrong!!\n");
                        score-=15;
                    }
                    else{
                        printf("The number IS an odd number!\n");
                        printf("No point deduction for getting it right!!\n");
                    }

                    turn+=1;

                }

                if(num % 2 == 0) {
                strcpy(third, "EVEN");
                }
                else {
                    strcpy(third, "ODD");
                }

                threeTrue+=1;
            
            }

            if(choice == 4){
                printf("\nGAMBLE GAMBLE GAMBLE!!!!\n");
                printf("I just rolled a dice... Guess what number its on and test your luck..\n");

                do{
                printf("Enter a number(1-6): ");
                scanf("%d", &diceChoice);

                if(diceChoice < 1 || diceChoice > 6){
                    printf("Invalid number!\n");
                }
                }while(diceChoice < 1 || diceChoice > 6);

                dice = rand()%6 + 1;

                if(dice == diceChoice){
                    printf("GOLDDDD GOLDDDD GOLDDDD GOLDDDD GOLDDDD!!!!!!\n");
                    printf("YOU STRUCK THE JACKPOT!!! THE NUMBER IS %d!!!!\n", num);
                    guess = num;
                }

                else if(dice == diceChoice - 1 || dice == diceChoice + 1){

                    printf("Close enough!! So I'll help you out a bit!!\n");

                    counter = 0;
                    
                    do{
                        
                        gambleNum = rand()%100 + 1;
                        printf("%d ",gambleNum);
                        counter+=1;

                    }while(counter <= 7);

                    printf("%d\n",num);
                    printf("Your number is in these bundle of numbers! Go guess!\n");

                    turn+=1;

                }

                else{
                    printf("You hit the absolute stinker!!!! You should never gamble again!!!\n");
                    score-=50;

                    turn+=1;
                }

        }

    }while(guess != num);

    score-=turn;

    printf("Congratulations! You did it!\n");
    printf("The number was %d!\n", num);
    printf("Total score: %d/100",score);

}