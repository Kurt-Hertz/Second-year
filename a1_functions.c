/********* definitions.c ********
	
	Student Name 	= Kurt Hertz
	Student Number	= 101261740
*/

// Your solution goes here 
#include <stdlib.h>  
#include <stdio.h>   // printf
#include <stdbool.h>

#include "a1_data_structures.h"
#include "a1_functions.h"


/*
   Calculate number of employees needed for the project based on cost and time
*/
void number_of_employees(milestone_t *project_details){
	project_details->num_employees = round(project_details->cost / (project_details->time * 40 * 25));
	printf("The planned number of employees needed is: %d", project_details->num_employees);
}

/* 
   Initialize milestones with names and planned budget
*/
milestone_t init_milestone(char stage_name[], float assigned_budget){
	milestone_t init;
		strcpy(init.name, stage_name);
		init.cost = assigned_budget;
		init.time = 0;
		init.num_employees = 0;
		init.completed = 0;
	return init;
}


/* 
   Get unsigned short integer user input. The value must be positive.
   If negative value entered ask user to re-enter a positive value
*/
unsigned short int get_input_usi(void){
	unsigned short int input;
	scanf("%hu", &input);

	while ((int)input < 0 || input > 6)
	{
		printf("\nThe value you entered is wrong\nEnter a value between 0 and 5 : 1");
		scanf("%hu", &input);
	}
	printf("\nYour choice is: %hu\n\n", input);
	return input;
}


/*
   Get user float input. The value must be positive.
   If negative value entered ask user to re-enter a positive value
*/
float get_input_f(void){
	float input;
	printf("enter a flaot: ");
	scanf("%f", &input);

	while (input < 0)
	{
		printf("\n--------------------------------------------\nThe value you entered is wrong\nenter a positive float: ");
		scanf("%f", &input);
	}
	printf("\nYour choice is: %0.2f\n\n", input);
	return input;
}


/* 
   Print menu with a list of milestones/options for the user to choose from
*/
void print_menu(void){
	
	printf("\nWhich milestone you want to update? (0 to exit): \n1. Technical requirements \n2. System Design\n3. Software Development\n4. Testing\n5. Product release\n");
}


/*
   Print out current stats of each milestone/project
   (i.e, print all members of the milestone_t struct)
*/
void print_stats(milestone_t details){
	if (details.completed == 0){
		printf("\nActual time: %0.2f weeks\nActual number of employees: %d\nActual cost: %0.2f$\nCompleted: No\n\n",details.time, details.num_employees, details.cost);
	}
}


/*
   Update the stats of the milestones (not the project).
   (i.e., Asks the user to update time, number of employees and completed.
    Cost is calculated based on the input data)
*/
void update_stats(milestone_t milestone_array[], int milestone_num){
	char b = 'a';
	printf("\nEnter the milestone's actual time: ");
	milestone_array[milestone_num].time = get_input_f();
	printf("\nEnter the milestone's actual number of employees: ");
	milestone_array[milestone_num].num_employees = get_input_usi();
	milestone_array[milestone_num].cost = milestone_array[milestone_num].num_employees * milestone_array[milestone_num].time * 40 * 25;
	printf("actual cost: %d", milestone_array[milestone_num].cost);
	while (b != 'Y' && b != 'N') { 
    	printf("\nIs this milestone complete?: (Y/N) ");
    	scanf(" %c", &b); 
	}
	if (b == 'Y'){
		milestone_array[milestone_num].completed = 1;
	} else if (b == 'N'){
		milestone_array[milestone_num].completed = 0;
	}
	printf("\nStats Updated!\n\n");
}

/*
   Check if all milestones are completed or not. If completed, updated the project's details to completed.
*/
void check_project_completion(milestone_t milestone_array[], int num_milestones){
	char in = 'a';
	for (int i = 1; i < num_milestones; i++){
		if (milestone_array[i].completed == 0){
			printf("\n--------------------------------------------\n---------- Project's Performance -----------\n--------------------------------------------");
			printf("\n\n------------- Milestone Stats --------------\nBelow is \"Planned Details\" current stats:\n--------------------------------------------");
			printf("\nActual time: %0.2f weeks", milestone_array[i].time);
			printf("\nActual number of employees: %d", milestone_array[i].num_employees);
			printf("\nActual cost: %0.2f$", milestone_array[i].cost);
			printf("\nCompleted: No");
			break;
		}
	}
}