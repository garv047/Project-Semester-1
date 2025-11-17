#include <stdio.h>

int main()
{
    int h, m, s;

    printf("Enter time (HH MM SS): ");
    scanf("%d %d %d", &h, &m, &s);

    printf("︽︽︽︽︽︽︽︽︽︽︽︽︽︽︽︽︽︽︽︽︽︽\n");
    printf("\t  🅳🅸🅶🅸🆃🅰🅻 🆃🅸🅼🅴 \n");
    printf("︾︾︾︾︾︾︾︾︾︾︾︾︾︾︾︾︾︾︾︾︾︾\n");

    while (1)
    {
        printf("\t%02d : %02d : %02d\n", h, m, s);

        s++;
        if (s == 60)
        {
            s = 0;
            m++;
        }
        if (m == 60)
        {
            m = 0;
            h++;
        }
        if (h == 24)
        {
            h = 0;
        }

        for (long double i = 0; i < 99999999; i++)
            ;
    }

    return 0;
}