#include "coordinate.h"
#include <math.h>
#include <iostream>


void add_coordinate(Coordinate *list_end, float x, float y)
{
	Coordinate * newCoord = new Coordinate;
	newCoord->x = x;
	newCoord->y = y;
	newCoord->next = NULL;

	newCoord->coord_id = list_end->coord_id + 1;
	newCoord->previous = list_end;
	list_end->next = newCoord;

}
void forward_display(Coordinate *list_beginning)
{
	std::cout << "Forward display:" << std::endl;
	//while(list_beginning->next != NULL)
	while (list_beginning != NULL)
	{
		std::cout << "ID: " << list_beginning->coord_id << " X: " << list_beginning->x << " Y: " << list_beginning->y << std::endl;
		list_beginning = list_beginning->next;
	}
}
void backward_display(Coordinate *list_end)
{
	std::cout << "Backward display:" << std::endl;
	//while(list_end->previous != NULL)
	while(list_end != NULL)
	{
		std::cout << "ID: " << list_end->coord_id << " X: " << list_end->x << " Y: " << list_end->y << std::endl;
		list_end = list_end->previous;
	}
}
void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete)
{
	Coordinate *temp = list_beginning;
	if (temp != NULL)
	{
		while (temp->coord_id != coord_id_to_delete)
		{
			temp = temp->next;
			if (temp == NULL)
			{
				std::cout << "Cannot delete coordinate " << coord_id_to_delete << ": Invalid ID" << std::endl;
				return;
			}
		}
		//check if value is at beginning or end of list, and update values
		temp->next != NULL ? temp->next->previous = temp->previous : temp->previous->next = NULL;
		temp->previous != NULL ? temp->previous->next = temp->next : temp->next->previous = NULL;
		
		delete temp;
	}
	else
	{
		std::cout << "List is empty." << std::endl;
	}
	
}
int list_length(Coordinate *list_beginning)
{
	int length = 0;
	while (list_beginning != NULL)
	{
		++length;
		list_beginning = list_beginning->next;
	}
	return length;
}
void closest_to(Coordinate *list_beginning, float x, float y)
{
	float minDistance = FLT_MAX;
	Coordinate* closeCoordinate = list_beginning;
	while(list_beginning != NULL)
	{
		//pythagorean theorem
		float xDistance = abs(list_beginning->x - x);
		float yDistance = abs(list_beginning->y - y);
		float newDistance = sqrt(pow(xDistance, 2) + pow(yDistance, 2));

		if (minDistance > newDistance)
		{
			minDistance = newDistance;
			closeCoordinate = list_beginning;
		}
		list_beginning = list_beginning->next;
	}
	//output result
	std::cout << "Closest coordinate to " << x << ", " << y << ":	ID: " << closeCoordinate->coord_id << " X: " << closeCoordinate->x << " Y: " << closeCoordinate->y << std::endl;
	
}
