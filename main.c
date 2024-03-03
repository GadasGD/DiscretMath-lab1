#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void sort_duplicate(char *o_arr, int size) // сортировка повторов (дубликаты в конец массива)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (o_arr[i] == o_arr[j])
            {
                for (int k = j; k < size - 1; k++)
                {
                    o_arr[k] = o_arr[k + 1];
                }
                size--;
                j = j - 1;
            }
        }
    }
}
int new_size(char *o_arr, int size) // размер массива без повторов
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (o_arr[i] == o_arr[j])
            {
                for (int k = j; k < size - 1; k++)
                {
                    o_arr[k] = o_arr[k + 1];
                }
                size--;
                j = j - 1;
            }
        }
    }
    int new_size = size;
    return new_size;
}
char *remove_duplicate(char o_arr[], int size, char n_arr[]) // возвращает новый массив без повторов
{
    for (int i = 0; i < size; i++)
    {
        n_arr[i] = o_arr[i];
    }
    return n_arr;
}
void sort(char *arr, int size) // сортировка пузырьком
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if ((int)arr[j] > (int)arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void merge(char arrA[], int sizeA, char arrB[], int sizeB, char result[], int *sizeR) // Функция для слияния двух упорядоченных множеств
{
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB)
    {
        if (arrA[i] < arrB[j])
        {
            result[k++] = arrA[i++];
        }
        else if (arrA[i] > arrB[j])
        {
            result[k++] = arrB[j++];
        }
        else
        {
            result[k++] = arrA[i++];
            j++;
        }
    }

    while (i < sizeA)
    {
        result[k++] = arrA[i++];
    }

    while (j < sizeB)
    {
        result[k++] = arrB[j++];
    }

    *sizeR = k;
}

void A_in_B(char check_setA[], int sizeA, char check_setB[], int sizeB) // проверка наличия элементов A в множестве B
{
    if (sizeA <= sizeB)
    {
        int i = 0, j = 0;
        while (i < sizeA && j < sizeB)
        {
            if (check_setA[i] == check_setB[j])
            {
                i++;
            }
            j++;
        }
        if (i == sizeA)
        {
            printf("Множество А: %s,\n", check_setA);
            printf("Множество B: %s,\n", check_setB);
            printf("Результат проверки: A входит в B.\n");
            printf("\n");
        }
        else
        {
            printf("Множество А: %s,\n", check_setA);
            printf("Множество B: %s,\n", check_setB);
            printf("Результат проверки: A не входит в B.\n");
            printf("\n");
        }
    }
    else
    {
        printf("Множество А: %s,\n", check_setA);
        printf("Множество B: %s,\n", check_setB);
        printf("Результат проверки: A не входит в B.\n");
        printf("\n");
    }
}

void print_A_and_B(char arrA[], int sizeA, char arrB[], int sizeB) // вывод множeства А и множества B
{
    printf("\n");
    printf("A: {");
    for (int i = 0; i < sizeA; i++)
    {
        if (i == sizeA - 1)
        {
            printf("%c", arrA[i]);
            continue;
        }
        printf("%c ", arrA[i]);
    }
    printf("}");
    printf("\n");

    printf("B: {");
    for (int i = 0; i < sizeB; i++)
    {
        if (i == sizeB - 1)
        {
            printf("%c", arrB[i]);
            continue;
        }
        printf("%c ", arrB[i]);
    }
    printf("}");
    printf("\n");
}

void combining_A_and_B(char check_setA[], int sizeA, char check_setB[], int sizeB, char result[], int *sizeR) // объединение множеств А и множества B
{
    merge(check_setA, sizeA, check_setB, sizeB, result, sizeR);
    printf("Множество А: %s,\n", check_setA);
    printf("Множество B: %s,\n", check_setB);
    printf("Результат объединения A и B: ");
    for (int i = 0; i < *sizeR; i++)
    {
        printf("%c ", result[i]);
    }
    printf("\n");
    printf("\n");
}

