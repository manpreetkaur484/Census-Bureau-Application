/*
 * Author: Manpreet Kaur
 * Date: June 18, 2020
 * Description: This program collects the information for a census bureau which should
 * obtain and analyze household information within the Greater Toronto Area
 *
 * This file contains all the functions required for to run the main.c
 * This file separates the main method from all other implementation methods
 */

//Header files required for this file
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "kaur484.h"

//This function clear the buffered entries in input
void clearBuffer()
{
    int x;
    while ((  x = getchar()) != '\n' && x != EOF)
    {
    }//while ends

}//clearBuffer function ends




//This function sets the value for minimum and maximum inputs that user can enter
int readInput(int min, int max)
{
    int value;
    //this loop will run as long as condition is true
    while (TRUE)
    {

        //if the user input is in between minimum and maximum value
        if (scanf("%d", &value) == 1 && value >= min && value <= max)
        {
            return value;
        }//if ends

        //calling the function to clear buffer
        clearBuffer();
        printf("Invalid Input! Please try again!");
    }//while ends

}//readInput function ends



//This function generates the random inputs
int generateRandomInput(int min, int max)
{
    int result;
    result =(rand() % (max - min + 1)) + min;
    return result;

}//generateRandomInput function ends



//This function reads the entry and create household
household readUserHousehold()
{
    household data;
    int choice;

    //let the user select region
    printf("Select region (0-Durham, 1-Peel, 2-York): ");
    //maximum input user can enter is 2, minimum is 0
    choice = readInput(0, 2);

    //if user enter o then RegionName is Durham
    if(choice == 0)
    {
        data.regionName = durham;
    }

    //if user enter 1 the RegionName is Peel
    else if(choice == 1)
    {
        data.regionName = peel;
    }

    //if user enter 2 the RegionName is York
    else if(choice == 2)
    {
        data.regionName = york;
    }

    //if the RegionName is "peel", it will go in this if statement and assign Town Name
    if (data.regionName == peel)
    {

         //Let user select the town from peel using 0 & 1
        printf("Select town (0-Brampton, 1-Mississauga): ");
        //validates the user input to be correct
        choice = readInput(0, 1);

        //if user enter 0 town name is brampton
        if (choice == 0) {
            data.townName = brampton;
        }
        //if user enter 1 town name is mississauga
        else {
            data.townName = mississauga;
        }

    }//peel If ends

    //if the RegionName is "york", it will go in this if statement and assign Town Name
    else if (data.regionName == york)
    {

        //Let user select the town from york using 0 & 1
        printf("Select town (0-Maple, 1-Vaughan): ");
        //validates the user input to be correct
        choice = readInput(0, 1);

        //if user enter 0 town name is maple
        if (choice == 0) {
            data.townName = maple;
        }
        //if user enter 0 town name is vaughan
        else
        {
            data.townName = vaughan;
        }

    }//york else if ends

    //if the RegionName is "durham", it will go in this if statement and assign Town Name
    else if (data.regionName == durham)
    {
        //Let user select the town from york using 0 & 1
        printf("Select town (0-Whitby, 1-Oshawa): ");
        //validates the user input to be correct
        choice = readInput(0, 1);

        //if user enter 0 town name is whitby
        if (choice == 0) {
            data.townName = whitby;
        }
        //if user enters 1 town name is oshawa
        else {
            data.townName = oshawa;
        }
    }//durham else if ends

    //Let user select the Race using 0, 1, 2, 3, and 4
    printf("Select a race (0-Caucasian, 1-Indigenous, 2-African American, 3-Asian, 4-Other): ");
    //validates the user input to be correct
    choice = readInput(0, 4);

    //taking user input and assigning the races accordingly

    if (choice == 0)
    {
        data.raceName = caucasian;
    }
    else if (choice == 1)
    {
        data.raceName = indigenous;
    }
    else if (choice == 2)
    {
        data.raceName = african_american;
    }
    else if (choice == 3)
    {
        data.raceName = asian;
    }
    else if (choice == 4)
    {
        data.raceName = other;
    }//if else ends for races


    //Let user enter the number of households and assign it to variable
    printf("Enter number of people in household: ");
    //this takes user input and assign it to numberOfPeople of data and checks for numberOfPeople is not to be zero
    data.numberOfPeople = readInput(1, INT_MAX);

    //Let user enter the income for household and assign it to the variable
    printf("Enter annual income of household: ");
    //this takes user input and assign it to annualIncome of data and checks for annualIncome is not to be zero
    data.annualIncome = readInput(1, INT_MAX);

    return data;

}//readUserHousehold function ends



