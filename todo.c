# include <stdio.h>
# include <string.h>
# include "todo.h"


/* The funktion interprets a string and converts it to number
*/
//s= array med todoitem-rader,
char *parseInt( char *s, int *value )
{
    *value = 0;
    int i;
    for( i=0; s[i]>='0' && s[i]<='9'; i++)
    *value = 10*(*value) + (s[i] - '0');

    return s+i;

}

/* Skip white space in string
*/
char *moveToNextNonSpaceChar( char *s )
{
    int i = 0;
    while (s[i] == ' '){
        i++;
    }
    return s+i;
}



char *parseDate( char *s, Date *d )
{

    s=parseInt(s, &d->year);
    s=parseInt(s, &d->month);
    s=parseInt(s, &d->day);

}

//Removes characters '\n', '\r' and ' ' from the end of the string

char *rightTrim( char *s )
{
    int end=0;
    for( int i = 0; s[i] != '\0' ; i++ )
        end = i;
    /* Check to see which, if any of the previous
       chars that needs to be removed.
    */
    while (s[end] == '\n' || s[end] == ' ' || s[end] == '\r' || s[end] == '\t')
    {
        if( s[end] == '\n'){
            s[end--] = 0;
        }
        if (s[end] == ' '){
            s[end--]= 0;
        }
        if (s[end] == '\r'){
            s[end--]= 0;
        }
        if (s[end] == '\t'){
            s[end--]= 0;
    }
}

    return s + end;
}


/* Translate a line into a TodoItem , parse=hantera

*/

TodoItem parseOneLine( char *s )
{
  TodoItem todo;
  Date date ;

  char *end;
    /* Remove spaces/newlines from the end of the string */
    s=rightTrim(s);

    /* First skip to the first non-whitespace char */
    s=moveToNextNonSpaceChar(s);

    /* Next, read the ID */
    s= parseInt(s, &todo.id);

    /* Skip until the date */
    s= moveToNextNonSpaceChar(s);

    /* Parse the date */
    s= parseDate(s, &date);
    /* Skip to the message */
    s= moveToNextNonSpaceChar(s);

    /* Copy the message into the todo item */
    //s= copyMessage(s);
    strcpy(todo.description, s);

}

/* Find an id that isn't used

*/

int getFreeID( int nrOfItems, TodoItem todos[] )
{

}

/* Take a TodoItem and creates a string representation of it
Tar ett TodoItem och gör om det till en sträng (samma format som beskrivs ovan).
Returnerar en pekare till början på strängen.
*/

char *formatTodoItem( TodoItem todo, char *s )
{
    sprintf(s, " %d %d-%d-%d %s", todo.id, todo.due.year, todo.due.month, todo.due.day, todo.description);

}

/* Read todos from text file and convert it to an array of TodoItems

*/
int readItemsFromFile( char *file, int maxNrOfItems, TodoItem arr[maxNrOfItems] )
{

    FILE *fp;
    fp = fopen(file, "r" );
    char line[MAXLINESIZE];
    int i = 0;
    while( fgets (line, MAXLINESIZE, fp)!=NULL ) {
    arr[i] = parseOneLine(line);

    i++;
    }
    fclose(fp);

    return(i);

}

/* Show all the todo items on the screen */
void showTodoItems( TodoItem todolist[], int nrOfExistingItems )
{

}

/* Delete the specified todo item from the list. Returns the number
   of item in the list
*/
int deleteItem( TodoItem todolist[], int nrOfExistingItems, int itemID )
{

}

/* Sort the array according to date */
void sortItemsByDate( TodoItem items[], int nrOfExistingItems )
{

}

/* Save TodoItems to a file */
void saveItemsToFile( char *file, int nrOfExistingItems, TodoItem arr[] )
{

}

/* Add a TodoItem to the current list of todos */
int addTodo( int maxNrOfItems, int nrOfExistingItems, TodoItem todos[], TodoItem newTodo )
{

}
