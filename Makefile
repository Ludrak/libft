# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 00:13:18 by lrobino           #+#    #+#              #
#    Updated: 2020/04/19 13:06:47 by lrobino          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

##	AUTHOR
AUTHOR			= lrobino

##	VERSION
VERSION			= 1.0

##	THE DIRECTORY OF YOUR FINAL TARGET
TARGET_DIR		= .

##	TARGET NAMES FOR BOTH EXECUTABLE AND LIBRARY COMPILATION
TARGET_LIB		= libft.a
TARGET_EXE		= test-libft.out

##	CHOOSE WHICH TARGET TO USE BY DEFAULT
TARGET			= $(TARGET_LIB)

##	SOURCES DIRECTORY OF YOUR PROJECT (USE '.' IF THEY ARE IN THE CURRENT FOLDER)
SRC_DIR			= .

##	SOURCES OF YOUR PROJECT
SRCS		=	ft_memset.c			\
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
				ft_constrain.c

##	BINARIES DIRECTORY OF YOUR PROJECT
BIN_DIR			= bin


##	PUT THE DIRECTORIES OF YOUR HEADER FILES HERE
HEADERS_DIR		= .

##	HEADERS OF YOUR PROJET /!\ USE FULL PATH FROM CURRENT FOLDER /!\ 
HEADERS			= libft.h

##	LIBS DIRECTORY OF YOUR PROJECT (USE '-' IF YOUR PROJECT DO NOT USE LIBRARY)
LIB_DIR			= -

##	LIBS THAT YOU ARE USING
LIBS			= -

################################################################################
################################################################################

OBJS			= $(addprefix $(BIN_DIR)/,$(SRCS:.c=.o))

INCLUDES		= $(addprefix -I,$(HEADERS_DIR))

ifneq	($(LIB_DIR), -)
	LIBFILES		= $(addprefix $(LIB_DIR)/,$(addsuffix .a,$(LIBS)))
endif

RM				= rm -rf
CC				= gcc -c
GCC				= gcc
AR				= ar rcs
CFLAGS			= -Wall -Wextra -Werror
OUT				= --output

C_RESET= \033[0m

BGREEN = \033[1;32m
GREEN = \033[0;32m
YELLOW	= \033[0;33m
BYELLOW = \033[1;33m
PURPLE = \033[0;35m
BPURPLE = \033[1;35m
BRED	= \033[1;31m
RED		= \033[0;31m
BLUE	= \033[0;34m
BBLUE	= \033[1;34m

m_MAKE		= $(C_RESET)[$(BBLUE) $(TARGET) $(C_RESET)] [$(PURPLE)MAKE$(C_RESET)] :
m_INFO		= $(C_RESET)[$(BBLUE) $(TARGET) $(C_RESET)] [$(PURPLE)INFO$(C_RESET)] :
m_LINK		= $(C_RESET)[$(BBLUE) $(TARGET) $(C_RESET)] [$(PURPLE)LINK$(C_RESET)] :
m_COMP		= $(C_RESET)[$(BBLUE) $(TARGET) $(C_RESET)] [$(PURPLE)COMP$(C_RESET)] :

m_WARN		= $(C_RESET)[$(BBLUE) $(TARGET) $(C_RESET)] [$(BYELLOW)WARN$(C_RESET)] :$(YELLOW)
m_REMV		= $(C_RESET)[$(BBLUE) $(TARGET) $(C_RESET)] [$(BRED)CLEAN$(C_RESET)] :$(BYELLOW)
m_ERR		= $(C_RESET)[$(BRED) $(TARGET) $(C_RESET)] [$(BRED)ERROR$(C_RESET)] :$(BYELLOW)



all : version $(TARGET)
	@echo "$(C_RESET)Done."


lib : $(TARGET_LIB)
$(TARGET_LIB) : $(LIB_DIR) $(LIBFILES) $(BIN_DIR) $(OBJS)
	@echo "$(m_LINK) Linking library : $(TARGET_LIB)"
	@$(AR) $(TARGET_LIB) $(OBJS) $(LIBFILES)
	@echo "$(m_LINK) Link success !"

exe : $(TARGET_EXE)
$(TARGET_EXE) : $(LIB_DIR) $(LIBFILES) $(BIN_DIR) $(OBJS)
	@echo "$(m_LINK) Making target $(TARGET_EXE)"
	@$(GCC) $(OUT) $(NAME) $(CFLAGS) $(OBJS) $(LIBFILES)
	@echo "$(m_LINK) Link success !"

##
##	BINS
##
$(BIN_DIR) :
	@mkdir -p $(BIN_DIR)
	@echo "$(m_WARN) $(BIN_DIR)/ Not found, created one.$(C_RESET)";



$(BIN_DIR)/%.o : %.c $(HEADERS)
	@$(CC) $< $(CFLAGS) $(OUT) $@ $(INCLUDES)
	@echo "$(m_COMP) Compiled : $<"



##
##	LIB
##
$(LIB_DIR) :
ifneq	($(LIB_DIR), -)
	@echo "$(m_ERR) Could not find $(LIB_DIR)/ directory !"
endif


$(LIB_DIR)/%/%.a : %
	@echo "$(m_MAKE) COMPILING LIB : $<$(C_RESET)"
	@$(MAKE) -C $<



##
##	CLEAN
##
cl : clean
clean :
	@$(RM) $(BIN_DIR)
	@echo "$(m_REMV) Removed .o files."





fc : fclean
fclean : clean
	@$(RM) $(TARGET_LIB)
	@$(RM) $(TARGET_LIB).dSYM
	@$(RM) $(TARGET_EXEC)
	@$(RM) $(TARGET_EXEC).dSYM
	@echo "$(m_REMV) Removed target : '$(TARGET)'"



##
##	UTILS
##
norm : version
	@echo "$(m_INFO) Norme for : '$(TARGET)'\n-->"
	@norminette



v : version
version :
	@printf "\e[1;1H\e[2J"
	@echo "$(BBLUE)#################################################################################"
	@echo "#                                                                               #"
	@echo "#           :::      ::::::::                                                   #"
	@echo "#         :+:      :+:    :+:                                                   #"
	@echo "#       +:+ +:+         +:+                                                     #"
	@echo "#     +#+  +:+       +#+                                                        #"
	@echo "#   +#+#+#+#+#+   +#+                                                           #"
	@echo "#         #+#    #+#                                                            #"
	@echo "#        ###   ######## - Lyon                                                  #"
	@echo "#                                                                               #"
	@echo "#$(C_RESET)>-----------------------------------------------------------------------------<$(BBLUE)#"
	@printf "#$(C_RESET)   Project : %-20.20s                                              $(BBLUE)#\n" $(TARGET_LIB)
	@printf "#$(C_RESET)   Version : %-15.15s                       Author : %-10.10s         $(BBLUE)#\n" $(VERSION) $(AUTHOR)
	@echo "#################################################################################$(C_RESET)\n\n"

##
##	SHORTCUTS
##
re : v fclean all

recomp : v clean $(LIB_DIR) compile

################################################################################

.PHONY	: all c compile recomp re fclean fc lclean lc clean version v cat ce bonus exe lib
