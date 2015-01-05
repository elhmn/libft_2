/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:07:33 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/12 16:03:49 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//compile with : gcc -L . test.c -lft

#include "libft.h"
#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define FAIL { printf("Echec Ligne %d, Fonction %s \n", __LINE__ - 1, __func__); return (0); }
//#define DEBUG(ft) { write(1, ft, 5); }	//uncomment for debug
//#define BONUS_LIST						//uncomment to test bonus
//#define BONUS_IS							//idem
#define LINUX		//bug workaround...

int		test_strlen(void)
{
#ifdef DEBUG
	DEBUG("slen\n");
#endif
	char    *str[] = {"", "a", "ha", "HAHA", "42 ha! ><", "\001\002\003\004\005\200"};
	int     i;

	for (i = 0; i <= 5; i++)
		if (strlen(str[i]) != ft_strlen(str[i]))
			FAIL;
	return (1);
}

int		test_strdup(void)
{
#ifdef DEBUG
	DEBUG("sdup\n");
#endif
	char	*ret1;
	char	*ret2;

	ret1 = strdup("");
	ret2 = ft_strdup("");
	if (strcmp(ret1, ret2) != 0)
		FAIL;
	free(ret1);
	free(ret2);
	ret1 = strdup("hello");
	ret2 = ft_strdup("hello");
	if (strcmp(ret1, ret2) != 0)
		FAIL;
	free(ret1);
	free(ret2);
	return (1);
}

int		test_strcpy(void)
{
#ifdef DEBUG
	DEBUG("scpy\n");
#endif
	char	dest[50] = {0};
	char	dest2[50] = {0};

	if (strcpy(dest, "Hello foo") != ft_strcpy(dest, "Hello foo"))
		FAIL;
	strcpy(dest, "Hello foo");
	ft_strcpy(dest2, "Hello foo");
	if (strcmp(dest, dest2) != 0)
		FAIL;
	strcpy(dest, "Hello");
	ft_strcpy(dest2, "Hello");
	if (strcmp(dest, dest2) != 0)
		FAIL;
	return (1);
}

int		test_strncpy(void)
{
#ifdef DEBUG
	DEBUG("ncpy\n");
#endif
	char	dest[50] = {0};
	char	dest2[50] = {0};

	if (strncpy(dest, "Hello foo", 6) != ft_strncpy(dest, "Hello foo", 6))
		FAIL;
	strncpy(dest, "Hello foo", 6);
	ft_strncpy(dest2, "Hello foo", 6);
	if (strcmp(dest, dest2) != 0)
		FAIL;
	strncpy(dest, "Hello", 2);
	ft_strncpy(dest2, "Hello", 2);
	if (strcmp(dest, dest2) != 0)
		FAIL;
	dest[19] = 'a';
	ft_strncpy(dest, "", 40);
	if (dest[19] != '\0')
		FAIL;
	return (1);
}

int		test_strcat(void)
{
#ifdef DEBUG
	DEBUG("scat\n");
#endif
	char	dest[50] = {0};
	char	dest2[50] = {0};

	if (strcat(dest, "hello ") != ft_strcat(dest, "hello "))
		FAIL;
	memset(dest, 0, sizeof(dest));
	strcat(dest, "Hello ");
	ft_strcat(dest2, "Hello ");
	if (strcmp(dest, dest2) != 0)
		FAIL;
	strcat(dest, "Hello ");
	ft_strcat(dest2, "Hello ");
	if (strcmp(dest, dest2) != 0)
		FAIL;
	return (1);
}

int		test_strncat(void)
{
#ifdef DEBUG
	DEBUG("ncat\n");
#endif
	char	dest[50] = {0};
	char	dest2[50] = {0};

	if (strncat(dest, "hello ", 2) != ft_strncat(dest, "hello ", 2))
		FAIL;
	memset(dest, 0, sizeof(dest));
	strncat(dest, "Hello ", 4);
	ft_strncat(dest2, "Hello ", 4);
	if (strcmp(dest, dest2) != 0)
		FAIL;
	strncat(dest, "Hello ", 2);
	ft_strncat(dest2, "Hello ", 2);
	if (strcmp(dest, dest2) != 0)
		FAIL;
	return (1);
}

#ifdef LINUX
int		test_strlcat(void)
{
#ifdef DEBUG
	DEBUG("lcat\n");
#endif
	char	dest[50] = {0};
	char	dest2[50] = {0};

	if (strlcat(dest, "Hello ", 4) != ft_strlcat(dest2, "Hello ", 4))
		FAIL;
	memset(dest, 0, sizeof(dest));
	memset(dest2, 0, sizeof(dest));
	strlcat(dest, "Hello ", 4);
	ft_strlcat(dest2, "Hello ", 4);
	if (strcmp(dest, dest2) != 0)
		FAIL;
	strlcat(dest, "Hello ", 1);
	ft_strlcat(dest2, "Hello ", 1);
	if (strcmp(dest, dest2) != 0)
		FAIL;
	return (1);
}
#endif

int		test_strchr(void)
{
#ifdef DEBUG
	DEBUG("schr\n");
#endif
	char	str[] = "Hello je tesx";

	if (strchr(str, 'H') != ft_strchr(str, 'H'))
		FAIL;
	if (strchr(str, 'j') != ft_strchr(str, 'j'))
		FAIL;
	if (strchr(str, 'x') != ft_strchr(str, 'x'))
		FAIL;
	if (strchr(str, 'y') != ft_strchr(str, 'y'))
		FAIL;
	if (strchr(str, 0) != ft_strchr(str, 0))
		FAIL;
	if (strchr(str, ' ') != ft_strchr(str, ' '))
		FAIL;
	if (strchr(str, '\0') != ft_strchr(str, '\0'))
		FAIL;
	if (strchr(str, '@') != ft_strchr(str, '@'))
		FAIL;
	return (1);
}

