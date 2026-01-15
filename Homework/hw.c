#define _CRT_SECURE_NO_WARNINGS

// Необходимые библиотеки
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// Основная функция
int main()
{
    // Русская локаль
    setlocale(LC_CTYPE, "RUS");

    FILE* in, * out;
    char input_file[] = "winter.txt";
    char output_file[100];
    char line[1000];
    char new_line[1000];
    int i, j;

    printf("Удаление всех пробелов из текстового файла\n");
    printf("Вариант 7\n\n");

    // Проверка существования файла
    printf("Ищем файл winter.txt в текущей папке...\n");

    if ((in = fopen(input_file, "rt")) == NULL)
    {
        printf("Ошибка: файл winter.txt не найден!\n\n");
        printf("Инструкция по созданию файла:\n");
        printf("1. Создайте текстовый файл в папке с программой\n");
        printf("2. Назовите его точно 'winter.txt'\n");
        printf("3. Вставьте в него текст:\n");
        printf("Winter1, winter2.\n");
        printf("     Let's go skate.\n");
        printf("     Winter3, winter4.\n");
        printf("     Don't be late.\n");
        printf("     Winter5, winter6.\n");
        printf("     Let's go roll.\n");
        printf("     Winter_7, winter_8.\n");
        printf("     In the snow.\n");
        printf("     Winter, Winter!\n");
        printf("     Winter, Winter!\n");
        printf("4. Сохраните файл\n");
        getchar();
        return 0;
    }

    // Ввод имени выходного файла
    printf("Файл winter.txt найден\n");
    printf("Введите имя для нового файла (без пробелов): ");
    scanf("%s", output_file);
    getchar();

    // Открытие выходного файла
    if ((out = fopen(output_file, "wt")) == NULL)
    {
        printf("Ошибка создания файла %s\n", output_file);
        fclose(in);
        getchar();
        return 0;
    }

    printf("\nОбработка файла...\n");
    printf("Исходный текст -> Текст без пробелов\n");
    printf("--------------------------------------\n");

    // Чтение файла построчно и удаление пробелов
    while (fgets(line, sizeof(line), in) != NULL)
    {
        // Удаление пробелов из строки
        j = 0;
        for (i = 0; line[i] != '\0'; i++)
        {
            if (!isspace((unsigned char)line[i]))
            {
                new_line[j] = line[i];
                j++;
            }
        }
        new_line[j] = '\0';

        // Вывод на экран
        printf("%s -> %s\n", line, new_line);

        // Запись в файл
        fprintf(out, "%s\n", new_line);
    }

    fclose(in);
    fclose(out);

    printf("\n--------------------------------------\n");
    printf("Обработка завершена!\n");
    printf("Текст без пробелов сохранен в файле: %s\n", output_file);

    getchar();
    return 0;
}