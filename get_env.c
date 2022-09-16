#include "minishell.h"

void    init_myenv(t_mini *mini, char *key, char *value)
{
    mini->myenv = malloc(sizeof(t_env));
    mini->myenv->key = ft_strdup(key);
    mini->myenv->value = ft_strdup(value);
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
        exit(EXIT_FAILURE);
    ret->key = ft_strdup(key);
    ret->value = ft_strdup(value);
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
        free_env(mini);
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
            free_env(mini);
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

void    free_mini(t_mini *mini)
{
    if (mini->myenv)
        free_env(mini);
    if (mini->letters)
        free_letters(mini);
    free(mini);
}


int main(int argc, char **argv, char **env)
{
    t_mini *mini;
    t_letters   *tmp;

    mini = malloc(sizeof(t_mini));
    mini->myenv = NULL;
    mini->letters = NULL;
    get_env(env, mini);
    parse_letters(mini, argv[1]);
    tmp = mini->letters;
    while (tmp != NULL)
    {
        printf("char = %c\ntype = %d\n", tmp->value, tmp->type);
        printf("\n");
        tmp = tmp->next;
    }
    free_mini(mini);
}
