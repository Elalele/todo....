# include <stdio.h>
# include "todo.h"

int main( int argc, char **argv )
{
	TodoItem todos[MAXTODOITEMS];
	int itemToDelete;
	int nrOfItems;
	
	/* Read the item id that should be deleted */
	parseInt(argv[1],&itemToDelete);
	
	/* Open and read the todo file */
	nrOfItems = readItemsFromFile( "todos.tdl", MAXTODOITEMS, todos );
	
	/* Delete the item */
	nrOfItems = deleteItem( todos, nrOfItems, itemToDelete );
	
	/* Sort the list according to date */
	sortItemsByDate( todos, nrOfItems );
	
	/* Display the list on screen */
	showTodoItems( todos, nrOfItems );
	
	/* Save the new list */
	saveItemsToFile( "todos.tdl", nrOfItems, todos );
	
	return 0;
}
