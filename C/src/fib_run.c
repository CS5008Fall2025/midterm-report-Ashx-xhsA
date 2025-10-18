// generates data for analysis

#include "fib.c"
#include "helper.c"

void nfib (int n,int k){
    int print = 0;
    ull ops;
    double time;
    ops = 0;
    double time1 = time_function(fib_iterative, n, &ops, print);
    ull ops1 = ops;
 

    ops = 0;
    double time2 = time_function(fibdp_full, n, &ops, print);
    ull ops2 = ops;


    ops = 0;
    double time3= time_function(fibr_full, n, &ops, print);
    ull ops3 = ops;

    // if k == 0, print runtime
    // if k== 1,print operation count
    if(k==0){
        
        printf("%d,%f,%f,%f\n", n, time1, time2, time3);
    }else
    {
        printf("%d,%llu,%llu,%llu\n", n, ops1, ops2, ops3);
    }

}

int main(int argc, char* argv[]){
    if(argc >1){

        int k = atoi(argv[1]);
        for (int i=0; i<=40; i++){
            nfib(i,k);
        }
    }
}