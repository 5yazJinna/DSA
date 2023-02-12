#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct book
{
    char title[100],author[100];
    int cpy,yr;
};
struct book b[200];
int n;

void add()
{
    int i;
    printf("Enter the number of books to be added : ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("\nEnter book %d details\n",i+1);
        printf("Book Title : ");
        scanf("%s",&b[i].title);
        printf("Author name : ");
        scanf("%s",&b[i].author);
        printf("No. of copies : ");
        scanf("%d",&b[i].cpy);
        printf("Year of publication : ");
        scanf("%d",&b[i].yr);
        printf("\n%s has been added successfully\n",b[i].title);
    }
    
}

void issue()
{
    int i;
    char bktitle[100];
    printf("\nEnter the title of book to be issued : ");
    scanf("%s",&bktitle);
    for(i=0;i<n;i++)
    {
        if (strcmp(bktitle,b[i].title)==0)
        {
            if(b[i].cpy>0)
            {
                b[i].cpy--;
                printf("%s has been issued successfully\n",b[i].title);
            }
            else
            {
                printf("%s is out of stock\n",b[i].title);
            }
        }
    }
}

void returnbk()
{
    int i;
    char bktitle[100];
    printf("\nEnter the title of book to be returned : ");
    scanf("%s",&bktitle);
    for(i=0;i<n;i++)
    {
        if (strcmp(bktitle,b[i].title)==0)
        {
            b[i].cpy++;
            printf("%s has been returned successfully\n",b[i].title);
        }

    }
}

void search()
{
    int pbyr,i;
    printf("Enter the publication year of the book : ");
    scanf("%d",&pbyr);
    for(i=0;i<n;i++)
    {
        if (pbyr==b[i].yr)
        {
            printf("%s\n",b[i].title);
        }

    }
}

void display()
{
    int i;
    printf("Books Available\n");
    for(i=0;i<n;i++)
    {   
        printf("Title : %s",b[i].title);
        printf("Author : %s",b[i].author);
        printf("Year of publication : %d",b[i].yr);
        printf("No. of copies available : %d\n",b[i].cpy);
    }
}

void copy()
{
    int i;
    char bktitle[100];
    printf("Enter the book title : ");
    scanf("%s",&bktitle);
    for(i=0;i<n;i++)
    {
        if(strcmp(bktitle,b[i].title)==0)
        {
            printf("No. of copies = %d\n",b[i].cpy);
        }
    }

}

void main()
{
    int choice;
    printf("LIBRARY SYSTEMS MANAGEMENT\n");
    printf("1.Add book\n2.Issue book\n3.Return book\n4.Search book by year of publication\n5.Display available books information\n6.Check no. of copies available\n7.Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
        {
            add();
            main();
        }

        case 2:
        {
            issue();
            main();
        }

        case 3:
        {
            returnbk();
            main();
        }

        case 4:
        {
            search();
            main();
        }

        case 5:
        {
            display();
            main();
        }

        case 6:
        {
            copy();
            main();
        }

        case 7:
        {
            exit(0);
        }

        default:
        {
            printf("Enter a valid number");
            main();
        }
    }
}
