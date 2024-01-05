/********* main.c ********
	
	Student Name 	= Kurt Hertz
	Student Number	= 101261740
*/

// Includes go here
#include <stdlib.h>  
#include <stdio.h>   // printf

//#include "a1_data_structures.h"
//#include "a1_functions.h"
#include "a1_functions.c"

int main()
{
    printf("Welcome to ABC Project Tracker");

	milestone_t m[6];
	
    printf("\nEnter total project's budget ");
    m[0] = init_milestone("Project", get_input_f());

    printf("\nEnter total project's duration in weeks: ");
    m[0].time = get_input_f();

    number_of_employees(&m[0]);
	


	m[1] = init_milestone("Technical requirements", m[0].cost / 5);
	m[2] = init_milestone("System Design", m[0].cost / 5);
	m[3] = init_milestone("Software Development", m[0].cost / 5);
	m[4] = init_milestone("Testing", m[0].cost / 5);
	m[5] = init_milestone("Product release", m[0].cost / 5);



	short int input = (short)1;
	while (input != 0){
		print_menu();
		input = get_input_usi();

		//project
		if (input == 0){
			char in = 'a';
			check_project_completion(m, 6);

			printf("\nDo you want to finish the remaining milestones? \n (Y/N) ");
			scanf(" %c", &in);

			while (in != 'Y' && in != 'N') {
    			printf("\nInvalid input. Enter (Y/N): ");
   				scanf(" %c", &in);
			}

			if (in == 'N'){
				printf("\n--------------------------------------------\n------- Final Project's Performance --------\n--------------------------------------------");
				printf("\nThe project's cost is below budget!");
				printf("\nPlanned budget: %0.2f", m[0].cost);
				printf("\nActual Cost: %0.2f",  m[1].cost + m[2].cost + m[3].cost + m[4].cost + m[5].cost);
				printf("\n--------------------------------------------\n--- The program will quit now! Goodbye! ---\n--------------------------------------------");
				break;
			}
		}else{

			printf("\n------------- Milestone Stats --------------\nBelow is \"%s\" current stats:\n--------------------------------------------",m[input].name);
			print_stats(m[input]);

			if (m[input].completed) {
					printf("\n--------------------------------------------\n");
					printf("%s milestone is completed\n", m[input].name);
					printf("Cannot be updated\n--------------------------------------------\n");
				} else {
					printf("\n-------------- Update Stats ----------------\n");
					update_stats(m, input);
			}
		}
	}
	return 0;
}