//This function generates the random data for census
household generateRandomHousehold()
{
    household randomData;

    //random data for region from regionNames enum
    randomData.regionName = generateRandomInput(0, 2);

    //random data for towns using townNames enum
    if (randomData.regionName == peel)
    {
        randomData.townName = generateRandomInput(0, 4);
    }
    else if (randomData.regionName == york)
    {
        randomData.townName = generateRandomInput(5, 9);
    }
    else if (randomData.regionName == durham)
    {
        randomData.townName = generateRandomInput(10, 15);
    }

    //random data for towns using raceNames enum
    randomData.raceName = generateRandomInput(0, 4);

    //random number of people using "numberOfPeople" from household structure variable, minimum is 1 and maximum is 10 for numberOfPeople
    randomData.numberOfPeople = generateRandomInput(1, 10);

    //random number of people using "annualIncome" from household structure variable, minimum is 1 and maximum is 10 for
    randomData.annualIncome = generateRandomInput(1, 100000);

    return randomData;

}//generateRandomHousehold function ends



//This function gives the total of household surveys in census  "byRegion" and displays the data
void householdByRegion(household *data)
{
    //setting the counter to 3 because we have 3 regions
    int counter[3];
    int i;

    //this loop assign the new value 0 for every region
    for (i = 0; i < 3; i++)
        counter[i] = 0;

    //this loop counts the households according to region names
    for (i = 0; i < MAXIMUM_ENTRIES; i++)
        counter[data[i].regionName]++;

    printf("\n*****Households by Region*****\n");
    printf("Household in Peel Region: %d\n", counter[0]);
    printf("Household in York Region: %d\n", counter[1]);
    printf("Household in Durham Region: %d\n", counter[2]);

}//householdByRegion function ends




//This function calculates the number of households by race and displays the data
void householdByRace(household *data)
{
    //setting the counter to 5 because we have 5 races
    int counter[5];

    //this loop assign the new value 0 for every region
    for (int i = 0; i < 5; i++)
        counter[i] = 0;

    //this loop counts the households according to Race
    for (int j = 0; j < MAXIMUM_ENTRIES; j++)
        counter[data[j].raceName]++;

    printf("\n*****Households by Race*****\n");
    printf("Caucasian: %d\n", counter[0]);
    printf("Indigenous: %d\n", counter[1]);
    printf("African American: %d\n", counter[2]);
    printf("Asian: %d\n", counter[3]);
    printf("Other: %d\n", counter[4]);

}//householdByRace function ends



//This function calculates the average household income and displays the data
void averageHouseholdIncome(household *data)
{
    int averageIncome = 0;

   //This for loop access the data and does the addition for averageIncome
    for (int x = 0; x < MAXIMUM_ENTRIES; x++)
        averageIncome += data[x].annualIncome;

    //formula to calculate the average income(Combining all the incomes and dividing them by no of entires)
    //averageIncome / MAXIMUM_ENTRIES;
    printf("\n********Average Income*******\n");
    printf("Average household income: %d\n", averageIncome / MAXIMUM_ENTRIES );

}//averageHouseholdIncome function ends



//This functions calculate the average household income by region and diplays the result
void averageIncomeByTownRegion(household *data)
{

    int totalTowns[6];
    int counter[6];

    //this loop sets the town names from town to town
    for (int i = 0; i < 6; i++)
    {
        totalTowns[i] = 0;
        counter[i] = 0;
    }

    //add the average income by town name and increase the counter
    for (int j = 0; j < MAXIMUM_ENTRIES; j++)
    {
        totalTowns[data[j].townName] += data[j].annualIncome;
        //increase the counter by one
        counter[data[j].townName]++;
    }

    //formula to calculate the average income by towns
    //this is taking total and dividing by the no of entries for the specific town, from a specific index, it is same for all the towns
    int brampton = totalTowns[0] / counter[0];
    int mississauga = totalTowns[1] / counter[1];
    int maple = totalTowns[2] / counter[2];
    int vaughan = totalTowns[3] / counter[3];
    int whitby = totalTowns[4] / counter[4];
    int oshawa = totalTowns[5] / counter[5];

    printf("\n****************Peel Region****************\n");

    printf("    Average annual income of Brampton: %d\n", brampton);
    printf("    Average annual income of Mississauga: %d\n", mississauga);

    printf("****************York Region****************\n");
    printf("    Average annual income of Maple: %d\n", maple);
    printf("    Average annual income of Vaughan: %d\n", vaughan);

    printf("****************Durham Region**************\n");
    printf("    Average annual income of Whitby: %d\n", whitby);
    printf("    Average annual income of Oshawa: %d\n", oshawa);


}//averageIncomeByTownRegion function ends



