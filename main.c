#include"User.h"
#include"Admin.h"





int main()
{
  s8 inner_case,Exit_flag=0;
  u16 user_ID,book_id;
  u8 age;
  s8 name[10];
  Add_User(2,"Sahar",22);
  Add_User(10,"Ahmed",15);
  Reserve_Book(2,2);
  printf("Welcome to system\n");
  printf("Enter A for Admin login and U for User login:  \n");
  scanf("%c",&inner_case);
  while(1)
	  {
  switch(inner_case)
  {

	        case'A':      //Admin
			 inner_case='S';
             break;
			case'S':   //Enter Password
				if(Enter_Admin_Pass()==A_WRONG_PASS)
					inner_case='W';
				else
					inner_case='I'; // correct pass
			break;
			case'W':   // Wrong Password
			  printf("Incorrect password retry\n");
			  	if(Enter_Admin_Pass()==A_WRONG_PASS)
				{
					printf("Incorrect password Exit\n");
					inner_case='O';
				}
				else
					inner_case='I'; // take input if correct pass

			break;
			case'I':   // Take Input
				printf("Enter D to add record\n");
				printf("Enter E to Edit record\n");
				printf("Enter R to  Reserve book\n");
				printf("Enter U to  User mode\n");
				printf("Enter C to Cancel book reservation\n");
				fflush(stdin);
				printf("Enter O to  Exit system\n");

				scanf("%c",&inner_case);
			break;
			case'D':   // Add record

			    printf("Enter user ID\n");
				scanf("%d",&user_ID);
				printf("Enter user Name\n");
				scanf("%s",name);
				printf("Enter user age\n");
				fflush(stdin);
				scanf("%d",&age);
			    while(Add_User(user_ID,name,age)==A_REPEATD_ID)
				{
				  printf("this ID is taken enter another one\n");
                   scanf("%d",&user_ID);
				}
				inner_case='I';
			break;
			case'E':   // Edit record
			    printf("Enter user ID\n");
				scanf("%d",&user_ID);
				printf("Enter user New Name\n");
				scanf("%s",name);
				printf("Enter user New age\n");
				fflush(stdin);
				scanf("%d",&age);
				if(Edit_Record(user_ID,name,age)==A_USER_NOT_FOUND)
					printf("USER_NOT_FOUND\n");
			   inner_case='I';
			break;
			case'R':   // Reserve book
			   printf("Enter user ID\n");
			   scanf("%d",&user_ID);
			   printf("Enter Book ID between 1 to 4 \n");
			   scanf("%d",&book_id);
			   if(Reserve_Book(book_id,user_ID)==A_USER_NOT_FOUND)
                printf("USER_NOT_FOUND\n");
                fflush(stdin);
			   while(book_id>NUM_BOOKS)
				{
				  printf("Enter Book ID between 1 to 4 \n");
			      scanf("%d",&book_id);
				}
				if(Reserve_Book(book_id,user_ID)==A_BOOK_IS_RESERVED)
					printf("Book IS RESERVED");
			   inner_case='I';
			break;

			case'C':   // Cancel book reservation
			 printf("Enter Book ID between 1 to 4 \n");
			 scanf("%d",&book_id);
			 inner_case='I';
			break;

			case'O':   // Exit system
			Exit_flag=1;
		    break;

        case'U':       //User
        inner_case='i';
        break;
		 case'i':   // Take Input

		    printf("Enter P to Print_all_users\n");
		    printf("Enter A to Admin mode\n");
			printf("Enter L to Print all Reservation\n");
			printf("Enter V to Print_Available books \n");
			printf("Enter O to  Exit system\n");
			fflush(stdin);
			scanf("%c",&inner_case);
		 break;
		 case'P':   // Print_all_users
			 Print_all_users();
			 inner_case='i';
		 break;
		 case'L':   // Print_Reservation
			Print_Reservation();
			inner_case='i';
		 break;
		 case'V':   // Print_Available
		    Print_Available();
		    inner_case='i';
		 break;


	  }
	  if(Exit_flag==1)
        break;
  }

  return 0;
}
