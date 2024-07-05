#include<stdio.h>
#include<string.h>
struct player 
{
    int jnumber;
    char playername[20];
    int runs;
    int wickets;
    int matchplayed;
};

void acceptplayerinfo(struct player*, int);
void displayplayerinfo(struct player*, int);
void addplayerinfo(struct player* , int ) ;
void searchplayerinfo(struct player*, int);
void updateplayerinfo(struct player*, int);
void removeplayerinfo(struct player*, int *);
void displaytopinfo(struct player*, int *);

int main() {
    int n, ch ;
    int exit = 0;
    printf("_____________________________________________PLAYERS INFORMATION_______________________________________________________\n");
    printf("\n Enter the number of plyers to add: ");
    scanf("%d", &n);
    struct player p[n];

    do {
        printf("1. Accept the player information\n");
        printf("2. Display all players\n");
        printf("3. Add the player information\n");
        printf("4. Update the player information\n");
        printf("5. Search for a player\n");
        printf("6. Remove a player\n");
        printf("7. Enter the top 3 players\n");
        printf("Enter your choice: \n");
        scanf("%d", &ch);
        printf("__________________________________\n");

        switch (ch) {
            case 1:
                acceptplayerinfo(p, n);
                break;
            case 2:
                displayplayerinfo(p, n);
                break;
            case 3:
            	 addplayerinfo(p,n);
            	 break;
            case 4:
                updateplayerinfo(p, n);
                break;
            case 5:
                searchplayerinfo(p, n);
                break;
            case 6:
                removeplayerinfo(p, &n);
                break;
            case 7:
                displaytopinfo(p, &n);
                break;
            default:
                printf("Invalid choice, please check again.\n");
        }

        printf("Enter 1 to continue, enter 0 to exit: ");
        scanf("%d", &exit);
    } while (exit == 1);

    return 0;
}
//------------------------------------------------------------------------------------------------------



void acceptplayerinfo(struct player* p, int n) 
{
    for (int i = 0; i < n; i++) 
	{
        printf("Enter the jersey number: ");
        scanf("%d", &p[i].jnumber);
        printf("Enter the player name: ");
        scanf("%s", p[i].playername);
        printf("Enter the runs which the player has gained: ");
        scanf("%d", &p[i].runs);
        printf("Enter the wickets: ");
        scanf("%d", &p[i].wickets);
        printf("Enter the total number of matches played: ");
        scanf("%d", &p[i].matchplayed);
        printf("__________________________________________\n");
    }
}
//--------------------------------------------------------------------------------------------------



void displayplayerinfo(struct player* p, int n) 
{
    printf("__________________________________________________________________________________________________\n");
    printf("|jersey number       | Player name       | Total runs       | Total wickets      | Match played\n");
    printf("_____________________________________________________________________________________________________\n");
    for (int i = 0; i < n; i++) 
	{
        printf("|%-14d|%-25s|%-25d|%-15d|%-15d|\n", p[i].jnumber, p[i].playername, p[i].runs, p[i].wickets, p[i].matchplayed);
        printf("_____________________________________________________________________________________________\n");
    }
}
//------------------------------------------------------------------------------------------------------



void addplayerinfo(struct player* p, int n) 
{
    for (int i = 0; i < n; i++) 
	{
        printf("Enter the jersey number: ");
        scanf("%d", &p[i].jnumber);
        printf("Enter the player name: ");
        scanf("%s", p[i].playername);
        printf("Enter the runs which the player has gained: ");
        scanf("%d", &p[i].runs);
        printf("Enter the wickets: ");
        scanf("%d", &p[i].wickets);
        printf("Enter the total number of matches played: ");
        scanf("%d", &p[i].matchplayed);
        printf("__________________________________________\n");
    }
    displayplayerinfo(p,n);
}
//------------------------------------------------------------------------------------------------------


