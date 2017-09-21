#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define M 26

void strToLower(char* str)
{
	while(*str != '\0')
	{
		if(*str>=65 && *str <= 90)
		*str = *str+32;
		str++;
	}
}

bool isPalin(char* str)
{
  int len = strlen(str);
  int odd = 0;
  int freq[M];
  memset(freq,0,M*sizeof(int));

  for (int i = 0; i <len; i++)
    freq[str[i]-'a']++;

  for(int i = 0; i<M; i++)
    if(freq[i]%2 == 1)
      odd++;

  if((len % 2 == 1 && odd == 1)||(len % 2 == 0 && odd == 0))
    return true;
  else
    return false;
}

void printAllPalindromePermutations(char* str)
{
  if(!isPalin(str))
    return;




}
