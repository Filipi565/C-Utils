final: path.a color.a strings_utils.a

all:
	@make $(MAKE_ARGS) path
	@make $(MAKE_ARGS) color
	@make $(MAKE_ARGS) strings_utils

path.a:
	@make $(MAKE_ARGS) path

color.a:
	@make $(MAKE_ARGS) color

strings_utils.a:
	@make $(MAKE_ARGS) strings_utils