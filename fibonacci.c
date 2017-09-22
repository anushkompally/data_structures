//Dynamic Programming
int fib(int n)
{
  int fn[n+1];
  int i;

  f[0]=0;
  f[1]=1;

  for(i=2;i<=n;i++)
  {
    fn[i] = fn[i-1]+fn[i-2];
  }
  return fn[n];
}
