#include "../include/libunit.h"

void child_process(t_unit_test *list)
{
    int child_pid;
    int status;
    int devnull;

    child_pid = fork();
    if (child_pid == 0)
    {
        devnull = open("/dev/null", O_WRONLY);
        if (devnull < 0)
        {
            perror("Failed to open /dev/null");
            exit(EXIT_FAILURE);
        }
        dup2(devnull, STDOUT_FILENO);
        close(devnull);
        exit(list->f());
    }
    else
    {
        alarm(3);
        wait(&status);
        exit (status);
    }
}

char *signal_handler(int status)
{
    int signal_num;

    signal_num = WTERMSIG(status);
    if (signal_num == SIGSEGV)
        return (ft_strdup(YEL"SIGSEGV"));
    else if (signal_num == SIGBUS)
        return (ft_strdup(YEL"SIGBUS"));
    else if (signal_num == SIGABRT)
        return (ft_strdup(YEL"SIGABRT"));
    else if (signal_num == SIGFPE)
        return (ft_strdup(YEL"SIGFPE"));
    else if (signal_num == SIGILL)
        return (ft_strdup(YEL"SIGILL"));
    else if (signal_num == SIGPIPE)
        return (ft_strdup(YEL"SIGPIPE"));
    else if (signal_num == SIGALRM)
        return (ft_strdup(YEL"SIGALRM"));
    return (NULL);
}

t_unit_test *skip_non_verbose(t_unit_test *list)
{
    while (list && !list->verbose)
        list = list->next;
    return (list);
}

void parent_process(t_unit_test *list, int *success_count)
{
    int status;
    char *status_str;

    wait(&status);
    if (WIFSIGNALED(status))
      status_str = signal_handler(status);
    else if (!status)
    {
       status_str = ft_strdup(GRN"OK");
        (*success_count)++;
    }
    else
       status_str = ft_strdup(RED"KO");
    if(!status_str)
    {
        ft_printf("Memory allocation failed for status string.\n");
        exit(EXIT_FAILURE);
    }
    ft_printf(WHT"%s: %s\n", list->test_name, status_str); // to be checked
    free(status_str);
}

int main_launcher(t_unit_test *list)
{
    __pid_t pid;
    int total_tests;
    int success_count;

    total_tests = 0;
    success_count = 0;
    while (list)
    {
        list = skip_non_verbose(list);
        if (!list)
            break;
        pid= fork();
        if (pid == 0)
            child_process(list);
        else
            parent_process(list, &success_count);
        list = list->next;
        total_tests++;
    }
    ft_printf(WHT"Total tests: %d," GRN" Success: %d"WHT"," RED" Failures: %d\n", total_tests, success_count, total_tests - success_count);
    if (success_count == total_tests)
        return (0);
    return (-1);
}

