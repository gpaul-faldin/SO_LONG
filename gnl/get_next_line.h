/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:14:36 by gpaul             #+#    #+#             */
/*   Updated: 2021/07/07 03:36:36 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 100

int		next_nl(char *str);
char	*ft_strdup_free(char **s1, int i, int size);
char	*ft_strjoin_free(char **s1, char *s2);
int		get_next_line(int fd, char **line);

#endif
