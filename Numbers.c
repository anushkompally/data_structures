bool isPrimeNumber(long num)
{
  int flag = 0;
  long i;
    for(i=2; i<=num/2; ++i)
    {
        // condition for nonprime number
        if(num%i==0)
        {
            flag=1;
            break;
        }
    }
    return !flag;
}

long largerstPrimeFactor(long num)
{
  for (long i = num; num>=1; i--)
  {
    if(num%i == 0)
    {
      if(isPrimeNumber(i))
        return i;
    }
  }
}

//no of digits in a number
int noOfDigits(int num)
{
  // int digits = 0;
  if(num/10 == 0)
    return 1;
  else
    return 1+noOfDigits(num/10);
}

int nthDigit(int num, int i)
{
  int d = noOfDigits(num);
  if(i>d)
  	return -1;
  else
  {
  	if(i == 1)
  		return num % 10;
  	else
  	{
  		return (num / (int)pow(10,i-1))%(10);
  	}
  }
}
// Work on it
bool isArmstrong(int num)
{
  int power,sum;
  power = noOfDigits(num);

  for(int i = 1; i<=power; i++)
  {
    sum = (int)pow(nthDigit(num,i),power) + sum;
  }
  return (sum == num);
}

//Leetcode
//Hamming distance
int getSetBits(int num)
{
    int count = 0;
    while(num)
    {
        num &=(num-1);
        count++;
    }
    return count;
}

int hammingDistance(int x, int y) {
    
    int z = x^y;
    return getSetBits(z);
    
}