int		test_strrchr(void)
{
#ifdef DEBUG
	DEBUG("rchr\n");
#endif
	char	str[] = "Hello je tesx";
	int     test[3], ctrl[3];

	if (strrchr(str, 'H') != ft_strrchr(str, 'H'))
		FAIL;
	if (strrchr(str, 'j') != ft_strrchr(str, 'j'))
		FAIL;
	if (strrchr(str, 'x') != ft_strrchr(str, 'x'))
		FAIL;
	if (strrchr(str, 0) != ft_strrchr(str, 0))
		FAIL;
	if (strrchr(str, ' ') != ft_strrchr(str, ' '))
		FAIL;
	if (strrchr(str, '\0') != ft_strrchr(str, '\0'))
		FAIL;
	if (strrchr(str, '@') != ft_strrchr(str, '@'))
		FAIL;
	return (1);
}

int		test_strstr(void)
{
#ifdef DEBUG
	DEBUG("sstr\n");
#endif
	char	*str = "Hello les genw";
	int     test[6], ctrl[6];
	char    str2[]="test\200string test\200string";

	if (strstr(str, "Hello") != ft_strstr(str, "Hello"))
		FAIL;
	if (strstr(str, "les") != ft_strstr(str, "les"))
		FAIL;
	if (strstr(str, "gen") != ft_strstr(str, "gen"))
		FAIL;
	if (strstr(str, "w") != ft_strstr(str, "w"))
		FAIL;
	if (strstr(str, "") != ft_strstr(str, ""))
		FAIL;
	if (strstr(str2, "test") != ft_strstr(str2, "test"))
		FAIL;
	if (strstr(str2, "string") != ft_strstr(str2, "string"))
		FAIL;
	if (strstr(str2, "\200") != ft_strstr(str2, "\200"))
		FAIL;
	if (strstr(str2, "@") != ft_strstr(str2, "@"))
		FAIL;
	if (strstr(str2, str) != ft_strstr(str2, str))
		FAIL;
	if (strstr(str2, "ingr") != ft_strstr(str2, "ingr"))
		FAIL;
	return (1);
}

#ifdef LINUX
int    test_strnstr(void)
{
#ifdef DEBUG
	DEBUG("nstr\n");
#endif
	char    *str = "Hello les genw";

	if (strnstr(str, "Hello", 3) != ft_strnstr(str, "Hello", 3))
		FAIL;
	if (strnstr(str, "les", 1) != ft_strnstr(str, "les", 1))
		FAIL;
	if (strnstr(str, "gen", 2) != ft_strnstr(str, "gen", 2))
		FAIL;
	if (strnstr(str, "w", 0) != ft_strnstr(str, "w", 0))
		FAIL;
	if (strnstr(str, "", 3) != ft_strnstr(str, "", 3))
		FAIL;
	if (strnstr("t\0est", "t\0est", 5) != ft_strnstr("t\0est", "t\0est", 5))
		FAIL;
	if (strnstr(str, "\200", 15) != ft_strnstr(str, "\200", 15))
		FAIL;
	if (strnstr(str, "@", 30) != ft_strnstr(str, "@", 30))
		FAIL;
	return (1);
}
#endif
int test_sign(int test)
{
	if (test > 0)
		return (1);
	else if (test < 0)
		return (-1);
	return (0);
}

int		test_strcmp(void)
{
#ifdef DEBUG
	DEBUG("scmp\n");
#endif
	char *a = "abc";
	char *b = "cba";
	char *c = "";
	char *d = "abcd";

	if (test_sign(strcmp(a, a)) != test_sign(ft_strcmp(a, a)))
		FAIL;
	if (test_sign(strcmp(b, a)) != test_sign(ft_strcmp(b, a)))
		FAIL;
	if (test_sign(strcmp(a, b)) != test_sign(ft_strcmp(a, b)))
		FAIL;
	if (test_sign(strcmp(c, c)) != test_sign(ft_strcmp(c, c)))
		FAIL;
	if (test_sign(strcmp(a, d)) != test_sign(ft_strcmp(a, d)))
		FAIL;
	if (test_sign(strcmp(d, a)) != test_sign(ft_strcmp(d, a)))
		FAIL;		
	if (test_sign(strcmp("test string", "test string")) != test_sign(ft_strcmp("test string", "test string")))
		FAIL;
	if (test_sign(strcmp("test string", "test spring")) != test_sign(ft_strcmp("test string", "test spring")))
		FAIL;
	if (test_sign(strcmp("test string", "test string ")) != test_sign(ft_strcmp("test string", "test string ")))
		FAIL;
	if (test_sign(strcmp("test string ", "test string")) != test_sign(ft_strcmp("test string ", "test string")))
		FAIL;
	if (test_sign(strcmp("", "test")) != test_sign(ft_strcmp("", "test")))
		FAIL;
	if (test_sign(strcmp("test", "")) != test_sign(ft_strcmp("test", "")))
		FAIL;
	if (test_sign(strcmp("", "")) != test_sign(ft_strcmp("", "")))
		FAIL;
	if (test_sign(strcmp("\200\230\100\255", "\200\230\100\255")) != test_sign(ft_strcmp("\200\230\100\255", "\200\230\100\255")))
		FAIL;
	if (test_sign(strcmp("\200\230\100\255", "\0\230\100\255")) != test_sign(ft_strcmp("\200\230\100\255", "\0\230\100\255")))
		FAIL;

	return (1);
}