void A_and_B_difference(char check_setA[], int sizeA, char check_setB[], int sizeB, char result[], int sizeR) // Разность множества А и множества B
{
    sizeR = 0;
    for (int i = 0; i < sizeA; i++)
    {
        int found = 0;
        for (int j = 0; j < sizeB; j++)
        {
            if (check_setA[i] == check_setB[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            result[sizeR++] = check_setA[i];
        }
    }
    printf("Множество А: %s,\n", check_setA);
    printf("Множество B: %s,\n", check_setB);
    printf("Результат разности A и B: ");
    for (int i = 0; i < sizeR; i++)
    {
        printf("%c ", result[i]);
    }
    printf("\n");
    printf("\n");
}

void intersection_A_and_B(char check_setA[], int sizeA, char check_setB[], int sizeB, char result[], int sizeR) // пересечение множеств А и множества B
{
    int i = 0, j = 0;
    sizeR = 0;
    while (i < sizeA && j < sizeB)
    {
        if (check_setA[i] == check_setB[j])
        {
            result[sizeR++] = check_setA[i];
            i++;
            j++;
        }
        else if (check_setA[i] < check_setB[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    printf("Множество А: %s,\n", check_setA);
    printf("Множество B: %s,\n", check_setB);
    printf("Результат пересечения A и B: ");
    for (int i = 0; i < sizeR; i++)
    {
        printf("%c ", result[i]);
    }
    printf("\n");
    printf("\n");
}
int main()
{
    char arrA[100];
    int sizeA = 0;
    char check_setA[100];

    char arrB[100];
    int sizeB = 0;
    char check_setB[100];

    char Results[100];
    int sizeR = 0;

    int choice;

    do
    {
        printf("------------------------------------\n");
        printf("1 - ввести отношение A\n2 - ввести отношения B\n3 - вывести отношения\n4 - Проверить A входит в B\n5 - Найти объединение A и B\n6 - Найти пересечение A и B\n7 - Найти разность A и B\n8 - выход\n");
        printf("------------------------------------\n");
        printf("Ведите ваш выбор: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%s", arrA);
            sizeA = strlen(arrA);
            for (int check = 0; check != 1;) // проверка корректности данных для множества А
            {
                check = 1;
                for (int i = 0; i < sizeA; i++)
                {
                    if ((((int)arrA[i] > 64 && (int)arrA[i] < 91)) || (((int)arrA[i] > 96 && (int)arrA[i] < 123))) // проверка корректности элементов
                    {
                        for (int j = i + 1; j < sizeA; j++)
                        {
                            if (arrA[j] == arrA[i]) // проверка наличия повторов
                            {
                                sort_duplicate(arrA, sizeA);
                                sizeA = new_size(arrA, sizeA);
                                check = 0;
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("Данные некорректны. Попробуйте ещё раз\n");
                        check = 0;
                        printf("Введите элементы множества A (буквы латинского алфавита без повторов): ");
                        scanf("%s", arrA);
                        sizeA = strlen(arrA);
                        break;
                    }
                    if (check == 0)
                    {
                        break;
                    }
                }

                if (check == 1)
                {
                    remove_duplicate(arrA, sizeA, check_setA);
                    break;
                }
            }
            break;
        case 2:
            scanf("%s", arrB);
            sizeB = strlen(arrB);
            for (int check = 0; check != 1;) // проверка корректности данных для множества А
            {
                check = 1;
                for (int i = 0; i < sizeB; i++)
                {
                    if ((((int)arrB[i] > 64 && (int)arrB[i] < 91)) || (((int)arrB[i] > 96 && (int)arrB[i] < 123))) // проверка корректности элементов
                    {
                        for (int j = i + 1; j < sizeB; j++)
                        {
                            if (arrB[j] == arrB[i]) // проверка наличия повторов
                            {
                                sort_duplicate(arrB, sizeB);
                                sizeB = new_size(arrB, sizeB);
                                check = 0;
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("Данные некорректны. Попробуйте ещё раз\n");
                        check = 0;
                        printf("Введите элементы множества A (буквы латинского алфавита без повторов): ");
                        scanf("%s", arrB);
                        sizeA = strlen(arrB);
                        break;
                    }
                    if (check == 0)
                    {
                        break;
                    }
                }

                if (check == 1)
                {
                    remove_duplicate(arrB, sizeB, check_setB);
                    break;
                }
            }
            break;
        case 3:
            print_A_and_B(arrA, sizeA, arrB, sizeB);
            break;
        case 4:
            A_in_B(check_setA, sizeA, check_setB, sizeB);
            break;
        case 5:
            combining_A_and_B(check_setA, sizeA, check_setB, sizeB, Results, &sizeR);
            break;
        case 6:
            intersection_A_and_B(check_setA, sizeA, check_setB, sizeB, Results, sizeR);
            break;
        case 7:
            A_and_B_difference(check_setA, sizeA, check_setB, sizeB, Results, sizeR);
            break;
        case 8:
            exit(0);
        default:
            printf("Неверный выбор операции. Попробуйте снова.\n");
            break;
        }
    } while (true);
    return 0;
}
