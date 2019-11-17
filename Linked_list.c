
#include "Linked_list.h"



typedef struct myNode
{
	gStrData_t node_data;
	struct myNode* Next;
}Node;

Node* Head=NULL_POINTER ;
Node* Tail=NULL_POINTER ;

void Append(gStrData_t Data )
{
	Node* NewNode= (Node*)malloc(sizeof(Node));
	NewNode->node_data=Data;
	if(Head==NULL_POINTER)
	{
		Head=NewNode;
		NewNode->Next=NULL_POINTER;
		Tail=NewNode;
		Tail->Next=NULL_POINTER;
	}
	else
	{
		Tail->Next=NewNode;
		Tail=NewNode;
		Tail->Next=NULL_POINTER;
	}
}


void print_nodes(void)
{
	Node* Current_Node=Head;
	if(Current_Node==NULL_POINTER)
	{
		printf("Empty LinkedList\n");
	}
	printf("ID Age Name  \n");
	while(Current_Node!=NULL_POINTER){
		printf("%d",Current_Node->node_data.ID);
		printf(" %d",Current_Node->node_data.Age);
		printf(" %s       \n",Current_Node->node_data.Name);
		Current_Node=Current_Node->Next;
	}
}

u8 Find_Node(u16 user_id)
{
   Node* Current_Node=Head;
   while(Current_Node!=NULL_POINTER)
   {
	   if(Current_Node->node_data.ID==user_id)
	   {
		   return TRUE ; // Found
	   }
	   Current_Node=Current_Node->Next;
   }
   return FALSE;  //Not Found
}

u8 Update_Node(u16 user_id,gStrData_t* Node_data_address)
{
   Node* Current_Node=Head;
   while(Current_Node!=NULL_POINTER)
   {
	   if(Current_Node->node_data.ID==user_id)
	   {
           Node_data_address=(gStrData_t*)Current_Node;
		   return TRUE ; // Found
	   }
	   Current_Node=Current_Node->Next;
   }
   return FALSE;  //Not Found
}




void Num_of_Nodes(void)
{
u32 count =0;
Node* Current_Node=Head;
		while(Current_Node!=NULL_POINTER){
		count++;
		Current_Node=Current_Node->Next;
		}
		printf("Num_of_Nodes: %d\n",count);
}
/*
void Delete_Node(u32 val)
{   Node* Current_Node=Head;
    Node*temp;
	while(Head->value==val){
		temp=Head;
		Head=Head->Next;
		free(temp);
		Current_Node=Head;
	}
	while(Current_Node->Next!=NULL_POINTER)
	{
		if((Current_Node->Next->value)==val)
		{
	        temp=Current_Node->Next;
			Current_Node->Next=Current_Node->Next->Next;
	        free(temp);
		}
		else
		Current_Node=Current_Node->Next;
	}
	}
*/
void Delete_Head(void)
{
	printf("delete_Head\n");
	Node*Temp;
    Temp=Head;
    Head=Head->Next;
    free(Temp);
}

void Delete_Tail(void)
{
	printf("Delete_Tail\n");
	Node* Current_Node=Head;
	while(Current_Node->Next!=Tail)
	{
		Current_Node=Current_Node->Next;
	}
	Current_Node->Next=NULL_POINTER;
	free(Tail);
	Tail=Current_Node;
}

void Delete_LinkedList(void)
{    printf("Delete_LinkedList\n");
	Node*Temp=Head;
	while(Temp->Next!=NULL_POINTER)
	{
		Head=Head->Next;
		free(Temp);
		Temp=Head;
	}
	free(Temp);
	Head=NULL_POINTER;
	Tail=NULL_POINTER;
}




