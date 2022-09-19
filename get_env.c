#include "minishell.h"

void    init_myenv(t_mini *mini, char *key, char *value)
{
    mini->myenv = malloc(sizeof(t_env));
    mini->myenv->key = ft_strdup(key); // TODO gérer erreurs
    mini->myenv->value = ft_strdup(value); // TODO gérer erreurs
    mini->myenv->next = NULL;
}

void    free_env(t_mini *mini)
{
    t_env *tmp;
    t_env   *tofree;

    tmp = mini->myenv;
    while (tmp != NULL)
    {
        free(tmp->key);
        free(tmp->value);
        tofree = tmp;
        tmp = tmp->next;
        free(tofree);
    }
}

void    add_envelem(t_mini *mini, char *key, char *value)
{
    t_env   *ret;
    t_env   *tmp;

    if (mini->myenv == NULL)
    {
        init_myenv(mini, key, value);
        return ;
    }
    tmp = mini->myenv;
    ret = malloc(sizeof(t_env));
    if (!ret)
        exit(EXIT_FAILURE); // TODO gérer erreurs
    ret->key = ft_strdup(key);
    ret->value = ft_strdup(value);// TODO gérer erreurs
    ret->next = NULL;
    while (mini->myenv->next != NULL)
        mini->myenv = mini->myenv->next;
    mini->myenv->next = ret;
    mini->myenv = tmp;
}

t_env   *get_env(char **env, t_mini *mini)
{
    char    *key;
    char    *value;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (!env ||!*env)
        return (NULL);
    while (env[i])
    {
        while(env[i][j] != 0 && env[i][j] != '=')
            j++;
        key = ft_substr(env[i], 0, j);
        if (env[i][j] != '\0')
            value = ft_substr(env[i], j + 1, ft_strlen(env[i]));
        else
            value = NULL;
        add_envelem(mini, key, value);
        free(key);
        free(value);
        j = 0;
        i++;
    }
}

char    *get_env_value(t_mini *mini, char *key)
{
    t_env *tmp;

    tmp = mini->myenv;
    while (tmp != NULL)
    {
        if (ft_strncmp(tmp->key, key, ft_strlen(key)) == 0)
            return (tmp->value);
        tmp = tmp->next;
    }
    return (NULL);
}

void    init_letters(t_mini *mini, char c, int type)
{
    t_letters *ret;

    ret = malloc(sizeof(t_letters));
    if (!ret)
    {
        free_env(mini); // TODO gérer erreurs
        free(mini);
        exit(1);
    }
    ret->type = type;
    ret->value = c;
    ret->next = NULL;
    mini->letters = ret;
}

// types à traiter: < > $ | ' "

int get_type(char c)
{
    if (c == '<')
        return (IN);
    else if (c == '>')
        return (OUT);
    else if (c == '$')
        return (DOLL);
    else if (c == '|')
        return (PIPE);
    else if (c == '\'')
        return (QUOTE);
    else if (c == '\"')
        return (DQUOTE);
    else
        return (WORD);
}

void    add_letter(t_mini *mini, char c)
{
    t_letters   *new;
    t_letters   *tmp;

    tmp = mini->letters;
    if (mini->letters == NULL)
    {
        init_letters(mini, c, get_type(c));
        return ;
    }
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
        new = malloc(sizeof(t_letters));
        if (!new)
        {
            free_env(mini); // TODO gérer erreurs
            free(mini);
            exit(1);
        }
        new->type = get_type(c);
        new->value = c;
        new->next = NULL;
        tmp->next = new;
    }
}

int parse_letters(t_mini *mini, char *line)
{
    int i;

    i = 0;
    if (!line)
        return (0);
    while (line[i])
    {
        add_letter(mini, line[i]);
        i++;
    }
}

void    free_letters(t_mini *mini)
{
    t_letters   *tmp;
    t_letters   *save;

    tmp = mini->letters;
    while (tmp != NULL)
    {
        save = tmp;
        tmp = tmp->next;
        free(save);
    }
}


void	free_words(t_mini *mini)
{
	t_words	*tmp;
	t_words	*tofree;
	
	tmp = mini->words;
	while (tmp != NULL)
	{
		tofree = tmp;
		tmp = tmp->next;
		free(tofree->value);
		free(tofree);
	}
}

void    free_mini(t_mini *mini)
{
    if (mini->myenv)
        free_env(mini);
    if (mini->letters)
        free_letters(mini);
	if (mini->words)
		free_words(mini);
    free(mini);
}

