# define MAXTODOITEMS 100
# define MAXLINESIZE 250
# define MAXDESCSIZE 200

typedef struct {
	int year;
	int month;
	int day;
} Date;

typedef struct {
	int id;
	Date due;
	char description[MAXDESCSIZE];
} TodoItem;

char *parseInt( char *s, int *value );

int readItemsFromFile( char *file, int maxNrOfItems, TodoItem arr[maxNrOfItems] );
void saveItemsToFile( char *file, int nrOfExistingItems, TodoItem arr[] );

void showTodoItems( TodoItem todolist[], int nrOfExistingItems );
void sortItemsByDate( TodoItem items[], int nrOfExistingItems );
int deleteItem( TodoItem todolist[], int nrOfExistingItems, int itemID );
int addTodo( int maxNrOfItems, int nrOfExistingItems, TodoItem todos[], TodoItem newTodo );
int getFreeID( int nrOfItems, TodoItem todos[] );

char *parseDate( char *s, Date *d );
char *parseInt( char *s, int *value );
