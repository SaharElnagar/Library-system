#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "StandardTypes.h"
#include <stdlib.h>
#include<stdio.h>

#define FALSE 0
#define TRUE  1
typedef struct
{
	/*USER IMP */
	u16 ID;
	u8 Name[10];
	u8 Age;
}gStrData_t;

void Append(gStrData_t Data );
u8 Find_Node(u16 user_id);
u8 Update_Node(u16 user_id,gStrData_t* Node_data_address);
void print_nodes(void);
void Num_of_Nodes(void);
void Delete_Node(u32 val);
void Delete_Tail(void);
void Delete_Head(void);
void Delete_LinkedList(void);

#endif
