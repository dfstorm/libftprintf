/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/19 16:03:09 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 14:54:23 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_printf(const char *str, ...);
void	ft_putstr(char *str);
void	ft_putnbr(int i);
void	ft_putchar(int d);

int		main(int argc, char **argv)
{
	int i;

	if (argc || argv) {}
	i = 0;
	i = ft_printf("test - %s - yeah", "12345");
	ft_putchar('\n');
	ft_putnbr(i);
	ft_putchar('\n');
	return (0);
}