int    test_strncmp(void)
{
#ifdef DEBUG
	DEBUG("ncmp\n");
#endif
	char *a = "abc";
	char *b = "cba";
	char *c = "";
	char *d = "abcd";

	if (test_sign(strncmp(a, a, 2)) != test_sign(ft_strncmp(a, a, 2)))
		FAIL;
	if (test_sign(strncmp(b, a, 2)) != test_sign(ft_strncmp(b, a, 2)))
		FAIL;
	if (test_sign(strncmp(a, b, 2)) != test_sign(ft_strncmp(a, b, 2)))
		FAIL;
	if (test_sign(strncmp(c, c, 3)) != test_sign(ft_strncmp(c, c, 3)))
		FAIL;
	if (test_sign(strncmp(a, d, 4)) != test_sign(ft_strncmp(a, d, 4)))
		FAIL;
	if (test_sign(strncmp(d, a, 4)) != test_sign(ft_strncmp(d, a, 4)))
		FAIL;
	if (test_sign(strncmp("test string", "test string", 0)) != test_sign(ft_strncmp("test string", "test string", 0)))
		FAIL;
	if (test_sign(strncmp("test string", "test spring", 30)) != test_sign(ft_strncmp("test string", "test spring", 30)))
		FAIL;
	if (test_sign(strncmp("test string", "test string ", 6)) != test_sign(ft_strncmp("test string", "test string ", 6)))
		FAIL;
	if (test_sign(strncmp("test string ", "test string", 8)) != test_sign(ft_strncmp("test string ", "test string", 8)))
		FAIL;
	if (test_sign(strncmp("", "test", 0)) != test_sign(ft_strncmp("", "test", 0)))
		FAIL;
	if (test_sign(strncmp("test", "", 0)) != test_sign(ft_strncmp("test", "", 0)))
		FAIL;
	if (test_sign(strncmp("", "", 3)) != test_sign(ft_strncmp("", "", 3)))
		FAIL;
	if (test_sign(strncmp("\200\230\100\255", "\200\230\100\255", 5)) != test_sign(ft_strncmp("\200\230\100\255", "\200\230\100\255", 5)))
		FAIL;
	if (test_sign(strncmp("\200\230\100\255", "\0\230\100\255", 5)) != test_sign(ft_strncmp("\200\230\100\255", "\0\230\100\255", 5)))
		FAIL;

	return (1);
}

int		test_atoi(void)
{
#ifdef DEBUG
	DEBUG("atoi\n");
#endif

	if (atoi("1230978") != ft_atoi("1230978"))
		FAIL;
	if (atoi("test") != ft_atoi("test"))
		FAIL;
	if (atoi("a1230978") != ft_atoi("a1230978"))
		FAIL;
	if (atoi("1230978ébpo") != ft_atoi("1230978ébpo"))
		FAIL;
	if (atoi("1230978bépo") != ft_atoi("1230978bépo"))
		FAIL;
	if (atoi("    + 001230978") != ft_atoi("    + 001230978"))
		FAIL;
	if (atoi("    - 001230978") != ft_atoi("    - 001230978"))
		FAIL;
	if (atoi("    -+0001230978") != ft_atoi("    -+0001230978"))
		FAIL;
	if (atoi("    +-0001230978") != ft_atoi("    +-0001230978"))
		FAIL;
	if (atoi("    --0001230978") != ft_atoi("    --0001230978"))
		FAIL;
	if (atoi("    ++0001230978") != ft_atoi("    ++0001230978"))
		FAIL;
	if (atoi("    -1230978") != ft_atoi("    -1230978"))
		FAIL;
	if (atoi("    +1230978") != ft_atoi("    +1230978"))
		FAIL;
	if (atoi("0009990") != ft_atoi("0009990"))
		FAIL;
	if (atoi("00000") != ft_atoi("00000"))
		FAIL;
	if (atoi("00001") != ft_atoi("00001"))
		FAIL;
	if (atoi("00100") != ft_atoi("00100"))
		FAIL;
	if (atoi("\n123") != ft_atoi("\n123"))
		FAIL;
	if (atoi("\t123") != ft_atoi("\t123"))
		FAIL;
	if (atoi("\e123") != ft_atoi("\e123"))
		FAIL;
	if (atoi("") != ft_atoi(""))
		FAIL;
	if (atoi(" 01+1") != ft_atoi(" 01+1"))
		FAIL;
	if (atoi(" 01-1") != ft_atoi(" 01-1"))
		FAIL;
	if (atoi("3.14") != ft_atoi("3.14"))
		FAIL;
	if (atoi("3,14") != ft_atoi("3,14"))
		FAIL;
	if (atoi("9999999999") != ft_atoi("9999999999"))
		FAIL;
	if (atoi("2147483647") != ft_atoi("2147483647"))
		FAIL;
	if (atoi("-2147483648") != ft_atoi("-2147483648"))
		FAIL;
	if (atoi("\v123") != ft_atoi("\v123"))
		FAIL;
	if (atoi("\f123") != ft_atoi("\f123"))
		FAIL;
	if (atoi("\r123") != ft_atoi("\r123"))
		FAIL;
	if (atoi("\n -123") != ft_atoi("\n -123"))
		FAIL;
	if (atoi("\v\t\r\f-123") != ft_atoi("\v\t\r\f-123"))
		FAIL;
	if (atoi("12-3") != ft_atoi("12-3"))
		FAIL;
	if (atoi("-+123") != ft_atoi("-+123"))
		FAIL;
	if (atoi("a123") != ft_atoi("a123"))
		FAIL;
	if (atoi("123a") != ft_atoi("123a"))
		FAIL;
	if (atoi("123") != ft_atoi("123"))
		FAIL;
	if (atoi("-123") != ft_atoi("-123"))
		FAIL;
	if (atoi("+123") != ft_atoi("+123"))
		FAIL;
	if (atoi(" 123") != ft_atoi(" 123"))
		FAIL;
	if (atoi(" - 123") != ft_atoi(" - 123"))
		FAIL;
	if (atoi("\t -123") != ft_atoi("\t-123"))
		FAIL;
	if (atoi("-2147483648") != ft_atoi("-2147483648"))
		FAIL;
	if (atoi("2147483647") != ft_atoi("2147483647"))
		FAIL;
	return (1);
}

