
#include "ft_isdigit.h"

int ft_isdigit_launcher(void)
{
    t_unit_test *test_list;

    test_list = NULL;
    load_test(&test_list, "ft_isdigit", "char_test", &char_test);
    load_test(&test_list, "ft_isdigit", "null_test", &null_test);
    load_test(&test_list, "ft_isdigit", "digit_test", &digit_test);
    load_test(&test_list, "ft_isdigit", "special_char_test", &special_char_test);
    return (launch_tests(test_list));
}