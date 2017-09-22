//Problem to output the integer thats repeated odd number of times
int findOdd(int arr[], int len)
{
  int res,i;
  for(i=0;i<len;i++)
  {
    res^=arr[i];
  }
  return res;
}

//Difference between logical and bitwise operand
int main()
{
   int x = 2, y = 5;
   (x & y)? printf("True ") : printf("False ");
   (x && y)? printf("True ") : printf("False ");
   return 0;
}


//To check if number is even or odd
int main()
{
   int x = 19;
   (x & 1)? printf("Odd"): printf("Even");
   return 0;
}

//use of ~operator
// Note that the output of following program is compiler dependent
int main()
{
   unsigned int x = 1;
   printf("Signed Result %d \n", ~x);
   printf("Unsigned Result %ud \n", ~x);
   return 0;
}
/* Output:
Signed Result -2
Unsigned Result 4294967294d */
