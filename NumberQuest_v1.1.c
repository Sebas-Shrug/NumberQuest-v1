#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void scoringInfo(){

    printf("\n================================\n");
    printf("The initial score is always 100. Each decision you make will be counted as a turn and each turn will deduct to your final score.\n");
    printf("- Picking the wrong side in CutHalf or OddEven will deduct 15 to your score.\n");
    printf("- Choosing a number at least two points away from the dice in Gambling will deduct 50 to your final score.");
    printf("\n================================\n");

}

char unknown(char start){

    do{
            
        printf("\nInvalid Answer! Only (Y/N): ");
        scanf(" %c", &start);
            start = toupper(start);

    }while(start != 'N' && start != 'Y');

}

void errorMessage(){
    printf("Not a valid number! Please only input 1-100!\n");
}

int main () {

    int num, choice, guess = 0, turn = 0;
    char info, start, restart = 'Y';

    int twoTrue = 0,cutChoice; //Cut Half Variables
    char second [50];

    int threeTrue = 0,oeChoice; //Odd-Even Variables
    char third [50];

    int diceChoice,dice,gambleNum,counter = 0, secretPosition; //Gamble Variables

    int score = 100, winner = 0;
    

    printf("Welcome to number quest!!\n");
    printf("I will generate a number from 1-100, you must guess which number it is!\n");
    printf("You'll be able to ask qustions to help you narrow it down! But be careful as you might be unlucky enough to be deducted in your final score!\n");
    printf("Would you like to more about the scoring system (Y/N)? ");
    scanf(" %c", &info);

    info = toupper(info);

    if(info != 'N' && info != 'Y'){

        unknown(info);

    }

    if(info == 'Y'){

        scoringInfo();

    }

    printf("\nWould you like to play(Y/N)? ");
    scanf(" %c", &start);

    start = toupper(start);

    if(start != 'N' && start != 'Y'){

        unknown(start);

    }

    if(start == 'N'){
        printf("\nGoodbye!");
        return 0;
    }

    srand(time(NULL));
    num = rand() % 100 + 1;

    do{

        if(winner > 0){

            num = rand() % 100 + 1;
            guess = 0;
            turn = 0;
            score = 100;
            twoTrue = 0;
            threeTrue = 0;

            printf("================================\n");
            printf("\nWould you like to keeep playing(Y/N)? ");
            scanf(" %c", &restart);

            restart = toupper(restart);

            if(restart != 'N' && restart != 'Y'){

            do{
                
                printf("\nInvalid Answer! Only (Y/N): ");
                scanf(" %c", &restart);
                restart = toupper(restart);

            }while(restart != 'N' && restart != 'Y');

            }

        }

        if(restart == 'Y'){

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
                        else if(num < 50){
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
                            secretPosition = rand()%10 + 1;
                            counter = 0;
                            
                            do{

                                counter+=1;
                                gambleNum = rand()%100 + 1;

                                if(counter == secretPosition){
                                    printf("%d ",num);
                                }

                                else{
                                    printf("%d ",gambleNum);
                                }

                            }while(counter <= 9);

                            printf("Your number is in this bundle of numbers! Go whats your guess? ");
                            scanf("%d", &guess);

                            if(guess != num){
                                printf("You had all that help and still didn't guess it?? WTH!!\n");
                            }
                            else{
                                printf("\nWHAT NO WAY!!! YOU GOT IT!!\n");
                            }

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

            printf("\n================================\n");

            if(score == 100){
                printf("YOU SCORED PERFECTLY!!!! CONGRATULATIONS!!!\n");
                printf("You're the goat of Number Quest W W W W W W W\n");
                printf("Total score: 100/100!!!!!\n",score);
            }

            else if(score < 100 && score >= 75){
                printf("YOU GOT A GOOD SCORE BE PROUD OF YOURSELF G\n");
                printf("Total score: %d/100!!!!!\n",score);
            }

            else if(score >= 50 && score < 75){
                printf("YOU PASSED CONGRATULATIONS!!\n");
                printf("Dont be disheartend with your score, surprisingly you'd still surpass 90%% of people playing this!\n");
                printf("Total score: %d/100!!!!!\n",score);
            }

            else if(score < 50 && score >= 25){
                printf("Awww brother we couldn't even meet halfway at least?\n");
                printf("Nice try I guess! Hey it couldve be way worse lol\n");
                printf("Total score: %d/100!!!!!\n",score);
            }

            else if(score >= 1 && score < 25){
                printf("Oh..... Thats rough\n");
                printf("On the bright side, it aint a zero!\n");
                printf("Hey stay positive!\n");
                printf("Total score: %d/100!!!!!\n",score);
            }

            else{
                printf("Yea you are absolutely horrendous\n");
                printf("How do you manage to score negative in a game about guessing numbers?\n");
                printf("Dont touch a keyboard ever again wallah\n");
                printf("Total score: 0/100!!!!!\n");
            }

            winner+=1;
        }

    }while(restart != 'N');    

    printf("\nThanks for playing! Goodbye!");

}
