/* use ft_split for this,
 * remove 'splitter'.
 * make something for the %d
 * stand alone parser.
 */

char	ft_getpercents(char *line)
{

}

/* parsers won't do
 * will move to another file.
 * function to make it all 
 * show up. main function?
 */

void	ft_printer(char *line)
{
	char	**percents;

	percents = ft_getpercents(line);
	while (line)
	{
		if (*line != '%')
			putchr(*line);
		else
		{
			ft_printpercent(*percents);
			(*percents)++;
		}
		line++;
	}
}

/* a series of if/else that
 * takes care of knowing 
 * what percent prints what.
 */

void	ft_printpercent(char *percent)
{
	if (ft_strlen(percent) > 1)
		{}
	else
	{
		if (percent[1] == '%')
			ft_putchr('%');
		if (percent[1] == 'd')
		//maybe i should keep count
		//of how many percents I've 
		//printed? can add a counter
		//behind every percent
			ft_printint('d', percent[0]); //like that
		if (percent[1] == 'c')
			ft_printchar('c', percent[0]);
		if (percent[1] == 's')
			ft_printstring('s', percent[0]);
		if (percent[1] == 'p')
			ft_printointer('p', percent[0]);
		if (percent[1] == 'c')
			ft_printchar('c', percent[0]);
		if (percent[1] == 's')
			ft_printstring('s', percent[0]);
		if (percent[1] == 'p')
			ft_printointer('p', percent[0]);
		//etc
	}
}