void searchplayerinfo(struct player* p, int n) 
{
	int ch;
    printf("Enter your choice:\n 1. Based on jersey number\n 2. Based on player name\n");
    scanf("%d", &ch);
    int jnumber, found = 0;
    char found1=0;
    char playername[20];

    
     if(ch==1)
     {
     	int i;
     	printf("Enter the jersey number you want to search: ");
	    scanf("%d", &jnumber);
		 
	    for (int i = 0; i < n; i++) 
		{
	        if (p[i].jnumber == jnumber) 
			{
	            found = 1;
	            printf("Jersey number %d is found.\n", jnumber);
	            break;
	      	}
   		}
	    if(p[i].jnumber!=found)
	    {
	    	printf("jersey number is not found %s",jnumber);
		}
	}
  		if(ch==2)
	  {	
	  int i;
	    scanf("%s", &playername);
	  	for (int i = 0; i < n; i++) 
		{
	        if (strcmp(p[i].playername,playername )==0) 
			{
	            found = 1;
	            printf("player name %s is found.\n", playername);
	            break;
	        }
	    }
	    if(found==0)
	    {  
	    	printf("player name is not found %s",playername);
		}
	  }
}
//---------------------------------------------------------------------------------------------------

void updateplayerinfo(struct player* p, int n) 
{
    int jnumber, found = 0;

    printf("Enter the jersey number you want to update: ");
    scanf("%d", &jnumber);

    for (int i = 0; i < n; i++) 
	{
        if (p[i].jnumber == jnumber) 
		{
            found = 1;
            printf("Enter the new jersey number: ");
            scanf("%d", &p[i].jnumber);
            printf("Enter the new run record: ");
            scanf("%d", &p[i].runs);
            printf("Enter the new wickets record: ");
            scanf("%d", &p[i].wickets);
            printf("Enter the new number of matches played by the player: ");
            scanf("%d", &p[i].matchplayed);
            printf("Player information is successfully updated.\n");
            break;
        }
    }

    if (found == 0) 
	{
        printf("Jersey number %d is not found.\n", jnumber);
    }
    printf("_____________________________________________\n");
}
//-----------------------------------------------------------------------------------------------------

void removeplayerinfo(struct player* p, int *n) 
{
    int jnumber;
    int found = 0;

    printf("Enter the jersey number which you want to remove: ");
    scanf("%d", &jnumber);

    for (int i = 0; i < *n; i++) 
	{
        if (p[i].jnumber == jnumber) 
		{
            found = 1;
            for (int j = i; j < *n - 1; j++) 
			{
                p[j] = p[j + 1];
            }
            (*n)--;
            printf("Player with jersey number %d has been removed.\n", jnumber);
            break;
        }
    }

    if (!found) {
        printf("Jersey number %d is not found.\n", jnumber);
    }
}
//----------------------------------------------------------------------------------------------------

void displaytopinfo(struct player* p, int *n) 
{
    int ch;
    printf("Enter your choice:\n 1. Based on runs\n 2. Based on wickets\n");
    scanf("%d", &ch);

    if (ch == 1) {
        struct player a;
        for (int i = 0; i < *n - 1; i++)
		 {
            for (int j = i + 1; j < *n; j++) 
			{
                if (p[i].runs < p[j].runs) 
				{
                    a = p[i];
                    p[i] = p[j];
                    p[j] = a;
                }
            }
        }

        printf("Top players based on runs:\n");
        printf("__________________________________________________________________________________________________\n");
        printf("|jersey number  | Player name          | runs           | wickets        | matches played\n");
        printf("__________________________________________________________________________________________________\n");

        for (int i = 0; i < *n; i++) 
		{
            printf("|%-14d|%-25s|%-15d|%-15d|%-15d|\n", p[i].jnumber, p[i].playername, p[i].runs, p[i].wickets, p[i].matchplayed);
        }

        printf("__________________________________________________________________________________________________\n");
    }
    if (ch == 2)
	 {
        struct player a;
        for (int i = 0; i < *n - 1; i++) 
		{
            for (int j = i + 1; j < *n; j++) 
			{
                if (p[i].wickets < p[j].wickets) 
				{
                    a = p[i];
                    p[i] = p[j];
                    p[j] = a;
                }
            }
        }

        printf("Top players based on wickets:\n");
        printf("__________________________________________________________________________________________________\n");
        printf("|jersey number  | Player name          | runs           | wickets        | matches played\n");
        printf("__________________________________________________________________________________________________\n");

        for (int i = 0; i < *n; i++) 
		{
            printf("|%-14d|%-25s|%-15d|%-15d|%-15d|\n", p[i].jnumber, p[i].playername, p[i].runs, p[i].wickets, p[i].matchplayed);
        }

        printf("__________________________________________________________________________________________________\n");
    }
}