#Double Hashing

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define cls() (system("cls"))
#define pause() (system("pause"))

int main()
{
    const int size = 10;
    int table[10], key, value, COPRIME = 5;
    for (int i = 0; i < size; i++)
    {
        table[i] = -1;
    }
    cls();
    for (int i = 0; i < size; i++)
    {
        fflush(stdin);
        printf("\nEnter value : ");
        scanf("%d", &value);
        key = value % 11;
        if (table[key - 1] == -1)
        {
            table[key - 1] = value;
        }
        else
        {
            int key1, final_key;
            key1 = value % COPRIME;
            if (key1 == 0)
            {
                COPRIME += 1;
            }
            for (int j = 0; j < 100; j++)
            {
                final_key = (key + (j * key1)) % 11;
                if (table[final_key - 1] == -1)
                {
                    table[final_key - 1] = value;
                    break;
                }
            }
        }
        printf("\nTable\n");
        for (int j = 0; j < size; j++)
        {
            printf("%d ", table[j]);
        }
    }
    printf("\nTable is full.");
    return 0;
}

#Quadratic Probing

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define cls() (system("cls"))
#define pause() (system("pause"))

int main()
{
    const int size = 10;
    int table[10], key, value, c1 = 3, c2 = 5;
    for (int i = 0; i < size; i++)
    {
        table[i] = -1;
    }
    cls();
    for (int i = 0; i < size; i++)
    {
        fflush(stdin);
        printf("\nEnter value : ");
        scanf("%d", &value);
        for (int j = 0; j < size; j++)
        {
            key = (value + (j * c1) + (j * j * c2)) % 11;
            if (table[key - 1] == -1)
            {
                table[key - 1] = value;
                break;
            }
        }
        printf("\nTable\n");
        for (int j = 0; j < size; j++)
        {
            printf("%d ", table[j]);
        }
    }
    printf("\nTable is full.");
    return 0;
}

#Rehashing

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define cls() (system("cls"))
#define pause() (system("pause"))

int main()
{
    const int size1 = 10;
    const int size2 = 20;
    int table1[10], table2[20], key, value, count = 0;
    float load_factor;
    cls();

    for (int i = 0; i < size1; i++)
    {
        table1[i] = -1;
    }
    for (int i = 0; i < size2; i++)
    {
        table2[i] = -1;
    }

    for (int i = 0; i < size1; i++)
    {
        fflush(stdin);
        printf("\nEnter value : ");
        scanf("%d", &value);
        key = -1;
        for (int j = 0; j < size1; j++)
        {
            key = (value + j) % size1;
            if (table1[key] == -1)
            {
                table1[key] = value;
                count++;
                break;
            }
            else
            {
                key = -1;
            }
        }
        load_factor = (float)count / size1;
        if (key == -1 || load_factor > 0.75)
        {
            break;
        }
        printf("\nTable\n");
        for (int j = 0; j < size1; j++)
        {
            printf("%d ", table1[j]);
        }
    }

    printf("Rehashing\n");
    for (int i = 0; i < size1; i++)
    {
        if (table1[i] != -1)
        {
            value = table1[i];
            for (int j = 0; j < size2; j++)
            {
                key = (value + j) % size2;
                if (table2[key] == -1)
                {
                    table2[key] = value;
                    break;
                }
            }
        }
    }

    printf("\nTable\n");
    for (int i = 0; i < size2; i++)
    {
        printf("%d ", table2[i]);
    }

    for (int i = 0; i < size2; i++)
    {
        fflush(stdin);
        printf("\nEnter value : ");
        scanf("%d", &value);
        key = -1;
        for (int j = 0; j < size2; j++)
        {
            key = (value + j) % size2;
            if (table2[key] == -1)
            {
                table2[key] = value;
                count++;
                break;
            }
            else
            {
                key = -1;
            }
        }
        load_factor = (float)count / size2;
        if (key == -1 || load_factor > 0.75)
        {
            break;
        }
        printf("\nTable\n");
        for (int j = 0; j < size2; j++)
        {
            printf("%d ", table2[j]);
        }
    }
    printf("LF > 0.75\n");
    return 0;
}

#Stack

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

#define cls() (system("cls"))
#define pause() (system("pause"))

const int size = 5;
char stack[5];
int top = -1;

void push()
{
    if (top == size - 1)
    {
        printf("The stack is full. ");
        return;
    }
    char temp;
    printf("Enter element : ");
    scanf("%c", &temp);
    if (isalpha(temp) == 0)
    {
        printf("\nERROR: Entered value is not a character. \n");
    }
    else if (temp == stack[top])
    {
        printf("\nERROR: Entered value is same as top. ");
    }
    else
    {
        stack[++top] = temp;
        printf("\nElement added. ");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nERROR: The stack is empty. ");
        return;
    }
    printf("\nElement %c removed. ", stack[top--]);
}

void occurence()
{
    if (top == -1)
    {
        printf("\nERROR: The stack is empty. ");
        return;
    }
    int count, frequency[5];
    for (int i = 0; i <= top; i++)
    {
        count = 1;
        for (int j = i + 1; j <= top; j++)
        {
            if (stack[i] == stack[j])
            {
                count++;
                frequency[j] = 0;
            }
        }
        if (frequency[i] != 0)
        {
            frequency[i] = count;
        }
    }
    for (int i = 0; i <= top; i++)
    {
        if (frequency[i] != 0)
        {
            printf("'%c' : %d\n", stack[i], frequency[i]);
        }
    }
}

void menu()
{
    int choice;
    cls();
    fflush(stdin);
    printf("\n1.Push\n2.Pop\n3.Occurence\n4.Exit\n");
    scanf("%d", &choice);
    cls();
    fflush(stdin);
    switch (choice)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        occurence();
        break;
    case 4:
        exit(0);
    default:
        menu();
    }
    pause();
    menu();
}

int main()
{
    menu();
    return 0;
}