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

CC			= gcc
AR 			= ar -rcs
RM			= rm -rf
MKDIR		= -mkdir -p
CFLAGS	= -Wall -Wextra -Werror -g3
LEAKS		= -fsanitize=address
MLXFLAGS = -framework OpenGL -framework AppKit
LDFLAGS	+= -lreadline

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ DIRECTORIES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

LIBFT_DIR = lib/libft/
# RL_DIR		=	/usr/local/opt/readline
INCLUDES 	= inc/
SRC_DIR 	= src/
OBJ_DIR 	= obj/
UTILS_DIR	= utils/

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ SOURCES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

LIBSFT = $(LIBFT_DIR)libft.a

MAIN_FILES	=	main
UTILS_FILES	= uno

SRC_MAIN_FILES	+=$(MAIN_FILES)
SRCS_MAIN = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_MAIN_FILES)))
OBJS_MAIN = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAIN_FILES)))
DEPS_MAIN = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_MAIN_FILES)))

SRC_UTILS_FILES	+=$(addprefix $(UTILS_DIR),$(UTILS_FILES))
SRCS_UTILS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_UTILS_FILES)))
OBJS_UTILS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_UTILS_FILES)))
DEPS_UTILS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_UTILS_FILES)))

ALL_OBJS += $(OBJS_UTILS) $(OBJS_MAIN) 
DEPS += $(DEPS_MAIN) $(DEPS_UTILS) $(DEPS_UTILS_BONUS)

# ◼◼◼◼◼◼◼◼◼◼◼◼◼ READLINE ◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼#

# RL_INCDIR	=	-I$(RL_DIR)/include 
# RL_LIB		=	-L$(RL_DIR)/lib -lreadline -lhistory

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ RULES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

all: LIBFS $(NAME)

tokemo:
			@echo $(LIBFT_DIR)

$(NAME):	$(OBJS_MAIN) $(OBJS_UTILS) $(OBJS_ORDER)
#			@$(CC) $(CFLAGS) $(LIBSFT) $(RL_INCDIR) $(RL_LIB) $^ -o $@
			@$(CC) $(CFLAGS) $(LIBSFT) $(RL_LIB) $^ -o $@
			@echo "$(ORANGE) Compilando Ejecutable  ➟  $(RED)$@ $(WHITE)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c Makefile
			@$(MKDIR) $(dir $@)
			@echo "$(ORANGE) Compilando objetos  ➟  $(BLUE)$< $(WHITE)"
#			@$(CC) -MMD -MP $(CFLAGS) $(RL_INCDIR) -I $(INCLUDES) -c $< -o $@
			@$(CC) -MMD -MP $(CFLAGS) -I $(INCLUDES) -c $< -o $@

LIBFS:
			@make -C $(LIBFT_DIR)

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