int		test_toupper(void)
{
#ifdef DEBUG
	DEBUG("toup\n");
#endif
	int		i;

	for (i = 0; i < 255; i++)
		if (toupper(i) != ft_toupper(i))
			FAIL;
	return (1);
}

int		test_tolower(void)
{
#ifdef DEBUG
	DEBUG("tolo\n");
#endif
	int		i;

	for (i = 0; i < 255; i++)
		if (tolower(i) != ft_tolower(i))
			FAIL;
	return (1);
}

int    test_memset(void)
{
#ifdef DEBUG
	DEBUG("mset\n");
#endif
	int		itab[9];
	char	ctab[3];
	char	ctab2[3];
	int		itab2[9];

	itab[0] = 3;
	itab2[0] = 3;
	itab[8] = 3;
	itab2[8] = 3;
	ctab[0] = 3;
	ctab2[0] = 3;
	ctab[2] = 3;
	ctab2[2] = 3;
	if (ft_memset(itab, 49, sizeof(itab)) != memset(itab, 49, sizeof(itab)))
		FAIL;
	ft_memset(itab, 49, sizeof(itab));
	memset(itab2, 49, sizeof(itab));
	if (memcmp(itab, itab2, sizeof(itab)) != 0)
		FAIL;
	ft_memset(ctab, 49, sizeof(ctab));
	memset(ctab2, 49, sizeof(ctab));
	if (memcmp(ctab, ctab2, sizeof(ctab)) != 0)
		FAIL;
	return (1);
}

int    test_bzero(void)
{
#ifdef DEBUG
	DEBUG("zero\n");
#endif
	int		itab[9];
	char	ctab[3];
	char	ctab2[3];
	int		itab2[9];

	itab[0] = 3;
	itab2[0] = 3;
	itab[8] = 3;
	itab2[8] = 3;
	ctab[0] = 3;
	ctab2[0] = 3;
	ctab[2] = 3;
	ctab2[2] = 3;
	ft_bzero(itab, sizeof(itab));
	bzero(itab2, sizeof(itab));
	if (memcmp(itab, itab2, sizeof(itab)) != 0)
		FAIL;
	ft_bzero(ctab, sizeof(ctab));
	bzero(ctab2, sizeof(ctab));
	if (memcmp(ctab, ctab2, sizeof(ctab)) != 0)
		FAIL;
	return (1);
}

int    test_memcpy(void)
{
#ifdef DEBUG
	DEBUG("mcpy\n");
#endif
	int	tab[9];
	int	tab2[9];
	int	cpy[4];

	cpy[0] = 3;
	cpy[1] = 4;
	cpy[2] = 5;
	cpy[3] = 7;
	memset(tab, 0, sizeof(tab));
	memset(tab2, 0, sizeof(tab));
	if (ft_memcpy(tab, cpy, sizeof(cpy)) != memcpy(tab, cpy, sizeof(cpy)))
		FAIL;
	memset(tab, 0, sizeof(tab));
	memset(tab2, 0, sizeof(tab));
	ft_memcpy(tab2, cpy, sizeof(cpy));
	memcpy(tab, cpy, sizeof(cpy));
	if (memcmp(tab, tab2, sizeof(tab)) != 0)
		FAIL;
	ft_memcpy(tab2 + 1, cpy, sizeof(cpy));
	memcpy(tab + 1, cpy, sizeof(cpy));
	if (memcmp(tab, tab2, sizeof(tab)) != 0)
		FAIL;
	return (1);
}

int    test_memccpy(void)
{
#ifdef DEBUG
	DEBUG("ccpy\n");
#endif
	char	tab[11] = "Hello boys\0";
	char	tab2[11] = "Hello boys\0";
	char	cpy[6] = "olleh\0";

	if (ft_memccpy(tab, cpy, 'o', sizeof(cpy)) != memccpy(tab, cpy, 'o', sizeof(cpy)))
		FAIL;
	memcpy(tab, "Hello", 5);
	ft_memccpy(tab2, cpy, 'o', sizeof(cpy));
	memccpy(tab, cpy, 'o', sizeof(cpy));
	if (memcmp(tab, tab2, sizeof(tab)) != 0)
		FAIL;
	ft_memccpy(tab2 + 1, cpy, 7, sizeof(cpy));
	memccpy(tab + 1, cpy, 7, sizeof(cpy));
	if (memcmp(tab, tab2, sizeof(tab)) != 0)
		FAIL;
	return (1);
}

int    test_memmove(void)
{
#ifdef DEBUG
	DEBUG("mmov\n");
#endif
	char	str[] = "memmove can be very useful......"; 
	char	str2[] = "memmove can be very useful......"; 
	char	str3[] = "memmove can be very useful......"; 
	char	str4[] = "memmove can be very useful......"; 

	if (strcmp(memmove(str + 10, str + 5, 10), ft_memmove(str2 + 10, str2 + 5, 10)) != 0)
		FAIL;
	if (strcmp(memmove(str3 + 5, str3 + 10, 10), ft_memmove(str4 + 5, str4 + 10, 10)) != 0)
		FAIL;
	return (1);
}

int    test_memchr(void)
{
#ifdef DEBUG
	DEBUG("mchr\n");
#endif
	char	tab[11] = "Hello boys\0";
	char	tab2[11] = "Hello boys\0";
	char	cpy[6] = "olleh\0";
	int             test[4], ctrl[4];
	unsigned char   str1[]="test\200string";

	if (ft_memccpy(tab, cpy, 'o', sizeof(cpy)) != memccpy(tab, cpy, 'o', sizeof(cpy)))
		FAIL;
	memcpy(tab, "Hello", 5);
	ft_memccpy(tab2, cpy, 'o', sizeof(cpy));
	memccpy(tab, cpy, 'o', sizeof(cpy));
	if (memchr(tab, 'y', sizeof(tab)) != ft_memchr(tab, 'y', sizeof(tab)))
		FAIL;
	ft_memccpy(tab2 + 1, cpy, 7, sizeof(cpy));
	memccpy(tab + 1, cpy, 7, sizeof(cpy));
	if (memchr(tab, 'h', sizeof(tab)) != ft_memchr(tab, 'h', sizeof(tab)))
		FAIL;
	if (memchr(str1, 'a', 12) != ft_memchr(str1, 'a', 12))
		FAIL;
	if (memchr(str1, 'g', 10) != ft_memchr(str1, 'g', 10))
		FAIL;
	if (memchr(str1, 'g', 11) != ft_memchr(str1, 'g', 11))
		FAIL;
	if (memchr(str1, '\200', 12) != ft_memchr(str1, '\200', 12))
		FAIL;
	return (1);
}

