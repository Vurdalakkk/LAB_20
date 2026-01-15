#define _CRT_SECURE_NO_WARNINGS

// Необходимые библиотеки
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>

// Основная функция
int main()
{
    // Русская локаль
    setlocale(LC_CTYPE, "RUS");

    FILE* in, * out;
    char input_file[100], output_file[100];
    double number, result;
    int counter = 1;

    printf("Преобразование чисел в файле\n");
    printf("Вариант 7: К каждому значению добавить его порядковый номер\n\n");

    // Ввод имени файла
    printf("Введите имя файла с числами: ");
    scanf("%s", input_file);
    getchar();

    // Создание имени выходного файла
    strcpy(output_file, input_file);
    char* dot = strrchr(output_file, '.');
    if (dot != NULL)
    {
        strcpy(dot, "_numbered.txt");
    }
    else
    {
        strcat(output_file, "_numbered.txt");
    }

    // Открытие файлов
    if ((in = fopen(input_file, "rt")) == NULL)
    {
        printf("Ошибка открытия файла %s\n", input_file);
        getchar();
        return 0;
    }

    if ((out = fopen(output_file, "wt")) == NULL)
    {
        printf("Ошибка создания файла %s\n", output_file);
        fclose(in);
        getchar();
        return 0;
    }

    printf("\nОбработка файла...\n");
    printf("Исходные числа -> Результат\n");

    // Чтение и обработка чисел
    while (fscanf(in, "%lf", &number) == 1)
    {
        result = number + counter;

        printf("%10.2lf -> %10.2lf\n", number, result);
        fprintf(out, "%.2lf\n", result);

        counter++;
    }

    fclose(in);
    fclose(out);

    printf("\nОбработка завершена!\n");
    printf("Результат сохранен в файле: %s\n", output_file);
    printf("Обработано чисел: %d\n", counter - 1);

    getchar();
    return 0;
}
