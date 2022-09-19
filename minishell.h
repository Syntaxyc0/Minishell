#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/include/libft.h"
# include <stdio.h>

typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
}   t_env;


typedef struct s_letters
{
    int type;
    char    value;
    struct s_letters    *next;
}   t_letters;

typedef struct s_words
{
    int type;
    char    *value;
    struct  s_words *next;
}   t_words;


typedef struct s_mini
{
    t_env   *myenv;
    t_letters   *letters;
	t_words		*words;
}   t_mini;

enum letter_type
{
    WORD = 1,
    IN = 2,
    OUT = 3,
    DOLL = 4,
    PIPE = 5,
    QUOTE = 6,
    DQUOTE = 7,
	QM = 8
};

enum word_type
{
    HEREDOC = 8,
    APPEND = 9,
    COMMAND = 10,
	DOLLQM = 11
};

#endif