int    test_memcmp(void)
{
#ifdef DEBUG
	DEBUG("mcmp\n");
#endif
	char	tab[11] = "Hello boys\0";
	char	tab2[11] = "Hello boys\0";
	char	cpy[6] = "olleh\0";

	if (ft_memccpy(tab, cpy, 'o', sizeof(cpy)) != memccpy(tab, cpy, 'o', sizeof(cpy)))
		FAIL;
	memcpy(tab, "Hello", 5);
	ft_memccpy(tab2, cpy, 'o', sizeof(cpy));
	memccpy(tab, cpy, 'o', sizeof(cpy));
	if (memcmp(tab, tab2, sizeof(tab)) != ft_memcmp(tab, tab2, sizeof(tab)))
		FAIL;
	ft_memccpy(tab2 + 1, cpy, 7, sizeof(cpy));
	memccpy(tab + 1, cpy, 7, sizeof(cpy));
	if (memcmp(tab, tab2, sizeof(tab)) != ft_memcmp(tab, tab2, sizeof(tab)))
		FAIL;
	return (1);
}

int    test_isalpha(void)
{
#ifdef DEBUG
	DEBUG("ialp\n");
#endif
	int	i;

	for (i = 0; i < 255; i++)
		if (isalpha(i) != ft_isalpha(i))
			FAIL;
	return (1);
}

int    test_isdigit(void)
{
#ifdef DEBUG
	DEBUG("idig\n");
#endif
	int i;

	for (i = 0; i < 255; i++)
		if (isdigit(i) != ft_isdigit(i))
			FAIL;
	return (1);
}

int    test_isalnum(void)
{
#ifdef DEBUG
	DEBUG("ialn\n");
#endif
	int i;

	for (i = 0; i < 255; i++)
		if (isalnum(i) != ft_isalnum(i))
			FAIL;
	return (1);
}

int    test_isascii(void)
{
#ifdef DEBUG
	DEBUG("iasc\n");
#endif
	int i;

	for (i = 0; i < 255; i++)
		if (isascii(i) != ft_isascii(i))
			FAIL;
	return (1);
}

int    test_isprint(void)
{
#ifdef DEBUG
	DEBUG("ipri\n");
#endif
	int i;

	for (i = 0; i < 255; i++)
		if (isprint(i) != ft_isprint(i))
			FAIL;
	return (1);
}



/*---------------------- 2nd PART ---------------------*/

int		test_memalloc(void)
{
#ifdef DEBUG
	DEBUG("mall\n");
#endif
	int i;
	unsigned char *tmp;

	tmp = (unsigned char*)ft_memalloc(15);
	i = -1;
	while (++i < 15)
		if (tmp[i] != 0)
			FAIL;
	return (1);
}

int		test_memdel(void)
{
#ifdef DEBUG
	DEBUG("mdel\n");
#endif
	void *tmp = malloc(50);

	ft_memdel(&tmp);
	if (tmp != NULL)
		FAIL;
	return (1);
}

int		test_strnew(void)
{
#ifdef DEBUG
	DEBUG("snew\n");
#endif
	int i;
	char *tmp;


	tmp = ft_strnew(15);
	i = -1;
	while (++i < 15)
		if (tmp[i] != '\0')
			FAIL;
	if (tmp[i] != '\0')
		FAIL;
	return (1);	
}

int		test_strdel(void)
{
#ifdef DEBUG
	DEBUG("sdel\n");
#endif
	char *tmp = malloc(50);

	ft_strdel(&tmp);
	if (tmp != NULL)
		FAIL;
	return (1);
}

int		test_strclr(void)
{
#ifdef DEBUG
	DEBUG("sclr\n");
#endif
	char *tmp = (char*)malloc(13);
	int i = -1;

	strcpy(tmp, "Motherfucker");
	ft_strclr(tmp);
	while (++i < 13)
		if (tmp[i] != '\0')
			FAIL;
	return (1);
}

int	test_strequ(void)
{
#ifdef DEBUG
	DEBUG("sequ\n");
#endif
	char str[4][15] = {"", " ", "Hello", "Motherfucker"};
	int i = -1;
	int j = -1;

	while (++i < 4)
	{
		j = -1;
		while (++j < 4) 
		{
			if (strcmp(str[i], str[j]) == 0 && ft_strequ(str[i], str[j]) != 1)
				FAIL;
			if (strcmp(str[i], str[j]) != 0 && ft_strequ(str[i], str[j]) != 0) 
				FAIL;
		}
	}
	return(1);
}


int	test_strsub(void)
{
#ifdef DEBUG
	DEBUG("ssub\n");
#endif
	char tmp[] = "Hello MotherFucker";
	char *dst;

	dst = ft_strsub(tmp, 6, 12);
	if (strcmp(tmp, "Hello MotherFucker") != 0) 
		FAIL;
	if (strcmp(dst, "MotherFucker") != 0) 
		FAIL;;
	return(1);
}
int	test_strjoin(void)
{
#ifdef DEBUG
	DEBUG("sjoi\n");
#endif
	char *tmp = "Hello ";
	char *tmp2 = "MotherFucker";
	char *dst;

	dst = ft_strjoin(tmp, tmp2);
	if (strcmp(dst, "Hello MotherFucker") != 0)
		FAIL;
	return (1);
}

