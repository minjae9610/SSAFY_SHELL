#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

bool print_history()
{
    FILE *fp = fopen("history", "r");
    if (fp == NULL)
        return false;
    char cmd[101];
    int i = 1;
    while (fgets(cmd, 101, fp))
    {
        printf("%d %s", i, cmd);
        i++;
    }
    fclose(fp);
    return true;
}

bool add_history(char *cmd)
{
    FILE *fp = fopen("history", "a");
    if (fp == NULL)
        return false;
    fseek(fp, 0, SEEK_END);
    fputs(cmd, fp);
    fputs("\n", fp);
    fclose(fp);
    return true;
}

bool clear_history()
{
    FILE *fp = fopen("history", "w");
    if (fp == NULL)
        return false;
    fclose(fp);
    return true;
}

char *get_history(int index)
{
    static char history[101];
    FILE *fp = fopen("history", "r");
    if (fp == NULL)
        return NULL;
    int i = 1;
    while (fgets(history, 101, fp))
    {
        if (i == index)
        {
            fclose(fp);
            history[strlen(history) - 1] = '\0';
            return history;
        }
        i++;
    }
    fclose(fp);
    return NULL;
}