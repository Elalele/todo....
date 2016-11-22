# include <stdio.h>
# include <string.h>
# include "todo.h"



int main( int argc, char **argv )
{
	TodoItem todos[MAXTODOITEMS];
	TodoItem newItem;
	int nrOfItems;
	char description[MAXLINESIZE] = "";
	
	
	/* Parse the date */
	parseDate(argv[1],&(newItem.due));
	
	/* Create the description string */
	for( int i = 2 ; i < argc ; i++ ){
		strcat(newItem.description,argv[i]);
		strcat(newItem.description," ");
	}
	
	/* Open and read the todo file */
	nrOfItems = readItemsFromFile( "todos.tdl", MAXTODOITEMS, todos );
	
	/* Find a free id */
	newItem.id = getFreeID( nrOfItems, todos );
	
	/* Add new todo */
	nrOfItems = addTodo( MAXTODOITEMS, nrOfItems, todos, newItem );
	
	/* Sort the list according to date */
	sortItemsByDate( todos, nrOfItems );
	
	/* Display the list on screen */
	showTodoItems( todos, nrOfItems );
	
	/* Save the new list */
	saveItemsToFile( "todos.tdl", nrOfItems, todos );
	
	return 0;
}
