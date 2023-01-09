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
        if (key == -1 || load_factor >1.00)
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
        if (key == -1 || load_factor > 1.00)
        {
            break;
        }
        printf("\nTable\n");
        for (int j = 0; j < size2; j++)
        {
            printf("%d ", table2[j]);
        }
    }
    printf("LF > 1.00\n");
    return 0;
}
