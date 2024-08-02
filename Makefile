final: path.a color.a strings_utils.a

all:
	@make all -C path
	@make all -C color
	@make all -C strings_utils

path.a:
	@make $(MAKE_ARGS) path

color.a:
	@make $(MAKE_ARGS) color

strings_utils.a:
	@make $(MAKE_ARGS) strings_utils