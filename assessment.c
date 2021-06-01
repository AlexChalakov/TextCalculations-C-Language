#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//Structs//
struct city{ 
double latitude;
double longitude;
int count;};
typedef struct city City;

//Part 2//
//2.1 - Number of people from the Santa's list//
int number_of_people (FILE *santaFile){
    santaFile = fopen("santaslist.txt", "r");
    char surname[100], firstname [100];
    int niceCounter = 0, behaviourScore = 0, peopleCounter = 0;
    double latitude = 0, longitude = 0;
    float giftWeight = 0;

    if (santaFile != NULL)
    {
        while (fscanf(santaFile, "%[^,],%[^,],%d,%lf,%lf,%f", surname, firstname,
        &behaviourScore, &latitude, &longitude, &giftWeight) == 6)
        {
            peopleCounter++;
        }   
    }
    return(peopleCounter);
    fclose(santaFile);
}

//2.2//
int number_of_nice_people(FILE *santaFile){
    santaFile = fopen("santaslist.txt", "r");
    char surname[100], firstname [100];
    int niceCounter = 0, behaviourScore = 0;
    double latitude = 0, longitude = 0;
    float giftWeight = 0;

    if (santaFile != NULL)
    {
        while (fscanf(santaFile, "%[^,],%[^,],%d,%lf,%lf,%f", surname, firstname,
        &behaviourScore, &latitude, &longitude, &giftWeight) == 6){
            if (behaviourScore > 0)
            {
                niceCounter++;
            }
        }
    }
    return(niceCounter);
    fclose(santaFile);
}

//2.3//
int number_of_naughty_people(FILE *santaFile){
    santaFile = fopen("santaslist.txt", "r");
    char surname[100], firstname [100];
    int naughtyCounter = 0, behaviourScore = 0;
    double latitude = 0, longitude = 0;
    float giftWeight = 0;

    if (santaFile != NULL)
    {
        while (fscanf(santaFile, "%[^,],%[^,],%d,%lf,%lf,%f", surname, firstname,
        &behaviourScore, &latitude, &longitude, &giftWeight) == 6)
        {
            if (behaviourScore < 0)
            {
                naughtyCounter++;
            }
        }
    }
    return(naughtyCounter);
    fclose(santaFile);
}

//2.4//
float average_behaviourscore(FILE *santaFile){
    santaFile = fopen("santaslist.txt", "r");
    char surname[100], firstname [100];
    int peopleCounter = 0, behaviourScore = 0;
    double latitude = 0, longitude = 0;
    float giftWeight = 0, sum = 0;

    if (santaFile != NULL)
    {
        while (fscanf(santaFile, "%[^,],%[^,],%d,%lf,%lf,%f", surname, firstname,
        &behaviourScore, &latitude, &longitude, &giftWeight) == 6)
        {   
            peopleCounter++;
            sum = sum + behaviourScore;
        }
        sum = sum/peopleCounter;
    }
    return(sum);
    fclose(santaFile);
}

//2.5//
void naughtiest_person(FILE *santaFile, double *latitude, double *longitude){
    santaFile = fopen("santaslist.txt", "r");
    char surname[100], firstname [100];
    int behaviourScore = 0, minBehaviourScore = 10;
    double latitudeCurrent = 0, longitudeCurrent = 0;
    float giftWeight = 0;

    if (santaFile != NULL)
    {
        while (fscanf(santaFile, "%[^,],%[^,],%d,%lf,%lf,%f", surname, firstname,
        &behaviourScore, &latitudeCurrent, &longitudeCurrent, &giftWeight) == 6)
        {   
            if (behaviourScore < minBehaviourScore){
                minBehaviourScore = behaviourScore;
                *latitude = latitudeCurrent;
                *longitude = longitudeCurrent;
            }
        }
    }
    fclose(santaFile);
}

//Part 3//
//Take off from Lapland//
//3.1//

