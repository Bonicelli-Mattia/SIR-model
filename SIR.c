#include <stdio.h>

#define BETA 0.48
#define GAMMA 0.2857
#define N0 1000
#define I0 1
#define R0 0
#define DAYS 100

int main(void)
{
    double d_sus, d_inf, d_rec;

    int t = 0;
    int dt = 1;

    double sus = (double)(N0 - R0 - I0) / N0;
    double inf = (double)I0 / N0;
    double rec = (double)R0 / N0;

    printf("  =====================================================\n");
    printf("                     SIRモデルの初期値\n");
    printf("      日々: %d    感受性: %.0f    感染: %.0f   隔離: %.0f\n",
            DAYS, sus * N0, inf * N0, rec * N0);
    printf("  =====================================================\n\n");

    printf("      Day     Susceptible     Infected    Removed\n");
    printf("        %d         %.3f        %.3f        %.3f\n",
            t, sus * N0, inf * N0, rec * N0);

    t = 1;

    while (t <= DAYS) {
        d_sus = (-BETA * sus * inf) * dt;
        d_inf = (BETA * sus * inf) - (GAMMA * inf) * dt;
        d_rec = (GAMMA * inf) * dt;

        sus += d_sus;
        inf += d_inf;
        rec += d_rec;

        if (t < 10) {
            printf("  ");
        }
        else if (t < 100) {
            printf(" ");
        }

        printf("      %d", t);

        printf("         %.3f", sus * N0);

        if (inf * N0 < 10) {
            printf("  ");
        }
        else if (inf * N0 < 100) {
            printf(" ");
        }
        
        printf("      %.3f", inf * N0);

        if (rec * N0 < 10) {
            printf("  ");
        }
        else if (rec * N0 < 100) {
            printf(" ");
        }
        printf("      %.3f\n", rec * N0);

        t += dt;
    }

    return 0;
}
