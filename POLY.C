#include<stdio.h>
#include<conio.h>
struct clist
{
int coef;
int xexpo,yexpo,zexpo;
struct clist *next;
};
int compare(struct clist *temp1,struct clist *temp2)
{
if(temp1->xexpo==temp2->xexpo&&temp1->yexpo==temp2->yexpo&&temp1->zexpo==temp2->zexpo)
return 0;
if(temp1->xexpo>temp2->xexpo)
return 1;
if(temp1->xexpo==temp2->xexpo&&temp1->yexpo==temp2->yexpo&&temp1->zexpo>temp2->zexpo)
return 1;
return -1;
}
 void addtolist(int coef,int xexpo,int yexpo,int zexpo,struct clist *first)
 {
 struct clist *temp,*cur;
 temp=(struct clist*)malloc(sizeof(*temp));
 temp->coef=coef;
 temp->xexpo=xexpo;
 temp->yexpo=yexpo;
 temp->zexpo=zexpo;
 temp->next=first;
 first=temp;
 cur=first;
 while(cur->next!=first)
 {
 cur=cur->next;
 break;
 }
 cur->next=temp;
 }

    void addpoly(struct clist *first,struct clist *second,struct clist *res)
    {
    struct clist *temp1,*temp2;
    temp1=first->next;
    temp2=second->next;
    while(temp1!=first&&temp2!=second)
    {
    switch(compare(temp1,temp2))
    {
    case 0:addtolist(temp1->coef+temp2->coef,temp1->xexpo,temp1->yexpo,temp1->zexpo,res);
    temp1=temp1->next;
    temp2=temp2->next;
    break;
    case 1:addtolist(temp1->coef,temp1->xexpo,temp1->yexpo,temp1->zexpo,res);
    temp1=temp1->next;
    break;
    case -1:addtolist(temp2->coef,temp2->xexpo,temp2->yexpo,temp2->zexpo,res);
    temp2=temp2->next;
    break;
    }
     while(temp1!=first)
     {
      addtolist(temp1->coef,temp1->xexpo,temp1->yexpo,temp1->zexpo,res);
      temp1=temp1->next;
     }
       while(temp2!=second)
       {
	addtolist(temp2->coef,temp2->xexpo,temp2->yexpo,temp2->zexpo,res);
	temp2=temp2->next;
       }
     }
   }

void display(struct clist *first)
{
struct clist *cur;
cur=first->next;
  while(cur!=first)
  {
  printf("\n+%dx^%dy^%dz^%d\n",cur->coef,cur->xexpo,cur->yexpo,cur->zexpo);
  cur=cur->next;
  break;
  }
}

 void main()
 {
 int xexpo,yexpo,coef,zexpo,ch,terms,i;
 struct clist *first,*second,*res;
 clrscr();
 first=(struct clist*)malloc(sizeof(first));
 first->next=first;
 second=(struct clist*)malloc(sizeof(second));
 second->next=second;
 res=(struct clist*)malloc(sizeof(res));
 res->next=res;
 printf("enter the no. of terms in polynomial1\n");
 scanf("%d",&terms);
  for(i=0;i<terms;i++)
   {
     printf("enter the coef,xexpo,yexpo,zexpo\n");
     scanf("%d%d%d%d",&coef,&xexpo,&yexpo,&zexpo);
     addtolist(coef,xexpo,yexpo,zexpo,first);
   }
  printf("\npolynomial1:\n");
  display(first);
  printf("enter the no. of terms in polynomial2\n");
  scanf("%d",&terms);
   for(i=0;i<terms;i++)
   {
    printf("enter the coef,xexpo,yexpo,zexpo\n");
    scanf("%d%d%d%d",&coef,&xexpo,&yexpo,&zexpo);
    addtolist(coef,xexpo,yexpo,zexpo,second);
   }
  printf("polynomial2:\n");
  display(second);
  printf("the resultant polynomial is\n");
  addpoly(first,second,res);
  display(res);
  getch();
 }


