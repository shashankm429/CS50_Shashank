

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;


int tile;
int blankspace;
int x;
int y;
int i;
int j;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

/**
 * Main function - sets up how game will operate.
 */
int main(int argc, string argv[])
{
    // greet player
    greet();
       // open log
    FILE* file = fopen("log.txt", "w");

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }
    
    // initialixing x and y here so 0 does not reset every time you call move function
    else
    {
        x = (d - 1);
        y = (d - 1);
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();
        
          // log the current state of the board (for testing)

        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
           // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }
        
           // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);
        
        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }
     fclose(file);
    // that's all folks
    return 0;
}


void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}


void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}


void init(void)
{
    
    
    int n = 0;

    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            
            n = n + 1;
            board[i][j] = (d*d - n);
        }
    }   
    
    if ((d % 2) == 0)
    {
        int temp = board[d - 1][d - 2];
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = temp; 
    }   
     
}


void draw(void)
{
    
    int n = 0;

    
    for (int i = 0; i < d; i++)
    {
        
        for (int j = 0; j < d; j++)
        {
            n = (n + 1); 

            
            if (board[i][j] > 0) 
            {
                printf("| %d ", board[i][j]);
            }

            
            if (board[i][j] == 0) 
            {
                printf("|__ ");
            }
        }
        
        printf("|\n"); 
    }    
      
}


bool move(int tile)
{
  
    for (int i = 0; i < d; i++) 
    {
        
        for (int j = 0; j < d; j++) 
        {
            
            if(tile == board[i][j]) 
            {
               
                int space = 0;       

                if (((x == (i - 1)) && (j == y)) ||  ((x == (i + 1)) && (j == y)) ||
                ((i == x) && (y == (j - 1))) || ((i == x) && (y == (j + 1))))
                {
                    

                    board[x][y] = tile;
                    board[i][j] = space;
                    x=i;
                    y=j;


                    return true;
                }   
            } 
        }
    }
    return false;
}


bool won(void)
{
    
    int n = 0;

    
    for (int i = 0; i < d; i++) 
    {
        for (int j = 0; j < d; j++)
        {
            
            n = n + 1;

            
          
           if (board[i][j] != n )
            {
                if ( i != d-1 || j != d-1)
                {return false;}
                
            }
        } 
    }
    
    return true;
}

