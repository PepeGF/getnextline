char	*get_next_line(int fd)
{
	int		BUFFER_SIZE;	//solo vale para pruebas
	char		*buffer;
	char		*aux;
	static char	*rest;
	char		*first_n;
	char		*line;
//	static t_list	line;		idea posible hacerlo con listas

	BUFFER_SIZE = 5;		//solo vale para prubas

	//if (!rest)	si no hay static ¿Lo mismo que no hay nada???
	{
		//{		posiblemente esto tenga que ser una función propia
		//generar buffer con malloc u bzero
		//leer archivo y rellenar el buffer
		//} hasta aquí la posible función
	}
	//else			si hay rest
	//{
		//	almacenar en el buffer lo contenido en static
		//	hay que hacer malloc+bzero antes de hacer esto?
		//	si hay que hacer malloc+bzero, hay que ver la longitud del rest?? 
	//}
	//if (ft_strchr(buffer, 10))	si hay salto en el buffer
	//{
		//	separar hasta \n
		//	almacenar restante en static
		//	liberar cosas
		//	return 1ª parte
	//}
	//else		no hay \n 
	//{
	//					esta parte no la tengo nada clara
		//		¿¿¿join de static + buffer???
		//		o bien static = buffer
		//	nuevo buffer linea 15
		//	
	//}
}

