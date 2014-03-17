/*************************************************************************
    > File Name: string.c
    > Author: 韩佩言
    > Mail: xiyouhanpeiyan@gmail.com 
    > Created Time: 2013年11月18日 星期一 15时57分34秒
    > Class: 计科1107
 ************************************************************************/


#include "string.h"

inline void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len)
{
	for (; len != 0; len--) {
		*dest++ = *src++;
	}
}

inline void memset(void *dest, uint8_t val, uint32_t len)
{
	uint8_t *dst = (uint8_t *)dest;

	for ( ; len != 0; len--) {
		*dst++ = val;
	}
}

inline void bzero(void *dest, uint32_t len)
{
	memset(dest, 0, len);
}

inline int strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && (*str1++ == *str2++))
	      ;

	if (*str1 == '\0' && *str2 == '\0') {
	      return 0;
	}

	if (*str1 == '\0') {
	      return -1;
	}
	
	return 1;
}

inline char *strcpy(char *dest, const char *src)
{
	char *tmp = dest;

	while (*src) {
	      *dest++ = *src++;
	}

	*dest = '\0';
	
	return tmp;
}

inline char *strcat(char *dest, const char *src)
{
	char *cp = dest;

	while (*cp) {
	      cp++;
	}

	while ((*cp++ = *src++))
	      ;

	return dest;
}

inline int strlen(const char *src)
{
	const char *eos = src;

        while (*eos++)
	      ;
	        
	return (eos - src - 1);
}

