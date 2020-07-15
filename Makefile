

## TARGET_TYPE
TARGET_EXE	= a.out
TARGET_LIB	= libft.a

## PROJECT NAME (Choose target)
NAME	= $(TARGET_LIB)

## SRCS
SRC_DIR= src

SRCS=	ft_memset.c			\
		ft_memcpy.c			\
		ft_memccpy.c		\
		ft_memmove.c		\
		ft_bzero.c			\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_strlen.c			\
		ft_isalpha.c		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_strnstr.c		\
		ft_atoi.c			\
		ft_calloc.c			\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_strdup.c			\
		ft_putnbr_fd.c		\
		ft_substr.c			\
		ft_strjoin.c		\
		ft_strstartswith.c	\
		ft_strendwith.c		\
		ft_itoa.c			\
		ft_strmapi.c		\
		ft_strtrim.c		\
		ft_split.c			\
		ft_ltoa_base.c		\
		ft_itoa_base.c		\
		ft_strinsert.c		\
		ft_utoa.c           \
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\
		ft_constrain.c		\
		ft_strnum.c			\
		ft_strcmp.c			\
		ft_sign.c			\
		ft_strldup.c		\
		ft_splitcharset.c	\
		ft_lstsort.c		\
		ft_bubblesort.c		\
		ft_freestab.c		\
		ft_atoi_base.c

## HEADERS
HEADERS = inc/
HEADER_FILES = libft.h

## BINS
BIN_DIR = bin
OBJS	= $(addprefix $(BIN_DIR)/, $(SRCS:.c=.o))

## LIBS
LIB			=
LIB_HEADER	=
LIB_DIRS	=

## GCC
CC			= gcc -c
GCC			= gcc
OUT			= --output
CFLAGS		= -Werror -Wextra -Wall

##
##			---- COLORS ----
##


#							--> Regular Colors
BLACK=		\033[0;30m
RED=		\033[0;31m
GREEN=		\033[0;32m
YELLOW=		\033[0;33m
BLUE=		\033[0;34m
PURPLE=		\033[0;35m
CYAN=		\033[0;36m
WHITE=		\033[0;37m

#							--> Bold
BBLACK=		\033[1;30m
BRED=		\033[1;31m
BGREEN=		\033[1;32m
BYELLOW=	\033[1;33m
BBLUE=		\033[1;34m
BPURPLE=	\033[1;35m
BCYAN=		\033[1;36m
BWHITE=		\033[1;37m



##
##			---- RULES ----
##



## Require NAME (42 norm)
all: desc $(NAME)
	@echo "Done"

## Prints a short description of what is compiling.
desc :
	@printf "$(BPURPLE)>>> Making target $(CYAN)"
	@if [ $(NAME) = $(TARGET_EXE) ] ; then \
		printf "exe $(BPURPLE)-> '$(NAME)'\n$(WHITE)" ; \
	else \
		printf "lib $(BPURPLE)-> '$(NAME)'\n$(WHITE)" ; \
	fi


## EXE
## Require all .a
## Require bin dir and objs
## Require headers
## -> Links the objs with libs.
$(TARGET_EXE) : $(foreach D, $(LIB_DIRS), $(LIB)/$D/$D.a) $(BIN_DIR) $(OBJS) $(HEADERS)
	@echo "$(BGREEN)Linked program $(CYAN)'$(NAME)'$(WHITE)."
	@$(GCC) $(OUT) $(NAME) $(CFLAGS) $(LIB_DIRS:%=-L$(LIB)/%) $(OBJS) $(LIB_DIRS:lib%=-l%)

## LIB
## Require all .a
## Require bin dir and objs
## Require headers
## -> Links the objs with libs.
$(TARGET_LIB) : $(foreach D, $(LIB_DIRS), $(LIB)/$D/$D.a) $(BIN_DIR) $(OBJS) $(HEADERS)
	@echo "$(BGREEN)Linked library $(CYAN)'$(NAME)'$(WHITE)."
	@ar rcs $(NAME) $(OBJS) $(foreach D, $(LIB_DIRS), $(LIB)/$D/$D.a)


## Makes the bin dir.
$(BIN_DIR) :
	@echo "$(BYELLOW)Warning : no $(BIN_DIR) found.\ncreating one..."
	@mkdir -p $(BIN_DIR)



## Require a C source
## -> Compiles a c source to a bin o file
$(BIN_DIR)/%.o : $(SRC_DIR)/%.c $(HEADER_FILES:%=$(HEADERS)%)
	@printf "$(WHITE)> Compiling : $(BGREEN)$< $(WHITE)"
	@$(CC) $(OUT) $@ $< $(CFLAGS) $(LIB_DIRS:%=-I$(LIB)/%) $(HEADERS:%=-I%)
	@printf "\r$(BWHITE)[$(BGREEN)✔️$(BWHITE)] Compiled : $(BGREEN)$<$(WHITE)\n"



## Require libft folder (if it exist ?)
## -> Makes libft.
$(LIB)/libft/libft.a : $(LIB)/libft
	@make -C $<



## -> Cleans the binarys
clean :
	@rm -rf $(BIN_DIR)
	@for lib in $(LIB_DIRS) ; do \
		make -C $(LIB)/$${lib} clean ; \
	done


## Requires clean
## -> Cleans the executable
fclean : clean
	@rm -rf $(NAME)
	@for lib in $(LIB_DIRS) ; do \
		make -C $(LIB)/$${lib} fclean ; \
	done

re : fclean all