int	test_strtrim(void)
{
#ifdef DEBUG
	DEBUG("stri\n");
#endif
	char *tmp = "\n\n\t\t   Hello\t\n MotherFucker \n\n  \t\t";
	char *tmp2 = "Hello MotherFucker";
	char *dst = ft_strtrim(tmp);
	char*dst2 = ft_strtrim(tmp2);

	if (strcmp(dst2, "Hello MotherFucker") != 0) 
		FAIL;
	if (strcmp(dst, "Hello\t\n MotherFucker") != 0)
		FAIL;
	return(1);
}

int test_strsplit(void)
{
#ifdef DEBUG
	DEBUG("sspl\n");
#endif
	char *tmp = "*salut**les*koupins";
	char *tmp2 = "salut**les*koupins*";
	char **tab;
	char **tab2;

	tab = ft_strsplit(tmp, '*');
	tab2 = ft_strsplit(tmp2, '*');
	if (strcmp(tab[0], "salut") != 0)
		FAIL;
	if (strcmp(tab[1], "les") != 0)
		FAIL;
	if (strcmp(tab[2], "koupins") != 0) 
		FAIL;
	if (tab[3] != 0)
		FAIL;
	if (strcmp(tab2[0], "salut") != 0) 
		FAIL;
	if (strcmp(tab2[1], "les") != 0) 
		FAIL;
	if (strcmp(tab2[2], "koupins") != 0) 
		FAIL;
	if (tab2[3] != 0) 
		FAIL;
	return(1);
}

int test_itoa(void)
{
#ifdef DEBUG
	DEBUG("itoa\n");
#endif
	int ints[4] = {0, -3, 256, -87459};
	char str[4][10] = {"0", "-3", "256", "-87459"};
	int i = -1;
	char *tmp;

	while (++i < 4)
	{ 
		tmp = ft_itoa(ints[i]);
		if (strcmp(tmp, str[i]) != 0) 
			FAIL;
	}
	return(1);
}

void uf_striteri_callback(unsigned int i, char *s)
{
	*s = *s + i;
}

void uf_striter_callback(char *s)
{
	*s = *s + 1;
}

char uf_strmap_callback(char s)
{
	return (s + 1);
}

char uf_strmapi_callback(unsigned int i, char s)
{
	return (s + i);
}

int test_striteri(void)
{
#ifdef DEBUG
	DEBUG("teri\n");
#endif
	char str[] = "Hello";

	ft_striteri(NULL, NULL);
	ft_striteri(str, NULL);
	ft_striteri(str, uf_striteri_callback);
	if (strcmp(str, "Hfnos") != 0)
		FAIL;
	return (1);
}

int test_striter(void)
{
#ifdef DEBUG
	DEBUG("ster\n");
#endif
	char str[] = "Hello";

	ft_striter(NULL, NULL);
	ft_striter(str, NULL);
	ft_striter(str, uf_striter_callback);
	if (strcmp(str, "Ifmmp") != 0)
		FAIL;
	return (1);
}

int test_strmapi(void)
{
#ifdef DEBUG
	DEBUG("mapi\n");
#endif
	char str[] = "Hello";
	char empty[] = "";
	char *ret;

	ft_strmapi(NULL, NULL);
	ft_strmapi(empty, NULL);
	ret = ft_strmapi(str, uf_strmapi_callback);
	if (strcmp(ret, "Hfnos") != 0)
	{
		free(ret);
		FAIL;
	}
	free(ret);
	return (1);
}

int test_strmap(void)
{
#ifdef DEBUG
	DEBUG("smap\n");
#endif
	char str[] = "Hello";
	char *ret;

	ft_strmap(NULL, NULL);
	ft_strmap("", NULL);
	ret = ft_strmap(str, uf_strmap_callback);
	if (strcmp(ret, "Ifmmp") != 0)
	{
		free(ret);
		FAIL;
	}
	free(ret);
	return (1);
}

int test_strnequ(void)
{
#ifdef DEBUG
	DEBUG("nequ\n");
#endif
	int ret;

	ft_strnequ(NULL, NULL, 0);
	ft_strnequ(NULL, NULL, 1);
	ft_strnequ(NULL, "", 1);
	ft_strnequ("", NULL, 1);
	ret = 0;
	if ((ret = ft_strnequ("abc", "abc", 2)) != 1)
		FAIL;
	if ((ret = ft_strnequ("cba", "abc", 2)) != 0)
		FAIL;
	if ((ret = ft_strnequ("abc", "cba", 2)) != 0)
		FAIL;
	if ((ret = ft_strnequ("abc", "abd", 2)) != 1)
		FAIL;
	if ((ret = ft_strnequ("", "", 3)) != 1)
		FAIL;
	return (1);
}


/* ----------------------- BONUS ----------------------------- */

#ifdef BONUS_IS

int    test_islower(void)
{
#ifdef DEBUG
	DEBUG("ialp\n");
#endif
	int i;

	for (i = 0; i < 255; i++)
		if (islower(i) != ft_islower(i))
			FAIL;
	return (1);
}

int    test_isupper(void)
{
#ifdef DEBUG
	DEBUG("ialp\n");
#endif
	int i;

	for (i = 0; i < 255; i++)
		if (isupper(i) != ft_isupper(i))
			FAIL;
	return (1);
}

int    test_isblank(void)
{
#ifdef DEBUG
	DEBUG("ialp\n");
#endif
	int i;

	for (i = 0; i < 255; i++)
		if (isblank(i) != ft_isblank(i))
			FAIL;
	return (1);
}

