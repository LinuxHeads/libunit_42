#include "../include/libunit.h"

void main_launcher(t_unit_test *list)
{
    __pid_t pid;
    int status;
    int signal_num;

    while (list)
    {
        pid = fork();
        if (pid == 0)
            // alarm(3);
            exit(list->f());
        else 
        {
            // signal()
            // alarm(3);
            wait(&status);
            if (WIFSIGNALED(status))
            {
                signal_num = WTERMSIG(status);
                if (signal_num == SIGSEGV)
                    ft_printf("SIGSEGV\n");
                else if (signal_num == SIGBUS)
                    ft_printf("SIGBUS\n");
            }
            else if (!status)
                ft_printf("OK");
            else
                ft_printf("KO");
        }
        list = list->next;
    }
}
