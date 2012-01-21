#include<stdio.h>
#include<conio.h>

struct node
{
int value;
struct node *link;
};
struct node *first=NULL;
struct node *newnode;
struct node *temp;

void push(int data)  //this function is used for push data into stack
{
  newnode=(struct node*)malloc(sizeof(struct node));//generate memory for new node
  newnode->value=data;
  newnode->link=NULL;         //create node

    if(first==NULL)
    {
	    first=newnode;
    }

    else
    {
	temp=first;
	while(temp->link!=NULL)
	{
	  temp=temp->link;
	}
	temp->link=newnode;
    }
}

int pop()
{
  int data;
  struct node *prev;

  if(first==NULL)
  {
	 printf("\n-->LIST IS EMPTY.");
	 return -1;
  }
  else
  {
    temp=first;
    while(temp->link!='\0')
    {
	 prev=temp;
	 temp=temp->link;
    }
    if(temp==first)
    {
      data=temp->value;
      first='\0';
    }
    else
    {
      data=temp->value;
      prev->link=temp->link;
    }
    return data;
  }
}

void main()
{
  int i,choice,no,r,last=0;
  int Stack[20],b=0;
  clrscr();

   do
   {
    printf("\n1> FOR PUSH INTO STACK");
    printf("\n2> FOR POP FROM STACK");
    printf("\n3> FOR EXIT FROM MENU");
    printf("\nENTER YOUR CHOICE:");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:printf("\nEnter Number:");
	     scanf("%d",&no);
	     if(no>9)
	     { printf("\n-->YOU HAVE ENTER NUMBER BETWEEN (0- 9):");}

	     else if(no>=last+2 || no<=last)
	     {
	       if(no==0)
	       {
				push(no);
	       }
	       else
	       {
				printf("\nLAST PUSHED NUMBER:%d",last);
				printf("\nPLESE PUSH NUMBER IN PROPER SEQUENCE\n");
	       }
	     }
	     else
	     {
		    last=no;
		    push(no);
	     }
	     break;

       case 2: r=pop();
				if(r!=-1)
				{
					Stack[b++]=r;
					printf("\nPOP element from stack:%d",r);
				}
				printf("\nElement in Stack:");
				for(i=0;i<b;i++)
				{
						printf("%d ",Stack[i]);
				}
				printf("\n");
				break;

      case 3: exit(0);
				break;

     default:printf("\n Please Enter Proper Choice");
    }
   }while(choice!=3);
   getch();
}