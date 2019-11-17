#include"User.h"

extern str_BooK Books[NUM_BOOKS];

void Print_all_users (void)
{
	print_nodes();
}

void Print_Reservation(void)
{
	u16 count=0,i;
	for(i=0;i<NUM_BOOKS;i++)
		{
			if(Books[i].Available==FALSE)
			{
			 if(i==0)
             fflush(stdin);
			 printf("User_ID Book_ID Name \n");
			 printf("%d",Books[i].User_id);
		     printf("    %d",Books[i].ID);
			 printf("    %s     \n",Books[i].Name);
			}
			else
			{
			count++;
			}
		}
		if(count==NUM_BOOKS)
			printf("No Reserved books\n");
}

void Print_Available(void)
{
 	u16 count=0,i;
	for(i=0;i<NUM_BOOKS;i++)
		{
			if(Books[i].Available==TRUE)
			{
			 if(i==0)
			 printf("Book_ID Name\n");
		     printf("%d",Books[i].ID);
			 printf("       %s\n",Books[i].Name);
			}
			else
			{
			count++;
			}
		}
		if(count==NUM_BOOKS)
			printf("No Available books\n");
}


