#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>

struct node
{
char name[50];
struct node *link;
};

struct node *first=NULL;
struct node *newnode;
struct node *temp;

void add_kid(char *na)
{
  newnode=(struct node*)malloc(sizeof(struct node));
  strcpy(newnode->name,na);
  newnode->link=newnode;
  if(first==NULL)
  {
       first=newnode;
  }
  else
  {
     temp=first->link;
     while(temp->link!=first)
     {
	temp=temp->link;
     }
     newnode->link=temp->link;
     temp->link=newnode;
  }
}
void display()
{
   int i=2;
   if(first==NULL)
   {
      printf("\nTHERE IS NO KID");
      return;
   }
   else
   {
      printf("\n1>  %s",first->name);
      temp=first->link;
      while(temp!=first)
      {
	printf("\n%d>  %s ",i,temp->name);
	temp=temp->link;
	i++;
      }
   }
}

void eliminate_kid(int pos)
{
  int i;
  struct node *prev;
  while(first->link!=first)
  {
      if(pos==1)
      {
	printf("\n\n%d '%s IS ELEMENETED\n",pos,first->name);
	temp=first->link;
	while(temp!=first)
	{
	   prev=temp;
	   temp=temp->link;
	}
	prev->link=temp->link;
	first=prev->link;
      }
      else
      {
	temp=first;
	for(i=1;i<pos;i++)
	{
	  prev=temp;
	  temp=temp->link;
	}
	prev->link=temp->link;
	printf("\n\nPASSES=%d '%s IS ELEMENETED\n",pos,temp->name);
	first=prev->link;
      }
      printf("\n\nKIDS STILL IN GAME");
     }
}

void main()
{
  int i,choice,k,n;
  char name[50];
  clrscr();

  do
  {
    printf("\n1> FOR ENTER KIDS");
    printf("\n2> FOR START ELIMINATION");
    printf("\n3> FOR EXIT");
    printf("\nENTER YOUR CHOICE:");
    scanf("%d",&choice);

   switch(choice)
   {
    case 1:printf("\nENTER NUMBER OF KIDS:");
	   scanf("%d",&k);
	   for(i=1;i<=k;i++)
	   {
		   printf("\nENTER NAME:");
		   scanf("%s",&name);
		   add_kid(name);
	   }
	   break;

    case 2: printf("\nENTER RANDOM NUMBER AMONG (1-%d) :",k-1);
	    scanf("%d",&n);
	    printf("\nTOTAL KIDS IN GAME");
	    display();
	    eliminate_kid(n);
	    printf("\n\n\nKID' %s 'WIN THE GAME",first->name);
	    printf("\n\n****CONGRATULATION*****\n");
	    break;

    case 3:
	   exit(0);
	    break;

    default:printf("\n->PLEASE ENTER PROPER CHOICE:");
   }
  }while(choice!=3);
  getch();
}
