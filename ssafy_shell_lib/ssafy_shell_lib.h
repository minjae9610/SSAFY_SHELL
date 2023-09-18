#ifndef SSAFY_SHELL_LIB_H
#define SSAFY_SHELL_LIB_H

#include <stdbool.h>

int convert_alpha_case(int c);
int isupper(int c);
void date();
void dmesg();
bool print_history();
bool add_history(char *cmd);
bool clear_history();
char *get_history(int index);
void ls();
bool putstr_fd(int fd, const char *s);
void tolower_str(char *str, int len);
int tolower(int c);
void uptime();

#endif
