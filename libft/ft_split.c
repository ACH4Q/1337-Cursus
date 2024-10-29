/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:35:07 by machaq            #+#    #+#             */
/*   Updated: 2024/10/29 18:06:41 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_split(char *str, char c)
{
	
	static size_t count_word(char *str, char sep)
	{
        	int words;
		size_t i;

		i = 0;
		while (*str)
		{
			if (!(str[i] == sep) && !word)
			{
				count++;
				i = 1;
			}
			else if (str[i] == sep)
			{
				i = 0;
			}
			s++:
		}
		return (count);
	}
}
int	main(void)
{
	char *str = "ACH4Q is here my brother";
	count_word(str, " ");
}