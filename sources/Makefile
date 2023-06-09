# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ NAMES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

NAME		= minishell

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ COLORS ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

GREEN		=\033[0;32m
BLUE 		=\033[0;34m
ORANGE	=\033[38;5;214m
RED			=\033[0;31m
YELLOW	=\033[0;33m
WHITE		=\033[0;37m

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ SANITIZER ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

# Address sanitizing flags
ASAN := -fsanitize=address -fsanitize-recover=address
ASAN += -fno-omit-frame-pointer -fno-common
# no psoportadas por High Sierra
# ASAN += -fsanitize=pointer-subtract -fsanitize=pointer-compare
# Technicaly UBSan but works with ASan
ASAN += -fsanitize=undefined
# Technicaly LSan but works with ASan
# ASAN += -fsanitize=leak
# Thread sanitizing flags
TSAN := -fsanitize=thread
# Memory sanitizing flags
MSAN := -fsanitize=memory -fsanitize-memory-track-origins

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ COMPILATE ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

CC			:= gcc
AR 			:= ar -rcs
RM			:= rm -rf
MKDIR		:= -mkdir -p
CFLAGS	:= -Wall -Wextra -Werror -g3 $(ASAN)
# CFLAGS	:= -Wall -Wextra -Werror -g3
LEAKS		:= -fsanitize=address
RDFLAGS	:= -lreadline -lhistory
MODE		:= normal

ifeq ($(MODE),g)
	CFLAGS += -g3
endif

ifeq ($(HOME),1)
RL_DIR := /usr/local/opt/readline/
else
RL_DIR := ${HOME}/.brew/opt/readline/
endif

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ DIRECTORIES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

LIBFT_DIR := lib/libft/
INCLUDES 	:= inc/
SRC_DIR 	:= src/
OBJ_DIR 	:= obj/
UTILS_DIR	:= utils/
TOOLS_DIR	:= working_tools/
BUILTINS_DIR := built-ins/

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ LIB ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

LIBSFT := $(LIBFT_DIR)libft.a
INCS := $(addprefix -I, $(INCLUDES) $(LIBFT_DIR)inc/)

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ SOURCES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

MAIN_FILES	:=	main
UTILS_FILES	:= env_lst signal cmd_lst parser token_to_cmd access_to_cmd exec
TOOLS_FILES := printer working 
BUILTINS_FILES := echo env_print exit_btin export_btin 

SRC_MAIN_FILES	+=$(MAIN_FILES)
OBJS_MAIN := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAIN_FILES)))
DEPS_MAIN := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_MAIN_FILES)))

SRC_UTILS_FILES	+=$(addprefix $(UTILS_DIR),$(UTILS_FILES))
OBJS_UTILS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_UTILS_FILES)))
DEPS_UTILS := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_UTILS_FILES)))

SRC_TOOLS_FILES	+=$(addprefix $(TOOLS_DIR),$(TOOLS_FILES))
OBJ_TOOLS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_TOOLS_FILES)))
DEPS_TOOLS := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_TOOLS_FILES)))

SRC_BUILTINS_FILES	+=$(addprefix $(BUILTINS_DIR),$(BUILTINS_FILES))
OBJ_BUILTINS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BUILTINS_FILES)))
DEPS_BUILTINS := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_BUILTINS_FILES)))

ALL_OBJS += $(OBJS_UTILS) $(OBJS_MAIN) $(OBJ_TOOLS) $(OBJ_BUILTINS)
DEPS += $(DEPS_MAIN) $(DEPS_UTILS) $(DEPS_TOOLS) $(DEPS_BUILTINS)

# ◼◼◼◼◼◼◼◼◼◼◼◼◼ READLINE ◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼#

RL_INCDIR	:=	-I$(RL_DIR)include/readline/
RL_LIB		:=	-L$(RL_DIR)lib $(RDFLAGS)

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ RULES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

all: LIBFS $(NAME)

test:
			@echo ALL_OBJS: $(ALL_OBJS)
			@echo NAME: $(NAME)

$(NAME):	$(ALL_OBJS)
			@$(CC) $(CFLAGS) $(LIBSFT) $(RL_INCDIR) $(RL_LIB) $^ -o $@
			@echo "$(ORANGE) Compilando Ejecutable  ➟  $(RED)$@ $(WHITE)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(LIBSFT) Makefile
			@$(MKDIR) $(dir $@)
			@echo "$(ORANGE) Compilando Minishell  ➟  $(BLUE)$< $(WHITE)"
			@$(CC) -MMD -MP $(CFLAGS) $(RL_INCDIR) $(INCS) -c $< -o $@

LIBFS:
			@make -C $(LIBFT_DIR)

RLINE:
			@make -C $(RL_DIR)

clean :
			@$(RM) $(OBJ_DIR) $(NAME)
			@echo "$(RED)\n ✗ Archivos objetos y projecto borrados.‼️\n$(WHITE)";

fclean : clean
			@make fclean -s -C $(LIBFT_DIR)
			@echo "$(YELLOW) Borrado todo y recompilado...🔆$(WHITE)"

re: fclean all
			@echo "$(YELLOW) Borrado todo y recompilado...✌🏼$(WHITE)"

norm:
			@norminette $(SRCS_MAIN) $(SRCS_UTILS) $(INCLUDES) | grep -v Norme -B1 || true

-include $(DEPS)

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ Non-file targets ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

.PHONY: all clean fclean re norm LIBFS
