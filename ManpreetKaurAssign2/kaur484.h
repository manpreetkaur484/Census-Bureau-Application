/*Author: Manpreet Kaur
 * Date: June 18, 2020
 * * Description: This program collects the information for a census bureau which should
 * obtain and analyze household information within the Greater Toronto Area
*/
//HEADER FILE FOR ASSIGNMENT 2

#ifndef ASSIGNMENT2_KAUR484_H
#define ASSIGNMENT2_KAUR484_H

#define TRUE 1
#define MAXIMUM_ENTRIES 100

//Declaration and Initialization of Enums
//Enum to store region names
enum region_names { peel, york, durham };
//Enum to store town names
enum town_names   { brampton, mississauga, maple, vaughan, whitby, oshawa };
//Enum to store toen names
enum race_names   { caucasian, indigenous, african_american, asian, other };


//Declaration and Initialization of 'Household' Structure
typedef struct data_structure
{
    //regionName is of type region_names enum
    enum region_names regionName;
    //townName is of type town_names enum
    enum town_names townName;
    //raceName is of type race_names enum
    enum race_names raceName;
    //variable store the number of family members
    int numberOfPeople;
    //variable that stores the annual income of household
    int annualIncome;

} household;

//Prototypes of all the functions from 'census.c' file

//clear buffer
void clearBuffer();

int readInput(int min, int max);
int generateRandomInput(int min, int max);

//methods for household data
household readUserHousehold();
household generateRandomHousehold();

//Methods that do all the calculations
void householdByRegion(household *data);
void householdByRace(household *data);

void averageHouseholdIncome(household *data);
void averageIncomeByTownRegion(household *data);
void averageIncomeByRace(household *data);

void householdBelowPoverty(household *data);
void householdPovertyByRace(household *data);
void householdPovertyByTownRegion(household *data);

void printHouseholdData(household *data);

//this method determine if household id below poverty or not
int belowPoverty(household entry);

#endif //ASSIGNMENT2_KAUR484_H