void	init_words(t_mini *mini, char *word, int type)
{
	t_words	*ret;

	ret = malloc(sizeof(t_words)); // TODO gérer erreurs
	if (!ret)
	{
		free_mini(mini);
		exit(1);
	}
	ret->value = word;
	ret->type = type;
	ret->next = NULL;
	mini->words = ret;
}

void	add_words_elem(t_mini *mini, t_words *word)
{
	t_words	*tmp;
	t_words	*new;

	tmp = mini->words;
	if (tmp == NULL)
	{
		mini->words = word;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = word;
}

size_t	get_word_len(t_letters	*letters)
{
	size_t			len;
	t_letters	*tmp;

	len = 0;
	tmp = letters;
	while (tmp != NULL && tmp->type == WORD)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	get_word(t_mini *mini, t_letters *letters)
{
	 t_words	*word;
	 int	i;
	
	 i = 0;
	 word = malloc(sizeof(t_words));
	 if (!word)
	 {
		free_mini(mini);
		exit(1);
	 }
	 word->type = WORD;
	 word->value = malloc(get_word_len(letters) + 1);
	 word->next = NULL;
	 if (!word->value)
	 {
		free_mini(mini);
		exit(1);
	 }
	 while (letters != NULL && letters->type == WORD)
	 {
		word->value[i++] = letters->value;
		letters = letters->next;
	 }
	 word->value[i] = '\0';
	 add_words_elem(mini, word);
}

void	get_redir_in(t_mini *mini, t_letters *letters)
{
	t_words	*ret;

	ret = malloc(sizeof(t_words));
	if (!ret)
	{
		free_mini(mini);
		exit(1);
	}
	if (letters->next != NULL && letters->next->type == IN)
	{
			ret->value = ft_strdup("<<");
			ret->type = HEREDOC;
	}
	else
	{
		ret->value = ft_strdup("<");
		ret->type = IN;
	}
	if (!ret->value)
	{
		free_mini(mini);
		exit(1);
	}
	add_words_elem(mini, ret);
}

void	get_redir_out(t_mini *mini, t_letters *letters)
{
	t_words	*ret;

	ret = malloc(sizeof(t_words));
	if (!ret)
	{
		free_mini(mini);
		exit(1);
	}
	if (letters->next != NULL && letters->next->type == OUT)
	{
			ret->value = ft_strdup(">>");
			ret->type = APPEND;
	}
	else
	{
		ret->value = ft_strdup(">");
		ret->type = OUT;
	}
	if (!ret->value)
	{
		free_mini(mini);
		exit(1);
	}
	add_words_elem(mini, ret);
}

void	get_doll(t_mini *mini, t_letters *letters)
{
	t_words	*ret;

	ret = malloc(sizeof(t_words));
	if (!ret)
	{
		free_mini(mini);
		exit(1);
	}
	if (letters->next != NULL && letters->next->type == QM)
	{
		ret->value = ft_strdup("$?");
		ret->type = DOLLQM;
	}
	else
	{
		ret->value = ft_strdup("$");
		ret->type = DOLL;
	}
	if (!ret->value)
	{
		free_mini(mini);
		exit(1);
	}
	add_words_elem(mini, ret);
}

int	check_closed_quote(t_letters *letters, int type)
{
	t_letters *tmp;

	tmp = letters;
	if (type == QUOTE)
	{
		while (tmp->next != NULL)
		{
			if (tmp->next->type == QUOTE)
				return (1);
			tmp = tmp->next;
		}
	}
	else if (type == DQUOTE)
	{
		while (tmp->next != NULL)
		{
			if (tmp->next->type == DQUOTE)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

void	get_quotes(t_mini *mini, t_letters *letters)
{
	t_words *ret;
	if (letters->type == QUOTE)
	{
		while()
	}
}

int main(int argc, char **argv, char **env)
{
    t_mini *mini;
    t_letters   *tmp;
	t_words		*tmp_word;

    mini = malloc(sizeof(t_mini));
    mini->myenv = NULL;
    mini->letters = NULL;
	mini->words = NULL;
    get_env(env, mini);
    parse_letters(mini, argv[1]);
    tmp = mini->letters;
	get_word(mini, tmp);
    while (tmp != NULL)
    {
        printf("char = %c\ntype = %d\n", tmp->value, tmp->type);
        printf("\n");
		tmp = tmp->next;
    }
	printf("%s\n", mini->words->value);
    free_mini(mini);
}
