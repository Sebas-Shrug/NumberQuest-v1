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

    }while(start != 'Y' && start != 'N');

}

int main () {

    int num, choice, guess = 0, turn = 0, guesses[101], remainNum[101], match = 0, foundNum = 0;
    char info, start, restart = 'Y';

    int valid = 0; //guess variables

    int twoTrue = 0,cutChoice; //Cut Half Variables
    char second [50];

    int threeTrue = 0,oeChoice; //Odd-Even Variables
    char third [50];

    int diceChoice, dice, gambleNum, counter = 1, secretPosition, gold = 0, storedNumber[12], lucky = 0, divide = 1, gambleFound = 0, showedNum[101], innerCounter = 0; //Gamble Variables

    int newLine, listNum, add, listIncr = 0, listFound = 0, space = 0; //List Variables

    int score = 100, winner = 0;

    int debug = 0;

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

        start = unknown(start);

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
            divide = 0;
            lucky = 0;
            gold = 0;
            space = 0;
            listIncr = 0;
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

            unknown(restart);

            }

        }

        if(restart == 'Y'){

        do{

            if(twoTrue > 0 && threeTrue > 0){
            printf("\n================================\n");
            printf("Turn: %d; Score: %d\n", turn,score);
            printf("What would you like to do?\n");
            printf("1. Guess the number\n");
            printf("2. You already used this! The number is %s 50\n",second);
            printf("3. You already used this! The number is an %s number\n",third);
            printf("4. Gamble gamble gamble!!\n");
            printf("5. Check valid numbers\n");
            printf("What would you like to do(1, 4 or 5)? ");
            scanf("%d", &choice);

            if(choice != 1 && choice != 4 && choice != 5){
            
                do{

                    printf("\nInvalid answer!");
                    printf("Only 1, 4 or 5: ");
                    scanf("%d", &choice);

                }while(choice != 1 && choice != 4 && choice != 5);

            }

            }

            else if(twoTrue > 0){
            printf("\n================================\n");
            printf("Turn: %d; Score: %d\n", turn,score);
            printf("What would you like to do?\n");
            printf("1. Guess the number\n");
            printf("2. You already used this! The number is %s 50\n",second);
            printf("3. Odd or Even!\n");
            printf("4. Gamble gamble gamble!!\n");
            printf("5. Check valid numbers\n");
            printf("What would you like to do(1, 3, 4 or 5)? ");
            scanf("%d", &choice);

            if(choice != 1 && choice != 4 && choice != 3 && choice != 5){
            
                do{
                    printf("\nInvalid answer!");
                    printf("Only 1, 3, 4 or 5: ");
                    scanf("%d", &choice);

                }while(choice != 1 && choice != 4 && choice != 3 && choice != 5);

            }

            }

            else if(threeTrue > 0){
            printf("\n================================\n");
            printf("Turn: %d; Score: %d\n", turn,score);
            printf("What would you like to do?\n");
            printf("1. Guess the number\n");
            printf("2. Cut in half!\n");
            printf("3. You already used this! The number is an %s number\n",third);
            printf("4. Gamble gamble gamble!!\n");
            printf("5. Check valid numbers\n");
            printf("What would you like to do(1, 3, 4 or 5)? ");
            scanf("%d", &choice);

            if(choice != 1 && choice != 4 && choice != 2 && choice != 5){
            
                do{
                    printf("\nInvalid answer!");
                    printf("Only 1, 2, 4 or 5!!: ");
                    scanf("%d", &choice);

                }while(choice != 1 && choice != 4 && choice != 2 && choice != 5);

            }

            }

            else{

            printf("\n================================\n");
            printf("Turn: %d; Score: %d\n", turn,score);
            printf("What would you like to do?\n");
            printf("1. Guess the number\n");
            printf("2. Cut in half!\n");
            printf("3. Odd or Even!\n");
            printf("4. Gamble gamble gamble!!\n");
            printf("5. Check valid numbers\n");
            
            printf("What would you like to do? ");
            scanf("%d", &choice);

            if(choice < 1 || choice > 5){
            
                do{
                    printf("Invalid answer!");
                    printf("Only 1-5: ");
                    scanf("%d", &choice);

                }while(choice < 1 || choice > 5);

            }


        }

        for(int i = 0; i<=100 ; i++){

            if(twoTrue == 1 && i < 50){ //Removes less than 50
                
                remainNum[i] = -1;

            }

            else if(twoTrue == 2 && i > 50){ //Removes more than 50
                
                remainNum[i] = -1;

            }

            else if(threeTrue == 1 && i % 2 > 0){ //Removes odd numbers

                remainNum[i] = -1;

            }

            else if(threeTrue == 2 && i % 2 == 0){ //Removes even numbers

                remainNum[i] = -1;

            }
                    
            else{

                for(int j = 0; j <= 100; j++){

                    if(lucky > 0){

                        for(int x = 0; x <= counter; x++){

                            if(i == storedNumber[x]){
                                match = 0;
                                foundNum = storedNumber[x];
                                break;
                            }

                            else{
                                match = 1;
                            }    

                        }

                    }

                    else if(i == guesses[j]){

                        match = 1;
                        break;

                    }

                    if(foundNum > 0){

                        if(foundNum == guesses[j]){
                            match = 1;
                            break;
                        }

                    }

                } 

                    if(match == 1){
                        remainNum[i] = -1;
                    }

                    else{
                        remainNum[i] = i;
                    }

                    match = 0;
                    foundNum = 0;

            }
                                        
        }

        /*for(int i = 1; i<=100 ; i++){

            printf("%d\n", remainNum[i]);

        }*/   //Debugger

            if(choice == 1){

                    do{

                        valid = 0;

                        printf("\nWhat would your guess be? ");
                        scanf("%d", &guess);

                        guesses[turn] = guess;

                        for(int d = 1; d <= 101; d++){

                            if(guess == remainNum[d]){

                                valid = 1;
                                break;

                            }

                        }

                        if(!valid){

                            if(guess < 1 || guess > 100){

                                printf("Not a valid number! Please only input 1-100!\n");

                            }

                            else{

                                printf("%d has already been excluded from the list, try a different number!\n", guess);

                            }

                        }

                    }while(!valid);

                    if(guess != num){

                        printf("You got it wrong! Try again!\n");
                        turn+=1;

                    }
                    
                    else{

                        printf("Congratulations you got it!!!!\n");

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
                            twoTrue = 1;
                        }
                        else if(num < 50){
                            strcpy(second, "LESS THAN");
                            twoTrue = 2;
                        }

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
                            threeTrue = 1;

                        }

                        else{

                            strcpy(third, "ODD");
                            threeTrue = 2;

                        }
                    
                    }

                    if(choice == 4){

                        printf("\nGAMBLE GAMBLE GAMBLE!!!!\n");
                        printf("I just rolled a dice... Guess what number its on and test your luck..\n");

                        dice = rand()%6 + 1;
                         printf("\n%d\n", dice); //debugger

                        do{

                            printf("Enter a number(1-6): ");
                            scanf("%d", &diceChoice);

                            if(diceChoice < 1 || diceChoice > 6){

                                printf("Invalid number!\n");

                            }

                        }while(diceChoice < 1 || diceChoice > 6);

                        if(dice == diceChoice){

                            printf("GOLDDDD GOLDDDD GOLDDDD GOLDDDD GOLDDDD!!!!!!\n");
                            printf("YOU STRUCK THE JACKPOT!!\n");
                            guess = num;
                            gold = 1;

                        }

                        else if(dice == diceChoice - 1 || dice == diceChoice + 1){

                            for(int c = 1; c <= counter; c++){ //resets everything for a brand new list

                                storedNumber[c] = -1;

                            }

                            counter = 1;

                            printf("Close enough!! So I'll help you out a bit!!\n");

                            if(lucky == 0){

                                secretPosition = rand()%10 + 1;

                            }

                            else if(lucky == 1){

                                secretPosition = rand()%5 + 1;

                            }

                            else if(lucky == 2){

                                secretPosition = rand()%3 + 1;

                            }

                            lucky+=1;
                            
                            do{

                                do{

                                    gambleFound = 0;
                                    innerCounter++;

                                    gambleNum = rand()%100 + 1;

                                    for(int a = 1; a <= 101; a++){

                                        if(gambleNum == remainNum[a] && gambleNum != num){ //only accepts numbers that havent been guessed and isnt the number

                                            gambleFound = 1;
                                            break;

                                        }
                                        
                                    }

                                    if(gambleFound == 1){

                                        for(int b = 1; b <= innerCounter; b++){

                                            if(showedNum[b] == gambleNum){

                                                showedNum[innerCounter] = -1; //if a number already showed is the same as the randomized Number, find another number
                                                gambleFound = 0;
                                                break;
                        
                                            }

                                        }

                                        if(gambleFound == 1){

                                            showedNum[innerCounter] = gambleNum;

                                        }

                                    }

                                }while(!gambleFound);

                                if(counter == secretPosition){

                                    printf("%d ",num);
                                    storedNumber[counter] = num;
                                    
                                }

                                else{

                                    printf("%d ",gambleNum);
                                    storedNumber[counter] = gambleNum;

                                }

                                counter+=1;

                            }while(counter <= 10 / divide);

                            printf("\nYour number is in this pool! ");

                            do{

                                valid = 0;

                                printf("What would your guess be? ");
                                scanf("%d", &guess);

                                guesses[turn] = guess;

                                for(int d = 1; d <= counter; d++){

                                    if(guess == storedNumber[d]){

                                        valid = 1;
                                        break;

                                    }

                                }

                                if(!valid){

                                    if(guess < 1 || guess > 100){

                                        printf("Not a valid number! Please only input 1-100!\n");
                                        break;

                                    }

                                    else{

                                        printf("Are you blind! %d is not a part of the pool!! Try again!\n", guess);  

                                    }

                                }

                            }while(!valid);

                            if(guess != num){

                                printf("You got it wrong! Try again!\n");

                            }
                            
                            else{

                                printf("Congratulations you got it!!!!\n");

                            } 

                            turn+=1;
                            divide++;

                            for(int c = 1; c <= innerCounter; c++){ //resets everything for a brand new list

                                showedNum[c] = -1;

                            }

                            innerCounter = 0;

                        }

                        else{
                            printf("You hit the absolute stinker!!!! You should never gamble again!!!\n");
                            score-=50;

                            turn+=1;
                        }

                    }

                    if(choice == 5){

                        printf("\n================================\n");
                        printf("Here is the list of all the numbers left:\n\n");

                        for (newLine = 1; newLine <= 10; newLine++) {

                            if(space == 0){

                                for(listNum = 1; listNum <=10 ; listNum++){

                                    add = listNum + listIncr;
                                
                                    for(int i = 0; i <= turn; i++){

                                        if(guesses[i] == add){
                                            listFound = 1;
                                        }

                                        else if(lucky > 0 && listFound == 0){
                                    
                                            for(int i = 1; i <= counter; i++){

                                                if(storedNumber[i] == add){
                                                    listFound = 0;
                                                    break;
                                                }
                                            
                                                else if(storedNumber[i] != add){
                                                    listFound = 1;
                                                }

                                            }

                                        }

                                    }

                                        if(twoTrue == 1 && add < 50){
                                            printf("   ");
                                        }

                                        else if(threeTrue == 2 && add % 2 == 0){
                                            printf("   ");
                                        }

                                        else if(threeTrue == 1 && add % 2 > 0){
                                            printf("   ");
                                        }

                                        else if(listFound == 1){
                                            printf("   ");
                                        }
                                        
                                        else{
                                            printf("%d  ",add);
                                        }

                                    listFound = 0;

                                }

                            }

                            else{

                                for(listNum = 1; listNum <=10 ; listNum++){

                                    add = listNum + listIncr;
                                
                                    for(int i = 0; i <= turn; i++){

                                        if(guesses[i] == add){
                                            listFound = 1;
                                        }

                                        else if(lucky > 0 && listFound == 0){
                                    
                                            for(int i = 1; i <= counter; i++){

                                                if(storedNumber[i] == add){
                                                    listFound = 0;
                                                    break;
                                                }
                                            
                                                else if(storedNumber[i] != add){
                                                    listFound = 1;
                                                }

                                            }

                                        }

                                    }
                                
                                        if(twoTrue == 1 && add < 50){
                                            printf("   ");
                                        }

                                        else if(threeTrue == 2 && add % 2 == 0){
                                            printf("   ");
                                        }

                                        else if(threeTrue == 1 && add % 2 > 0){
                                            printf("   ");
                                        }

                                        else if(twoTrue == 2 && add > 50){
                                            printf("   ");
                                        }

                                        else if(listFound == 1){
                                            printf("   ");
                                        }

                                        else{
                                            printf("%d ",add);
                                        }

                                    listFound = 0;

                                }

                            }
  
                        printf("\n");
                        listIncr+=10;
                        space = 1;

                        }

                    }

                space = 0;
                listIncr = 0;

                if(choice != 5 && gold != 1){
                    score--;
                }

            }while(guess != num);

            printf("\n================================\n");
            printf("The number was %d!!\n",num);

            if(score == 100){
                printf("YOU SCORED PERFECTLY!!!! CONGRATULATIONS!!!\n");
                printf("You're the goat of Number Quest W W W W W W W\n");
                printf("Total score: 100/100!!!!!\n");
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

    return 0;

}
