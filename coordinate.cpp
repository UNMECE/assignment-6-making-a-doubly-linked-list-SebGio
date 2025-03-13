#include "coordinate.h"
#include <math.h>
#include <iostream.h>
#include <stdlib.h>

void add_coordinate(Coordinate *list_end, float x, float y)
{
	Coordinate * newCoord = (Coordinate)malloc(sizeof(coordinate));
	newCoord->x = x;
	newCoord->y = y;
	//newCoord->id = list_end->id + 1;
	newCoord->next = null;
	newCoord->previous = list_end;
	list_end->next = newCoord;
}
void forward_display(Coordinate *list_beginning)
{

	while(list_beginning->next != null)
	{
		std::cout << "ID: " << list_beginning->coord_id << " X: " << list_beginning->x << " Y: " << list_beginning->y << std::endl;
		list_beginning = list_beginning->next;
	}
	//last value will get skipped, make sure it still gets output
	//std::cout << "ID: " << list_beginning->coord_id << " X: " << list_beginning->x << " Y: " << list_beginning->y << std::endl;
	//for (int i = 0; i <  list_length(list_beginning); ++i)
	//{
		//std::cout << "ID: " << (list_beginning + i)->coord_id << " X: " << (list_beginning + i)->x << " Y: " << (list_beginning + i)->y << std::endl;
	//}
}
void backward_display(Coordinate *list_end)
{
	while(list_end->previous != null)
	{
		std::cout << "ID: " << list_end->coord_id << " X: " << list_end->x << " Y: " << list_end->y << std::endl;
		list_end = list_end->previous;
	}
	//last value will get skipped, make sure it still gets output
	//std::cout << "ID: " << list_end->coord_id << " X: " << list_end->x << " Y: " << list_end->y << std::endl;

	//for (int i =  list_length(list_beginning); i > 0;  --i)
	//{
	//	std::cout << "ID: " << (list_beginning + i)->coord_id << " X: " << (list_beginning + i)->x << " Y: " << (list_beginning + i)->y << std::endl;
	//}

}
void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete)
{
	Coordinate *temp = list_beginning;
	if (temp != null)
	{
		while (temp->coord_id != coord_id_to_delete)
		{
			temp = temp->next;
		}
		if (temp == null)

	}
	else
	}
		std::cout << "List is empty." << endl;
	}
}
int list_length(Coordinate *list_beginning)
{
	int length = 0;
	while (list_beginning->next != null)
	{
		++length;
	}
	return length;
}
void closest_to(Coordinate *list_beginning, float x, float y)
{
	float distance = 0;
	while(list_beginning->next != null)
	{
		//pythagorean theorem
		float xDistance = abs(list_beginning->x) + abs(x);
		float yDistance = abs(list_beginning->y) + abs(y);
		float newDistance = sqrt(pow(xDistance, 2) + pow(yDistance, 2));
		if (distance > newDistance)
		{
			distance = newDistance;	
		}
	}
	
}
