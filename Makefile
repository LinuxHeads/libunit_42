CC     = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR   =	libft
LIBUNIT_DIR =	framework
TESTS_DIR = 	tests
REALTESTS_DIR =	real_tests


all: libft libunit lib_test real_test

libft:
	@$(MAKE) -C $(LIBFT_DIR)

libunit:
	@$(MAKE) -C $(LIBUNIT_DIR)

lib_test:
	@$(MAKE) -C $(TESTS_DIR)
	
real_test:
	@$(MAKE) -C $(REALTESTS_DIR) 

run_real_test:
	@$(MAKE) test -C $(REALTESTS_DIR) SKIP="$(SKIP)"

run_lib_test:
	@$(MAKE) test -C $(TESTS_DIR) SKIP="$(SKIP)"

test:real_test lib_test run_lib_test run_real_test

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(LIBUNIT_DIR)
	@$(MAKE) clean -C $(TESTS_DIR)
	@$(MAKE) clean -C $(REALTESTS_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(LIBUNIT_DIR)
	@$(MAKE) fclean -C $(TESTS_DIR)
	@$(MAKE) fclean -C $(REALTESTS_DIR)

bonus: libft libunit_bonus lib_test_bonus real_test_bonus

libunit_bonus:
	@$(MAKE) bonus -C $(LIBUNIT_DIR)

lib_test_bonus:
	@$(MAKE) bonus -C $(TESTS_DIR)
	
real_test_bonus:
	@$(MAKE) bonus -C $(REALTESTS_DIR) 

run_real_test_bonus:
	@$(MAKE) bonus_test -C $(REALTESTS_DIR) SKIP="$(SKIP)"

run_lib_test_bonus:
	@$(MAKE) bonus_test -C $(TESTS_DIR) SKIP="$(SKIP)"

bonus_test:real_test_bonus lib_test_bonus run_lib_test_bonus run_real_test_bonus

clean_bonus:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean_bonus -C $(LIBUNIT_DIR)
	@$(MAKE) clean_bonus -C $(TESTS_DIR)
	@$(MAKE) clean_bonus -C $(REALTESTS_DIR)

fclean_bonus: clean_bonus
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean_bonus -C $(LIBUNIT_DIR)
	@$(MAKE) fclean_bonus -C $(TESTS_DIR)
	@$(MAKE) fclean_bonus -C $(REALTESTS_DIR)


re_bonus: fclean_bonus bonus

.PHONY: all clean fclean re libft libunit test real_test run_real_test run_lib_test lib_test libunit_bonus lib_test_bonus real_test_bonus run_real_test_bonus run_lib_test_bonus clean_bonus bonus_test fclean_bonus re_bonus
