# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lrobino <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/02 18:15:54 by lrobino      #+#   ##    ##    #+#        #
#    Updated: 2019/12/03 02:02:38 by lrobino     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #


NAME		= libft.a

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
				ft_itoa_base.c

BONUS_SRCS	= 	ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c

OBJDIR			= required_objs
BONUS_OBJDIR	= bonus_objs
OBJS			= $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
BONUS_OBJS		= $(addprefix $(BONUS_OBJDIR)/,$(BONUS_SRCS:.c=.o))

INCLUDES		= -I.

RM				= rm -rf
CC				= gcc -c
LNK				= gcc
LIB				= ar rcus 
CFLAGS			= -Wall -Wextra -Werror
OUT				= --output

all : $(NAME)




$(NAME) : pre $(OBJS)
	@echo "\033[0m[\033[1;32mMAKE\033[0m] ->	\033[1;35mINFO		\033[0;32mSuccessfully compiled project : \033[0;35m$(NAME)\n"
	@echo "\033[0m[\033[1;32mLINK\033[0m] ->	\033[1;35mINFO		\033[0;32mStarting linker process..."
	@$(LIB) $(NAME) $(OBJS)
	@echo "\033[0m[\033[1;32mLINK\033[0m] ->	\033[1;35mSUCCESS		\033[1;32mLink Success !	-> '$(NAME)' created"




pre : $(OBJDIR)
	@echo "\033[1;37m\n> REQUIRED	- ############################################################################"
	@echo "\n ----		\033[4;37mSTATUS\033[1;0m		\033[4;37mCOMMENT\033[1;0m"




pre_bonus : $(OBJDIR) $(BONUS_OBJDIR)
	@echo "\033[1;37m\n> BONUS		- ###########################################################################"
	@echo "\n -----		\033[4;37mSTATUS\033[1;0m		\033[4;37mCOMMENT\033[1;0m"




$(OBJDIR) :
	@mkdir -p $(OBJDIR)
	@echo "\033[0m[\033[1;33mWARN\033[0m] ->	\033[1;33mWARNING		\033[0;33mFailed to locate $(OBJDIR) folder. Creating one..."




$(BONUS_OBJDIR) :
	@mkdir -p $(BONUS_OBJDIR)
	@echo "\033[0m[\033[1;33mWARN\033[0m] ->	\033[1;33mWARNING		\033[0;33mFailed to locate $(BONUS_OBJDIR) folder. Creating one..."



$(OBJDIR)/%.o : %.c libft.h
	@echo "\033[0m[\033[1;32mMAKE\033[0m] ->	\033[1;32mCOMPILED	\033[1;36m$<"
	@$(CC) $< $(CFLAGS) -o $@




$(BONUS_OBJDIR)/%.o : %.c
	@echo "\033[0m[\033[1;35mBONUS\033[0m] ->	\033[1;32mCOMPILED	\033[1;36m$<"
	@$(CC) $< $(CFLAGS) -o $@




clean :
	@$(RM) $(OBJDIR)
	@$(RM) $(BONUS_OBJDIR)
	@echo "\033[0m[\033[1;31mCLEAN\033[0m] ->	\033[1;33mREMOVED		\033[0;33mRemoved '.o' files."




fclean : clean
	@$(RM) $(NAME)
	@echo "\033[0m[\033[1;31mCLEAN\033[0m] ->	\033[1;33mREMOVED		\033[0;33mRemoved executable '$(NAME)'"




re : fclean all




bonus : pre_bonus $(BONUS_OBJS) pre $(OBJS)
	@echo "\033[0m[\033[1;32mMAKE\033[0m] ->	\033[1;35mINFO		\033[0;32mSuccessfully compiled project : \033[0;35m$(NAME)\n"
	@echo "\033[0m[\033[1;32mLINK\033[0m] ->	\033[1;35mINFO		\033[0;32mStarting linker process..."
	@$(LIB) $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "\033[0m[\033[1;32mLINK\033[0m] ->	\033[1;35mSUCCESS		\033[1;32mLink Success !	-> '$(NAME)' created"