//This function calculate the average household income by Race and displays the result
void averageIncomeByRace(household *data)
{
    int totalRace[5];
    int counter[5];

   //Reset the race here
    for (int i = 0; i < 5; i++)
    {
        totalRace[i] = 0;
        counter[i] = 0;
    }

    //This loop calculates the income according to the data
    for (int i = 0; i < MAXIMUM_ENTRIES; i++)
    {
        totalRace[data[i].raceName] += data[i].annualIncome;
        counter[data[i].raceName]++;
    }

    int caucasians = (totalRace[0] / counter[0]);
    int indigenous = (totalRace[1] / counter[1]);
    int americans = (totalRace[2] / counter[2]);
    int asians = (totalRace[3] / counter[3]);
    int others = (totalRace[4] / counter[4]);

    //printing the results for average income by race using varibales above
    printf("\n***********Average income by Race************\n");
    printf("Average annual income of Caucasians: %d\n", caucasians);
    printf("Average annual income of Indigenous: %d\n",indigenous);
    printf("Average annual income of African Americans: %d\n", americans);
    printf("Average annual income of Asians: %d\n", asians);
    printf("Average annual income of Others: %d\n", others);

}//averageIncomeByRace ends here



//This functions determine if the household is below poverty or not
int belowPoverty(household entry)
{
    /*
     * if the household is 1 and annual income is less that 15000,
     * if the household is 2 and annual income is less that 20000,
     * if the household is 3 and annual income is less that 25000,
     * if the household is 4 and annual income is less that 30000,
     * if the household is 5 and annual income is less that 40000 ,
     * HOUSE IS CONSIDERED AS POOR
     */
    return (
               (entry.numberOfPeople == 1 && entry.annualIncome < 15000)
            || (entry.numberOfPeople == 2 && entry.annualIncome < 20000)
            || (entry.numberOfPeople == 3 && entry.annualIncome < 25000)
            || (entry.numberOfPeople == 4 && entry.annualIncome < 30000)
            || (entry.numberOfPeople >= 5 && entry.annualIncome < 40000)

            );

}//belowPoverty Function ends here




//This function calculate the percentage of household below poverty
void householdBelowPoverty(household *data)
{
    double countBelowPoverty = 0;

    for (int i = 0; i < MAXIMUM_ENTRIES; i++)
        if (belowPoverty(data[i]))
            countBelowPoverty++;

     // this formula calculate the percentage of household below poverty
     // count Below Poverty household / total households * 100
    double percentage = countBelowPoverty / MAXIMUM_ENTRIES * 100;
    printf("\n********Percentage Household below Poverty*******\n");
    printf("Number of households below poverty line are: %.2f%%\n", percentage);

}//householdBelowPoverty ends here




//This function calculate the percentage of household below poverty by race
void householdPovertyByRace(household *data)
{
    double countBelowPoverty[5];
    int counter[5];

    //Reset the race here
    for (int i = 0; i < 5; i++)
    {
        countBelowPoverty[i] = 0;
        counter[i] = 0;
    }

    //This loop calculates the number of household according to the data
    for (int i = 0; i < MAXIMUM_ENTRIES; i++)
    {
        if (belowPoverty(data[i]))
            countBelowPoverty[data[i].raceName]++;

        counter[data[i].raceName]++;
    }

    //this formula calculate the percentage for households below poverty by race
    //count  households below poverty people in specific race / total households in that specific race * 100
    double caucasians = countBelowPoverty[0] / counter[0] * 100;
    double indigenous = countBelowPoverty[1] / counter[1] * 100;
    double americans =  countBelowPoverty[2] / counter[2] * 100;
    double asians =     countBelowPoverty[3] / counter[3] * 100;
    double others =     countBelowPoverty[4] / counter[4] * 100;

    printf("\n**********Percentage Households below poverty by Race*********\n");
    printf("Households below poverty line of Caucasians: %.2f%%\n", caucasians);
    printf("Households below poverty line of Indigenous: %.2f%%\n", indigenous);
    printf("Households below poverty line of African Americans: %.2f%%\n",americans);
    printf("Households below poverty line of Asians: %.2f%%\n", asians);
    printf("Households below poverty line of Others: %.2f%%\n", others);

}//householdPovertyByRace ends here



