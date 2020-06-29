/*Assignment 2 for Data Structures and Algorithm Development C
 * Author: Manpreet Kaur
 * Date: June 18, 2020
 * Description: This program collects the information for a census bureau which should
 * obtain and analyze household information within the Greater Toronto Area
 *
 * This takes the first 5 inputs from user if they want to enter, if they do not want
 * to enter values it can generates all the values randomly.
 *
 * It also calculates the the averages of incomes based on regions and does the other calculations like
 * calculating basis of poverty, percentage of households below poverty by race etc.
 */

//header files required for this application
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kaur484.h"

//main method of the application
int main(int argc, char *argv[])
{
    //declaring the variables required for application
    //this variable keep count of the entries in the array of data
    int numberOfEntries;
    //storing the user selection in this variable like 0, 1 etc
    int choice;
    household data[MAXIMUM_ENTRIES];

    //seeding the random generator
    srand((unsigned) time(0));

    //assigning the initial value for the variable
    numberOfEntries = 0;

    while (numberOfEntries < MAXIMUM_ENTRIES)
    {
        printf("Do you want to fill the entries with Random Generator? \n Enter 0 for YES and 1 for NO: (0-Yes, 1-No): ");
        choice = readInput(0, 1);

        //If user enters then break the loop. Then user have to select the values for data
        if (choice == 0)
            break;

        //entering the data from user in the 'data[]'
        data[numberOfEntries++] = readUserHousehold();
    }

    //This loop fill the array with Random Information
    for (; numberOfEntries < MAXIMUM_ENTRIES; numberOfEntries++)
        //loop is going till the maximum entrires and filling the data in 'data[]'
        data[numberOfEntries] = generateRandomHousehold();

    //calling the function to print the data
    printHouseholdData(data);

   //Menu for the user, They can choose any option they like and enter 0 to exit the program
   //this loop will run till the condition is true
    while (TRUE)
    {
        //display menu for the user
        printf("\n*****************Menu*****************\n");
        printf("1. Households by region\n");
        printf("2. Households by race\n");
        printf("3. Average household income\n");
        printf("4. Average household by town and region\n");
        printf("5. Average household income by race\n");
        printf("6. Percentage of households below poverty\n");
        printf("7. Percentage of households below poverty by race\n");
        printf("8. Percentage of households below poverty by town and region\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        //this sets the limit on user input, minimum number user can enter is 0 and maximum is 8, any other number will error
        choice = readInput(0, 8);

        //this will executes the methods from census.c file according to the user's choice

        //if user enters 0, it will break the loop and this will end program
        if (choice == 0)
        {
            break;
        }

        //if user enters 1 this will calculates the number of households by region
        if (choice == 1)
        {
            //call the function houseHoldByRegion and pass the "data"
            householdByRegion(data);
        }

        //if user enters 2 this will calculates the number of households by race
        else if (choice == 2)
        {
            //call the function householdByRace and pass the "data"
            householdByRace(data);
        }

        //if user enters 3 this will calculates the average households incomes
        else if (choice == 3)
        {
            //call the function averageHouseholdIncome and pass the "data"
            averageHouseholdIncome(data);
        }

        //if user enters 4 this will calculates the average households incomes town and region
        else if (choice == 4)
        {
            //call the function averageIncomeByTownRegion and pass the "data"
            averageIncomeByTownRegion(data);
        }

        //if user enters 5 this will calculates the average household income by race
        else if (choice == 5)
        {
            //call the function averageIncomeByRace and pass the "data"
            averageIncomeByRace(data);
        }

        //if user enters 6 this will calculates the percentage of households below poverty
        else if (choice == 6)
        {
            //call the function householdBelowPoverty and pass the "data"
            householdBelowPoverty(data);
        }

        //if user enters 7 this will calculates the percentage of households below poverty by race
        else if (choice == 7)
        {
            //call the function householdPovertyByRace and pass the "data"
            householdPovertyByRace(data);
        }

        //if user enters 8 this will calculate the Percentage of households below poverty by town and region
        else if (choice == 8)
        {
            //call the function householdPovertyByTownRegion and pass the "data"
            householdPovertyByTownRegion(data);
        }

        //if user does not enter anything it will give error and ask for the number again
        else {
            //error message
            printf("Invalid Option! Please enter the Correct number.\n");
        }

    }//while loop ends here

    return 0;
}//main method ends here