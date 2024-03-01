#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int *A = NULL;
    int sizeA = 0;
    int inputA = 0;

    int *B = NULL;
    int sizeB = 0;
    int inputB = 0;

    while (true)
    {
        printf("1 - ввести отношение A\n2 - ввести отношения B\n3 - вывести отношения\n4 - выход\n");
        int choice = 0;
        scanf("%d", &choice);
        if (choice == 1)
        {
            while (true)
            {
                scanf("%lc", &inputA); // считываем значение
                if (inputA == '0')     // если ноль, прерываем цикл
                {
                    break;
                }
                if (inputA == 10)
                {
                    continue;
                }
                sizeA++;                             // увеличиваем размер массива на один
                A = realloc(A, sizeA * sizeof(int)); // изменяем размер памяти под массив
                if (A == NULL) // если не удалось выделить память, выводим ошибку и выходим
                { 
                    printf("Ошибка выделения памяти\n");
                    exit(1);
                }
                A[sizeA - 1] = inputA; // записываем значение в последнюю ячейку массива
            }
        }
        else if (choice == 2)
        {
            while (true)
            {
                scanf("%lc", &inputB); 
                if (inputB == '0')     
                {
                    break;
                }
                if (inputB == 10)
                {
                    continue;
                }
                sizeB++;                             
                B = realloc(B, sizeB * sizeof(int)); 
                if (B == NULL)
                { 
                    printf("Ошибка выделения памяти\n");
                    exit(1);
                }
                B[sizeB - 1] = inputB; 
            }
        }
        else if (choice == 3)
        {   
            printf("A: {");
            for (int i = 0; i < sizeA; i++)
            {
                if (i == sizeA - 1)
                {
                    printf("%c", B[i]);
                    continue;
                }
                printf("%c ", A[i]);
            }
            printf("}");
            printf("\n");

            printf("B: {");
            for (int i = 0; i < sizeB; i++)
            {   
                if (i == sizeB - 1)
                {
                    printf("%c", B[i]);
                    continue;
                }
                printf("%c ", B[i]);
            }
            printf("}");
            printf("\n");
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Введите цифру из меню\n");
        }
    }

    return 0;
}
