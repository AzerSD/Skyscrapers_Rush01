/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:07:41 by coder             #+#    #+#             */
/*   Updated: 2022/02/13 16:07:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

char	*ft_strcpy(char *dest, char *src);

int		is_space(char c);

int		is_numeric(char c);

int		ft_strlen(char *str);

void	remove_char(char *str, char garbage);

#endif