int    test_iscntrl(void)
{
#ifdef DEBUG
	DEBUG("ialp\n");
#endif
	int i;

	for (i = 0; i < 255; i++)
		if (iscntrl(i) != ft_iscntrl(i))
			FAIL;
	return (1);
}
int    test_isgraph(void)
{
#ifdef DEBUG
	DEBUG("ialp\n");
#endif
	int i;

	for (i = 0; i < 255; i++)
		if (isgraph(i) != ft_isgraph(i))
			FAIL;
	return (1);
}

int    test_ispunct(void)
{
#ifdef DEBUG
	DEBUG("ialp\n");
#endif
	int i;

	for (i = 0; i < 255; i++)
		if (ispunct(i) != ft_ispunct(i))
			FAIL;
	return (1);
}

int    test_isspace(void)
{
#ifdef DEBUG
	DEBUG("ialp\n");
#endif
	int i;

	for (i = 0; i < 255; i++)
		if (isspace(i) != ft_isspace(i))
			FAIL;
	return (1);
}

int    test_isxdigit(void)
{
#ifdef DEBUG
	DEBUG("ialp\n");
#endif
	int i;

	for (i = 0; i < 255; i++)
		if (isxdigit(i) != ft_isxdigit(i))
			FAIL;
	return (1);
}

#endif

#ifdef BONUS_LIST

int test_lstnew()
{
#ifdef DEBUG
    DEBUG("lnew\n");
#endif

	t_list *lstnew_1;
	t_list *lstnew_2;

	lstnew_1 = ft_lstnew(NULL, 147);
	lstnew_2 = ft_lstnew("This is test", 13);

	if(!(lstnew_1->content == NULL))
		FAIL;
	if(!(lstnew_1->content_size == 0))
		FAIL;
	if(!(lstnew_1->next == NULL))
		FAIL;

	if(strcmp("This is test", lstnew_2->content))
		FAIL;
	if(!(lstnew_2->content_size == 13))
		FAIL;
	if(!(lstnew_2->next == NULL))
		FAIL;

	return (1);
}

static void test_ft_del(void *data, size_t size)
{
	if (data != NULL)
		free(data);
	size = 0;
}

int test_lstdelone(void)
{
#ifdef DEBUG
	DEBUG("delo\n");
#endif

	t_list *lstdelone_1;
	t_list *lstdelone_2;

	lstdelone_1 = ft_lstnew(NULL, 147);
	lstdelone_2 = ft_lstnew("This is test", 13);

	if(!(lstdelone_1->content == NULL))
		FAIL;
	if(!(lstdelone_1->content_size == 0))
		FAIL;
	if(!(lstdelone_1->next == NULL))
		FAIL;

	if(strcmp("This is test", lstdelone_2->content))
		FAIL;
	if(lstdelone_2->content_size != 13)
		FAIL;
	if(!(lstdelone_2->next == NULL))
		FAIL;

	lstdelone_1->next = lstdelone_2;
	lstdelone_2->next = NULL;

	ft_lstdelone(&lstdelone_1->next, test_ft_del);
	if(!(lstdelone_1->next == NULL))
		FAIL;
	if(!(lstdelone_1->next->next != NULL))
		FAIL;

	return (1);
}

int test_lstdel(void)
{
#ifdef DEBUG
	DEBUG("ldel\n");
#endif
	t_list *lstdel_1;
	t_list *lstdel_2;

	lstdel_1 = ft_lstnew(NULL, 147);
	lstdel_2 = ft_lstnew("This is test", 13);

	if(!(lstdel_1->content == NULL))
		FAIL;
	if(!(lstdel_1->content_size == 0))
		FAIL;
	if(!(lstdel_1->next == NULL))
		FAIL;

	if(strcmp("This is test", lstdel_2->content))
		FAIL;
	if(!(lstdel_2->content_size == 13))
		FAIL;
	if(!(lstdel_2->next == NULL))
		FAIL;

	lstdel_1->next = lstdel_2;
	lstdel_2->next = NULL;

	if(!(lstdel_1->next == lstdel_2))
		FAIL;
	if(!(lstdel_2->next == NULL))
		FAIL;

	ft_lstdel(&lstdel_1, test_ft_del);
	if(!(lstdel_1 == NULL))
		FAIL;
	if(!(lstdel_2 == NULL))
		FAIL;

	return (1);
}

int test_lstadd(void)
{
#ifdef DEBUG
	DEBUG("ladd\n");
#endif
	t_list *lstadd_1;
	t_list *lstadd_2;
	t_list *lstadd_tst;

	lstadd_1 = ft_lstnew(NULL, 147);
	lstadd_2 = ft_lstnew("This is test", 13);

	if(!(lstadd_1->content == NULL))
		FAIL;
	if(!(lstadd_1->content_size == 0))
		FAIL;
	if(!(lstadd_1->next == NULL))
		FAIL;

	if(strcmp("This is test", lstadd_2->content))
		FAIL;
	if(!(lstadd_2->content_size == 13))
		FAIL;
	if(!(lstadd_2->next == NULL))
		FAIL;

	lstadd_1->next = lstadd_2;
	lstadd_2->next = NULL;

	if(!(lstadd_1->next == lstadd_2))
		FAIL;
	if(!(lstadd_2->next == NULL))
		FAIL;

	lstadd_tst = lstadd_1;
	ft_lstadd(&lstadd_tst, lstadd_2);
	if(strcmp("First element", lstadd_tst->content))
		FAIL;
	if(!(lstadd_tst->next == lstadd_1))
		FAIL;
	if(!(lstadd_tst->next->next == lstadd_2))
		FAIL;
	if(!(lstadd_tst->next->next->next == NULL))
		FAIL;
	if(!(lstadd_2->next == NULL))
		FAIL;

	return (1);
}

t_list *test_ft_map(t_list *elem)
{
	char *text;

	if (elem)
	{
		if (elem->content)
		{
			text = (char *)elem->content;
			while(*text)
			{
				*text = (*text) + 1;
				text++;
			}
		}
	}
	return (elem);
}