float total_weight(FILE *santaFile){
    santaFile = fopen("santaslist.txt", "r");
    char surname[100], firstname [100];
    int behaviourScore = 0;
    double latitude = 0, longitude = 0;
    float giftWeight = 0, sum = 0;

    if (santaFile != NULL)
    {
        while (fscanf(santaFile, "%[^,],%[^,],%d,%lf,%lf,%f", surname, firstname,
        &behaviourScore, &latitude, &longitude, &giftWeight) == 6)
        {
            sum = sum + giftWeight;
        }
    }
    return(sum);
    fclose(santaFile);
}

//3.2//
int calculate_sleighs_needed(FILE *santaFile){
    santaFile = fopen("santaslist.txt", "r");
    char surname[100], firstname [100];
    int behaviourScore = 0, sleighsNeeded = 0;
    double latitude = 0, longitude = 0, sleighsCargo = 1500;
    float giftWeight = 0, sum = 0;

    if (santaFile != NULL)
    {
        while (fscanf(santaFile, "%[^,],%[^,],%d,%lf,%lf,%f", surname, firstname,
        &behaviourScore, &latitude, &longitude, &giftWeight) == 6)
        {
            sum = sum + giftWeight;
            if ( sleighsCargo < sum)
            {
                while (sleighsCargo < sum)
                {
                    sum = sum - sleighsCargo;
                    sleighsNeeded++;
                }
            }
        }
    }
    if (sum > 0)
    {
        sleighsNeeded++;
    }
    
    return(sleighsNeeded);
    fclose(santaFile);
}

//3.3//
int calculate_time_needed(FILE *santaFile){
    santaFile = fopen("santaslist.txt", "r");
    char surname[100], firstname [100];
    int behaviourScore = 0, sleighsNeeded = 0, sleighsCargo = 1500;
    double latitude = 0, longitude = 0;
    float giftWeight = 0, sum = 0, sleighTime = 0;;

    if (santaFile != NULL)
    {
        while (fscanf(santaFile, "%[^,],%[^,],%d,%lf,%lf,%f", surname, firstname,
        &behaviourScore, &latitude, &longitude, &giftWeight) == 6)
        {
            sum = sum + giftWeight;
            if ( sleighsCargo < sum)
            {
                while (sleighsCargo < sum)
                {
                    sum -= sleighsCargo;
                    sleighsNeeded++;
                }

                sleighTime = sleighsNeeded * 90;
            }
        }
    }
    if (sum > 0)
    {
        sleighsNeeded++;
        sleighTime = sleighsNeeded * 90;
    }
    
    return(round(sleighTime/60));
    fclose(santaFile);
}

//3.4//
void largest_gathering(FILE *santaFile, double *latitude, double *longitude){
    santaFile = fopen("santaslist.txt", "r");
    char surname[100], firstname [100];
    int behaviourScore = 0, totalCitiesCount = 0, maxCount = 0;
    bool cityExists;
    double latitudeCurrent = 0, longitudeCurrent = 0;
    float giftWeight = 0;
    //calling struct//
    //initialising struct array//
    City cities [number_of_people(santaFile)]; 

    if (santaFile != NULL)
    {
        //opening file and reading from it//
        while (fscanf(santaFile, "%[^,],%[^,],%d,%lf,%lf,%f", surname, firstname,
        &behaviourScore, &latitudeCurrent, &longitudeCurrent, &giftWeight) == 6)
        {   
            //we assume city doesn't exist, so it enters the following for loop//
            cityExists = false;
            for ( int i = 0; i < totalCitiesCount; i++)
            {
                //if we find the same coordinates, we say we have found the city and we give it +1//
                if (latitudeCurrent == cities[i].latitude 
                && longitudeCurrent == cities[i].longitude)
                {
                    cities[i].count++;
                    cityExists = true;
                } 
            } 

            //if city doesn't exist, we create a new one and add it to our array of cities//
            if (!cityExists)
            {
                //we define the new city with the following attributes into the array and add +1//
                City city1 = {latitudeCurrent, longitudeCurrent, 1};
                cities[totalCitiesCount] = city1;
                totalCitiesCount++;
            }
        }

        //we firstly find the most number of people//
        for (int i = 0; i < totalCitiesCount; i++)
        {
            if (cities[i].count > maxCount)
            {
                maxCount = cities[i].count;
            }
        }

        //we then find the corresponding city(coordinates) to them//
        for (int i = 0; i < totalCitiesCount; i++)
        {
            if (maxCount == cities[i].count)
            {
                *longitude = cities[i].longitude;
                *latitude = cities[i].latitude;
                break;
            }   
        }
    }
    fclose(santaFile);
}


