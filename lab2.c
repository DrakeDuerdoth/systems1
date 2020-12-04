int main(){

phase_5(7, 84);


return 0;}

void phase_5(int num1, int num2)
{

        if ((num1 + num2 ) < 1)
                printf("no");

        num1 = num1 & 15;

        if (num1 == 15)
                printf("No. num = 15");

        int sum = 0;
        int count = 0;

        while (num1 != 15) {
                sum = sum + num1;
                count++;
                num1++;
        };

        if ((count != 8) || (sum != num2))
                printf("NO.");

        printf("%d, %d", count, sum);
}