int test_lstmap(void)
{
#ifdef DEBUG
	DEBUG("lmap\n");
#endif

	t_list *lstmap_1;
	t_list *lstmap_2;
	t_list *lstmap_3;
	t_list *lstmap_test;

	lstmap_1 = ft_lstnew(NULL, 147);
	lstmap_2 = ft_lstnew("This is test", 13);
	lstmap_3 = ft_lstnew("", 1);

	if(!(lstmap_1->content == NULL))
		FAIL;
	if(!(lstmap_1->content_size == 0))
		FAIL;
	if(!(lstmap_1->next == NULL))
		FAIL;

	if(strcmp("This is test", lstmap_2->content))
		FAIL;
	if(!(lstmap_2->content_size == 13))
		FAIL;
	if(!(lstmap_2->next == NULL))
		FAIL;

	if(!(lstmap_3->content == NULL))
		FAIL;
	if(!(lstmap_3->content_size == 0))
		FAIL;
	if(!(lstmap_3->next == NULL))
		FAIL;

	lstmap_1->next = lstmap_2;
	lstmap_2->next = lstmap_3;

	if(!(lstmap_1->next == lstmap_2))
		FAIL;
	if(!(lstmap_2->next == lstmap_3))
		FAIL;

	lstmap_test = ft_lstmap(lstmap_1, test_ft_map);
	if(!(lstmap_test->next != NULL))
		FAIL;
	if(!(lstmap_test->next->next != NULL))
		FAIL;
	if(!(lstmap_test->next->next->next != NULL))
		FAIL;
	if(!(lstmap_test->next->next->next->next != NULL))
		FAIL;
	if(!(lstmap_test->next->next->next->next->next == NULL))
		FAIL;

	if(!(lstmap_test->content_size == 0))
		FAIL;

	return (1);
}

void test_ft_iter(t_list *elem)
{
	char *text;

	if (elem)
	{
		if (elem->content)
		{
			text = (char *)elem->content;
			while(*text)
			{
				*text = (*text) + 1;
				text++;
			}
		}
	}
}

int test_lstiter(void)
{
#ifdef DEBUG
	DEBUG("lite\n");
#endif

	t_list *lstiter_1;
	t_list *lstiter_2;
	t_list *lstiter_3;

	lstiter_1 = ft_lstnew(NULL, 147);
	lstiter_2 = ft_lstnew("This is test", 13);
	lstiter_3 = ft_lstnew("", 1);

	if(!(lstiter_1->content == NULL))
		FAIL;
	if(!(lstiter_1->content_size == 0))
		FAIL;
	if(!(lstiter_1->next == NULL))
		FAIL;

	if(strcmp("This is test", lstiter_2->content))
		FAIL;
	if(!(lstiter_2->content_size == 13))
		FAIL;
	if(!(lstiter_2->next == NULL))
		FAIL;

	if(!(lstiter_3->content == NULL))
		FAIL;
	if(!(lstiter_3->content_size == 0))
		FAIL;
	if(!(lstiter_3->next == NULL))
		FAIL;

	lstiter_1->next = lstiter_2;
	lstiter_2->next = lstiter_3;

	if(!(lstiter_1->next == lstiter_2))
		FAIL;
	if(!(lstiter_2->next == lstiter_3))
		FAIL;

	ft_lstiter(lstiter_1, test_ft_iter);

	if(!(lstiter_1->content == NULL))
		FAIL;
	if(!(lstiter_1->content_size == 0))
		FAIL;
	if(!(lstiter_1->next == lstiter_2))
		FAIL;

	if(strcmp("Uijt!jt!uftu", lstiter_2->content))
		FAIL;
	if(!(lstiter_2->content_size == 13))
		FAIL;
	if(!(lstiter_2->next == lstiter_3))
		FAIL;

	if(!(lstiter_3->content == NULL))
		FAIL;
	if(!(lstiter_3->content_size == 0))
		FAIL;
	if(!(lstiter_3->next == NULL))
		FAIL;

	return (1);
}

#endif

/* -------------------------------------------------------- */


int     main(void)
{
	int	score;

	score = test_strlen() + test_strdup() + test_strcpy() + test_strncpy() + test_strcat() + test_strncat() + test_strchr() + test_strrchr() + test_strstr() + test_strcmp() + test_strncmp() + test_atoi() + test_toupper() + test_tolower() + test_memset() + test_bzero() + test_memcpy() + test_memccpy() + test_memmove() + test_memchr() + test_memcmp() + test_isalpha() + test_isdigit() + test_isalnum() + test_isascii() + test_isprint() + test_memalloc() + test_memdel() + test_strnew() + test_strdel() + test_strclr() + test_strequ() + test_strsub() + test_strjoin() + test_strnequ() + test_strmap() + test_strmapi() + test_striter() + test_striteri() + test_itoa() + test_strtrim() + test_strsplit();
	score += 8; //(putchar + putnbr + putstr + putendl) * 2 -> fd

	#ifdef LINUX
	score += test_strlcat();
	score += test_strnstr();
	#endif
	#ifdef BONUS_IS
	score += test_islower();
	score += test_isupper();
	score += test_isblank();
	score += test_iscntrl();
	score += test_isgraph();
	score += test_ispunct();
	score += test_isspace();
	score += test_isxdigit();
	#endif
	#ifdef BONUS_LIST
	score += test_lstnew();
	score += test_lstdelone();
	score += test_lstdel();
	score += test_lstadd();
	score += test_lstiter();
	score += test_lstmap();
	#endif

	ft_putstr("Note: ");
	ft_putnbr(score);
	ft_putchar('!');
	ft_putendl(" :D");
	printf("Note: %d! :D\n", score);
	ft_putstr_fd("Note: ", 1);
	ft_putnbr_fd(score, 1);
	ft_putchar_fd('!', 1);
	ft_putendl_fd(" :D", 1);
	return (0);
}