//This function calculates the percentage of below poverty line by town and region
void householdPovertyByTownRegion(household *data)
{
    double countBelowPoverty[6];
    int counter[6];

    //this reset the couter
    for (int i = 0; i < 6; i++)
    {
        countBelowPoverty[i] = 0;
        counter[i] = 0;
    }

    //Count the number of households below poverty line
    for (int j = 0; j < MAXIMUM_ENTRIES; j++)
    {
        if (belowPoverty(data[j]))
            countBelowPoverty[data[j].townName]++;

        counter[data[j].townName]++;
    }
    //count  households below poverty people in specific region / total households in that specific region * 100
    double brampton = countBelowPoverty[0] / counter[0] * 100;
    double mississauga = countBelowPoverty[1] / counter[1] * 100;
    double maple = countBelowPoverty[2] / counter[2] * 100;
    double vaughan = countBelowPoverty[3] / counter[3] * 100;
    double whitby = countBelowPoverty[4] / counter[4] * 100;
    double oshawa = countBelowPoverty[5] / counter[5] * 100;

    printf("\n*********Number of household below poverty by Town and Region*******\n");
    printf("--------------------------Peel Region----------------------------\n");
    printf("Number of households below poverty line of Brampton: %.2f%%\n",brampton);
    printf("Number of households below poverty line of Mississauga: %.2f%%\n", mississauga);

    printf("--------------------------York Region----------------------\n");
    printf("Number of households below poverty line of Maple: %.2f%%\n",maple);
    printf("Number of households below poverty line of Vaughan: %.2f%%\n", vaughan);

    printf("----------------------Durham Region--------------------------\n");
    printf("Number of households below poverty line of Whitby: %.2f%%\n", whitby);
    printf("Number of households below poverty line of Oshawa: %.2f%%\n", oshawa);

}//householdPovertyByTownRegion function ends here



//This function print the house hold data in a formatted way
void printHouseholdData(household *data)
{
    printf("\n*****************************Household Data for Census*****************************\n\n");
    //formatting the header for data
    printf("%5s%15s%10s%15s%15s%15s\n", "Number", "Income", "FamilySize", "Race", "Region", "Town");

    //this loop will get all the elements from data
    for (int i = 0; i < MAXIMUM_ENTRIES; i++)
    {
        //Prints the Number, Income, & Family Size
        printf("%5d%15d%10d",
               i + 1,
               data[i].annualIncome,
               data[i].numberOfPeople);


        //Prints the Race Name
        if(data[i].raceName == caucasian)
        {
            printf("%20s", "Caucasian");
        }
        else if(data[i].raceName == indigenous)
        {
            printf("%20s", "Indigenous");
        }
        else if(data[i].raceName == african_american)
        {
            printf("%20s", "African American");
        }
        else if(data[i].raceName == asian)
        {
            printf("%20s", "Asian");
        }
        else if(data[i].raceName == other)
        {
            printf("%20s", "Other");
        }//if else ends for race names

        //prints the Region Name
        if(data[i].regionName == durham)
        {
            printf("%20s", "Durham");
        }
        else if(data[i].regionName == peel)
        {
            printf("%20s", "Peel");
        }
        else if(data[i].regionName == york)
        {
            printf("%20s", "York");
        }//if else ends for region names


        //Prints the Town name
        if(data[i].regionName == whitby)
        {
            printf("%20s", "Whitby");
        }
        if(data[i].regionName == brampton)
        {
            printf("%20s", "Brampton");
        }
        if(data[i].regionName == mississauga)
        {
            printf("%20s", "Mississauga");
        }
        if(data[i].regionName == vaughan)
        {
            printf("%20s", "Vaughan");
        }
        if(data[i].regionName == oshawa)
        {
            printf("%20s", "Oshawa");
        }
        if(data[i].regionName == maple)
        {
            printf("%20s", "Maple");
        }//if ends for town names

        printf("\n");

    }//for loop ends

}//printHouseholdData function ends here