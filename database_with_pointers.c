/*
Implement Database Management using array of structures with operations Create, Display,
Modify, Append, Search and Sort.
(For any database like Employee or Bank database with and without pointers to structures)
*/

#include <stdio.h>
#include <stdlib.h>

//definition of structure
typedef struct student
    {
        int roll_no;//members of structure
        char name[15];//members of structure
        int mrks;//members of structure
    }stud;//datatype



int main()
{
    //struct student stud[20]; //structure array variable
    stud *s;    //structure pointer variable

    int n,op,i, ele;
    void disp(stud *, int );//declaration of function
    void create(stud *, int );
    int append(stud *, int );
    void modify(stud *, int );
    void search(stud *, int , int );
    void sort(stud *, int);

    do{
        printf("\n 1.create \n 2.display \n 3.Modify \n 4.Append \n 5.Search \n 6.Sort \n 7.exit");
        printf("\n Enter your option: ");
        scanf("%d", &op);

        switch(op)
        {
           case 1:
                printf("\n Enter number of students:");
                scanf("%d",&n);

                create(&s,n);  //call to function
                break;
            case 2:
                disp(&s, n);
                break;
            case 3:
                 //modify
                 disp(&s, n);
                 modify(&s, n);
                 disp(&s, n);
                break;
            case 4:
                //append
               n = append(&s, n);//n=2
                break;
            case 5:
                //search
                printf("\nEnter the roll number you want to search: ");
                scanf("%d", &ele);
                search(&s, n, ele);
                break;
            case 6:
                //sort
                sort(&s,n);
                break;
        }
    }while(op!=7);
    return 0;
}


void create(stud *s, int n)
{
   for(int i=0;i<n;i++)
        {
            printf("\n Enter data of student %d: ",i+1);
            printf("\n Enter roll no, name and marks: ");
            scanf("%d%s%d",&(s+i)->roll_no,(s+i)->name,&(s+i)->mrks);
        }
}

void disp(stud *s, int n)
{
  printf("\n*************database*************");
  printf("\n index \t\tRoll no.\t Name \t Marks");
  for(int i=0;i<n;i++)
    printf("\n index=%d \t%d\t\t %s \t %d",i,(s+i)->roll_no,(s+i)->name,(s+i)->mrks);
}

void sort(stud *s, int n)//bubble: ascending
{
    stud temp;
    for(int i=0;i<n-1;i++)//iterations
    {
        for(int j=0;j<n-i-1;j++)//comparison
        {
            if((s+j)->roll_no > (s+j+1)->roll_no)
            {
                temp = *(s+j);
                *(s+j)= *(s+j+1);
                *(s+j+1) = temp;
            }
        }
    }
}

void modify(stud *s, int n) 
{
    int i;
    printf("\nEnter roll number you want to modify: ");
    scanf("%d", &i);
    printf("\n index \t\tRoll no.\t Name \t Marks");
    printf("\n index=%d \t%d\t\t %s \t %d",i-1,(s+i)->roll_no,(s+i)->name,(s+i)->mrks);
    printf("\nEnter new roll number: ");
    scanf("%d",&(s+i)->roll_no);
    printf("\nEnter new Name: ");
    scanf("%s",(s+i)->name);
    printf("\nEnter new marks: ");
    scanf("%d",&(s+i)->mrks);
    
}

int append(stud *s, int n)
{
    int i;
    i = n;
    printf("\nEnter information of student %d:\n",i);
    printf("Enter name: ");
    scanf("%s",(s+i)->name);
        
    printf("Enter roll number: ");
    scanf("%d",&(s+i)->roll_no);
        
    printf("Enter marks: ");
    scanf("%d",&(s+i)->mrks);
    
    n++;
    return n;
}

void search(stud *s, int n, int ele)
{
    int i, j = 0;
    for(i = 0; i < n; i++)
        if ((s+i)->roll_no == ele) {
            printf("\n index \t\tRoll no.\t Name \t Marks");
            printf("\n index=%d \t%d\t\t %s \t %d",i,(s+i)->roll_no,(s+i)->name,(s+i)->mrks);
            j++;
        }
    
    if (j == 0)
        printf("\nSorry Roll number not found :(");
}
