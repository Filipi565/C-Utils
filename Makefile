MAKE_ARGS = -C

final: path.a color.a strings_utils.a

__set_args:
	@MAKE_ARGS -= -C
	@MAKE_ARGS += all -C

all: __set_args final

path.a:
	@make $(MAKE_ARGS) path

color.a:
	@make $(MAKE_ARGS) color

strings_utils.a:
	@make $(MAKE_ARGS) strings_utils