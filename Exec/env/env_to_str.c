/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:14:47 by tquere            #+#    #+#             */
/*   Updated: 2023/01/09 15:59:21 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static int	env_size(t_var *lst)
{
	int		index;

	if (lst == NULL)
		return (0);
	index = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}

static char	*add_var(t_var *var)
{	
	char	*str;
	int		len_name;
	int		len_value;
	int		i;

	i = 0;
	len_name = ft_strlen(var->name);
	len_value = ft_strlen(var->value);
	str = malloc(sizeof(char) * (len_name + len_value + 2));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str + i, var->name, len_name);
	i += len_name;
	ft_memcpy(str + i, "=", 1);
	i += 1;
	if (var->value)
	{
		ft_memcpy(str + i, var->value, len_value);
		i += len_value;
	}
	ft_memcpy(str + i, "\0", 1);
	return (str);
}

char	**env_to_str(t_var *var)
{
	char	**env_str;
	int		i;

	i = 0;
	if (var == NULL)
		return (NULL);
	env_str = malloc(sizeof(char *) * env_size(var) + 1);
	if (!env_str)
		return (NULL);
	env_str[i] = add_var(var);
	i++;
	while (var->next != NULL)
	{
		var = var->next;
		env_str[i] = add_var(var);
		i++;
	}
	env_str[i] = NULL;
	return (env_str);
}
