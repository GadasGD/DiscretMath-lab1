#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void remove_duplicates(int *array, int size);
void merge(int *a, int size);
void input_arr(int *A, int sizeA);


int main()
{
    int *A = NULL;
    int sizeA;

    int *B = NULL;
    int sizeB;

    int *Results = NULL;
    int sizeR = 0;
    int inputR = 0;

    while (true)
    {
        printf("1 - ввести отношение A\n2 - ввести отношения B\n3 - вывести отношения\n4 - u\n5 - выход\n");
        int choice = 0;
        scanf("%d", &choice);
        if (choice == 1)
        {
            input_arr(A, sizeA);
        }
        else if (choice == 2)
        {
            input_arr(B, sizeB);
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
            sizeR = sizeA + sizeB;
        }
        else if (choice == 5)
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


void input_arr(int *A, int sizeA)
{   
    sizeA = 0;
    int inputA = 0;
    while (true)
    {
        scanf("%lc", &inputA); // считываем значение
        if (inputA == '0')     // если ноль, прерываем цикл
        {
            break;
        }
        if (inputA == 10) // если значение пробел
        {
            continue;
        }
        sizeA++;                             // увеличиваем размер массива на один
        A = realloc(A, sizeA * sizeof(int)); // изменяем размер памяти под массив
        if (A == NULL)                       // если не удалось выделить память, выводим ошибку и выходим
        {
            printf("Ошибка выделения памяти\n");
            exit(1);
        }
        A[sizeA - 1] = inputA; // записываем значение в последнюю ячейку массива
    }
    // remove_duplicates(A, sizeA);
    // merge(A, sizeA);
}

void remove_duplicates(int *array, int size)
{
    int i, j, k = 0;     
    int C[100];
    for (i = 0; i < size; i++)
    { 
        for (j = i + 1; j < size; j++)
        { 
            if (array[i] == array[j])
            {
                C[k] = array[i];
                array[j] = 0;
                k++;  
            }
            else if(array[i] != 0)
            {
                C[k] = array[i];
                k++;
            }
            
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (i <= k)
        {
            array[i] = C[i];
        }
        else
        {
            array[i] = ' ';
        }
    }
}
void merge(int *a, int size)
{
    int mid = size / 2; // находим середину сортируемой последовательности
    if (size % 2 == 1)
        mid++;
    int h = 1; // шаг
    // выделяем память под формируемую последовательность
    int *c = (int *)malloc(size * sizeof(int));
    int step;
    while (h < size)
    {
        step = h;
        int i = 0;   // индекс первого пути
        int j = mid; // индекс второго пути
        int k = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid)
        {
            while ((i < step) && (j < size) && (j < (mid + step)))
            { // пока не дошли до конца пути
                // заполняем следующий элемент формируемой последовательности
                // меньшим из двух просматриваемых
                if (a[i] < a[j])
                {
                    c[k] = a[i];
                    i++;
                    k++;
                }
                else
                {
                    c[k] = a[j];
                    j++;
                    k++;
                }
            }
            while (i < step)
            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                c[k] = a[i];
                i++;
                k++;
            }
            while ((j < (mid + step)) && (j < size))
            { // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                c[k] = a[j];
                j++;
                k++;
            }
            step = step + h; // переходим к следующему этапу
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        for (i = 0; i < size; i++)
            a[i] = c[i];
    }
}