//Part 4//
//Quiz Extensions//

int number_of_neutral_people(FILE *santaFile){
    santaFile = fopen("santaslist.txt", "r");
    char surname[100], firstname [100];
    int neutralCounter = 0, behaviourScore = 0;
    double latitude = 0, longitude = 0;
    float giftWeight = 0;

    if (santaFile != NULL)
    {
        while (fscanf(santaFile, "%[^,],%[^,],%d,%lf,%lf,%f", surname, firstname,
        &behaviourScore, &latitude, &longitude, &giftWeight) == 6){
            if (behaviourScore == 0)
            {
                neutralCounter++;
            }
        }
    }
    return(neutralCounter);
    fclose(santaFile);
}


void furthest_east_child(FILE *santaFile, char *surname, char *firstname){
    santaFile = fopen("santaslist.txt", "r");
    char surnameCurrent[100], firstnameCurrent[100];
    //positive longitude is east//
    int behaviourScore = 0;
    double latitudeCurrent = 0, longitudeCurrent = 0, longitudeEast = 0;
    float giftWeight = 0;

    if (santaFile != NULL)
    {
        while (fscanf(santaFile, "%[^,],%[^,],%d,%lf,%lf,%f", surname, firstname,
        &behaviourScore, &latitudeCurrent, &longitudeCurrent, &giftWeight) == 6)
        {   
            if (longitudeCurrent < longitudeEast){
                longitudeEast = longitudeCurrent;
                surname = surnameCurrent;
                firstname = firstnameCurrent;
            }
        }
    }
    fclose(santaFile);
}

//Part 1//
//The main function//

int main () {
    FILE *santaFile;
    santaFile = fopen("santaslist.txt", "r");

    number_of_people(santaFile);
    int number = number_of_people(santaFile);
    printf("Number of people on the list: %d\n", number);

    number_of_nice_people(santaFile);
    int nice = number_of_nice_people(santaFile);
    printf("Number of nice people on the list: %d\n", nice);

    number_of_naughty_people(santaFile);
    int naughty = number_of_naughty_people(santaFile);
    printf("Number of naughty people on the list: %d\n", naughty);

    average_behaviourscore(santaFile);
    float average = average_behaviourscore(santaFile);
    printf("Average behaviour score is: %f\n", average);

    double latitude, longitude;
    naughtiest_person(santaFile, &latitude, &longitude);
    printf("Naughtiest person has coordinates of %lf, %lf.\n", latitude, longitude);

    total_weight(santaFile);
    float weight = total_weight(santaFile);
    printf("Total weight of gifts: %f\n", weight);

    calculate_sleighs_needed(santaFile);
    int sleighs = calculate_sleighs_needed(santaFile);
    printf("%d of sleighs are needed for Santa to deliver the gifts.\n", sleighs);

    calculate_time_needed(santaFile);
    int time = calculate_time_needed(santaFile);
    printf("It takes %d minutes to launch the required number of sleighs.\n", time);

    largest_gathering(santaFile, &latitude, &longitude);
    printf("Address with the most number of people living there is %lf, %lf\n", latitude, longitude);

    number_of_neutral_people(santaFile);
    int neutral = number_of_neutral_people(santaFile);
    printf("Number of neutral people on the list: %d\n", neutral);

    char surname[100], firstname [100];
    furthest_east_child(santaFile, surname, firstname);
    printf("The furthest east child is %s, %s\n", surname, firstname);

    rewind(santaFile);
}