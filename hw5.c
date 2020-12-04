File Edit Options Buffers Tools C Help
/* Prob 3.63 */
long switch_prob(long x, long n)
{

  long result;
  result = x;
  switch(n)

    {
    case 60:
    case 62:
      result = x*8;
      break;

    case 63:
      result = x;
      result = result >> 3;
      break;

    case 64:
      result = x;
      result = result << 4;
      result -= x;
      x = result;


    case 65:
      result = x;
      x = x *x;

    default:

      result = x +75;

    }

  return result;

}


int main () {
   switch_prob(2, 63);
}
