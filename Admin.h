#ifndef _ADMIN_H
#define _ADMIN_H

#include "StandardTypes.h"
#include "Linked_list.h"


#define NUM_BOOKS         4
#define FALSE             0
#define TRUE              1
/**********************************Structures&Enums******************************/

typedef struct
 {
   u16 ID;
   s8* Name;
   u8 Available;    
   u16 User_id ;   
 }str_BooK;

typedef enum
{
A_NO_ERRORS=0,
A_NULL_POINTER,
A_WRONG_PASS,
A_REPEATD_ID,
A_USER_NOT_FOUND,
A_BOOK_ID_NOT_FOUND,
A_BOOK_IS_RESERVED,
	
	
}enum_Admin_Errors;

enum_Admin_Errors Enter_Admin_Pass(void);
enum_Admin_Errors Add_User(u16 id,s8*Name,u8 age);
enum_Admin_Errors Reserve_Book(u16 book_id,u16 user_id);
enum_Admin_Errors Edit_Record(u16 id,s8*name,u8 age);
enum_Admin_Errors Cancel_Reservation(u16 book_id);

#endif