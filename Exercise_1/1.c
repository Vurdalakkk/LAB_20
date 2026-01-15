#define _CRT_SECURE_NO_WARNINGS

// Необходимые библиотеки
#include <stdio.h>
#include <locale.h>

// Основная функция
int main()
{
    // Русская локаль
    setlocale(LC_CTYPE, "RUS");

    FILE* in;
    char filename[] = "temp.txt";
    int number, sum = 0, count = 0;
    float average;

    printf("Чтение чисел из файла %s\n", filename);

    // Открытие файла для чтения
    if ((in = fopen(filename, "rt")) == NULL)
    {
        printf("Ошибка открытия файла %s\n", filename);
        printf("Убедитесь, что файл temp.txt создан в Задании 1 Лабы 20\n");
        printf("и находится в папке с программой\n");
        getchar();
        return 0;
    }

    // Чтение чисел до конца файла
    while (!feof(in))
    {
        if (fscanf(in, "%d", &number) == 1)
        {
            sum += number;
            count++;
            printf("Прочитано число: %d\n", number);
        }
        else
        {
            // Пропуск нечисловых данных
            fscanf(in, "%*s");
        }
    }

    fclose(in);

    // Вычисление среднего
    if (count > 0)
    {
        average = (float)sum / count;
        printf("\nСтатистика:\n");
        printf("Количество чисел: %d\n", count);
        printf("Сумма чисел: %d\n", sum);
        printf("Среднее арифметическое: %.2f\n", average);
    }
    else
    {
        printf("В файле не найдено чисел\n");
    }

    getchar();
    return 0;
}