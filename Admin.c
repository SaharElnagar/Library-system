/**********************************Includes**************************************/
#include "Admin.h"
/**********************************Defines***************************************/
#define CORRECT_PASSWORD "1234"
#define PASSWORD_SIZE     4


/**********************************Globals***************************************/

str_BooK Books[NUM_BOOKS]={{1,"Lord of the rings",TRUE,NULL_VALUE} ,
	                       {2,"Great Expectations",TRUE,NULL_VALUE},
						   {3,"Alchemist",TRUE,NULL_VALUE},
						   {4,"Harry Potter",TRUE,NULL_VALUE}
						   };




/**********************************Functions_Implementation**********************/
 enum_Admin_Errors Enter_Admin_Pass(void)
 {
	 u16 i;
	 s8 pass[PASSWORD_SIZE];
     printf("Enter PASSWORD:\n");
     scanf("%s",pass);
	   for(i=0;i<PASSWORD_SIZE;i++)
	   {
		  if(pass[i]!=CORRECT_PASSWORD[i])
          {
			return A_WRONG_PASS;
		  }
	   }
	 return A_NO_ERRORS;
 }


enum_Admin_Errors Add_User(u16 id,s8*Name,u8 age)
{
	u16 i;
	if(Name==NULL_POINTER)
	{
	    return A_NULL_POINTER;
	}
	else
	{
		if(Find_Node(id))
		{
			return A_REPEATD_ID;
		}
		else
		{
			gStrData_t New_Data;
			New_Data.ID=id;
			for(i=0;Name[i]!='\0';i++)
			 New_Data.Name[i]=Name[i];
		    New_Data.Age=age;
			Append(New_Data);
		}
	}
    return A_NO_ERRORS;
}
enum_Admin_Errors Reserve_Book(u16 book_id,u16 user_id)
{
	int i;
	if(Find_Node(user_id))
	{
		if(book_id>NUM_BOOKS)
		{
			return A_BOOK_ID_NOT_FOUND;
		}
		else
		{
			/*Reserve_Book*/
			for(i=0;i<NUM_BOOKS;i++)
			{
				if(Books[i].ID==book_id)
				{
				  if(Books[i].Available==FALSE)
				  {
					return A_BOOK_IS_RESERVED;
				  }
				  else
				  {
					Books[i].User_id=user_id	;
					Books[i].Available=FALSE;
					break;
				  }
				}
			}
		}
	}
	else
	{
		return A_USER_NOT_FOUND	;
	}
	return A_NO_ERRORS;
}


enum_Admin_Errors Edit_Record(u16 id,s8*name,u8 age)
{
	gStrData_t* record;
	u16 i=0;
	if(name==NULL_POINTER)
	{
	    return A_NULL_POINTER;
	}
	else
	{
		if(Update_Node(id,record))
		{    for(i=0;name[i]!='\0';i++)
			 record->Name[i]=name[i];
			 record->Age=age;
		}
		else
		{
		  return A_USER_NOT_FOUND	;
		}
	}
    return A_NO_ERRORS;
}


enum_Admin_Errors Cancel_Reservation(u16 book_id)
{
	u16 i;
	if(book_id>NUM_BOOKS)
		{
			return A_BOOK_ID_NOT_FOUND;
		}
		else
		{
			for(i=0;i<NUM_BOOKS;i++)
			{
				if(Books[i].ID==book_id)
				{
				 Books[i].Available=TRUE;
				}
			}
		}
	return A_NO_ERRORS;
}






