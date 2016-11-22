# include <stdio.h>
# include "todo.h"

int main( void )
{
	TodoItem todos[MAXTODOITEMS];
	int nrOfItems;
	
	/* Open and read the todo file */
	nrOfItems = readItemsFromFile( "todos.tdl", MAXTODOITEMS, todos );
	
	/* Sort them according to date */
	sortItemsByDate( todos, nrOfItems );
	
	/* Display the list on screen */
	showTodoItems( todos, nrOfItems );
	
	return 0;
}