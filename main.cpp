#include "coordinate.h"
#include <iostream>
#include <string>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	//make sure number of coordinates is specified
	if (argc == 1)
	{
		std::cout << "Please specify a number of coordinates to create when running the program" << std::endl;
		return 1;
	}
	

	//seed random
	srand(time(NULL));

	int numCoords = std::stoi(argv[1]);

	//create initial element
	Coordinate* head = new Coordinate;
	head->coord_id = 0;
	head->previous = NULL;

	Coordinate* tail = head;
	//fill the list
	for (int i = 0; i < numCoords; ++i)
	{
		add_coordinate(tail, (float)rand() / 10, (float)rand() / 10);
		tail = tail->next;
	}

	//delete initial value so the length is what the user requested.
	head = head->next;
	delete_coordinate(head->previous, 0);

	std::cout << "Length before delete: " << list_length(head) << std::endl;
	forward_display(head);
	backward_display(tail);
	
	//delete some elements
	delete_coordinate(head, 4);
	tail = tail->previous;
	delete_coordinate(head, 10);

	std::cout << "Length after delete: " << list_length(head) << std::endl;
	list_length(head);
	forward_display(head);
	backward_display(tail);
	

	closest_to(head, (float)rand() / 10, (float)rand() / 10);

	//clear memory
	while (head != NULL)
	{
		Coordinate* temp = head->next;
		delete head;
		head = temp;
	}

return 0;
}
