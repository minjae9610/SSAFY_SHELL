#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ssafy_shell.h"
#include "ssafy_shell_lib.h"

int main()
{
    char *cmd;
    while (1)
    {
        cmd = get_cmd();
        if (cmd[0] == '!')
        {
            cmd = get_history(atoi(cmd + 1));
            if (cmd == NULL)
            {
                putstr_fd(1, "ERROR : No such command in history.\n");
                continue;
            }
        }
        if (!add_history(cmd))
            putstr_fd(2, "ERROR : History not saved.\n");
        tolower_str(cmd, strlen(cmd));
        if (!strcmp(cmd, "exit"))
            return 0;
        exec(cmd);
    }
    return 0;
}

char *get_cmd()
{
    static char cmd[101];
    putstr_fd(1, SHELL_PROMPT);
    fgets(cmd, 101, stdin);
    cmd[strlen(cmd) - 1] = '\0';
    return cmd;
}

void exec(char *cmd)
{

    if (!strcmp(cmd, "date"))
        date();
    else if (!strcmp(cmd, "uptime"))
        uptime();
    else if (!strcmp(cmd, "ls"))
        ls();
    else if (!strcmp(cmd, "log"))
        dmesg();
    else if (!strcmp(cmd, "history"))
        print_history();
    else if (!strcmp(cmd, "hclear"))
        clear_history();
    else
        putstr_fd(1, "ERROR : Command not found.\n");
}
