include ../../includes/push_swap.mk

HEADER_H = -I ../includes/

DIR_O = ../../lib
SOURCES = main.c check_swap_operations.c compare_this.c create_stack.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling unit test operations

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
