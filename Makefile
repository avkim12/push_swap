

all:
	@make -C push_swap_dir
	@make -C checker_dir
	@mv push_swap_dir/push_swap .
	@mv checker_dir/checker .

clean:
	@make clean -C push_swap_dir
	@make clean -C checker_dir

fclean:
	@make fclean -C push_swap_dir
	@make fclean -C checker_dir
	@rm -rf push_swap
	@rm -rf checker

re: fclean all
