// Main function entrance
#include "fib.c"
#include "helper.c"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("at least two arguments needed!\n");
        help();
        return 1;
    }

    const int n = atoi(argv[1]);
    int type = 3;
    int print = 0;
    if (argc > 2) {
        type = atoi(argv[2]);
    }
    if(argc > 3) {
        print = true;
    }

    ull ops;
    double time;
    switch (type)
    {
    case 0:
        printf("iterative version\n");
        ops = 0;
        time = time_function(fib_iterative, n, &ops, print);
        printf("time: %f(%llu)\n", time, ops);
        break;
    case 1:
        printf("recursive version\n");
        ops = 0;
        time = time_function(fibr_full, n, &ops, print);
        printf("time: %f(%llu)\n", time, ops);
        break;
    case 2:
        printf("dynamic programming version\n");
        ops = 0;
        time = time_function(fibdp_full, n, &ops, print);
        printf("time: %f(%llu)\n", time, ops);
        break;
    case 4:
        printf("iterative version\n");
        ops = 0;
        time = time_function(fib_iterative, n, &ops, print);
        printf("%f,%llu", time, ops);

        printf("\ndynamic programming version\n");
        ops = 0;
        time = time_function(fibdp_full, n, &ops, print);
        printf("%f,%llu", time, ops);
        break;
    default:
        ops = 0;
        time = time_function(fib_iterative, n, &ops, print);
        printf("%f,%llu,", time, ops);

        ops = 0;
        time = time_function(fibdp_full, n, &ops, print);
        printf("%f,%llu,", time, ops);

        ops = 0;
        time = time_function(fibr_full, n, &ops, print);
        printf("%f,%llu", time, ops);

        break;
    }


}


