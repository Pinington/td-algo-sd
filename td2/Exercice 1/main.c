#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    // Test case 
    int list[] = {
        -995, -990, -985, -980, -975, -970, -965, -960, -955, -950,
        -945, -940, -935, -930, -925, -920, -915, -910, -905, -900,
        -895, -890, -885, -880, -875, -870, -865, -860, -855, -850,
        -845, -840, -835, -830, -825, -820, -815, -810, -805, -800,
        -795, -790, -785, -780, -775, -770, -765, -760, -755, -750,
        -745, -740, -735, -730, -725, -720, -715, -710, -705, -700,
        -695, -690, -685, -680, -675, -670, -665, -660, -655, -650,
        -645, -640, -635, -630, -625, -620, -615, -610, -605, -600,
        -595, -590, -585, -580, -575, -570, -565, -560, -555, -550,
         105,  110,  115,  120,  125,  130,  135,  140,  145,  150,
         155,  160,  165,  170,  175,  180,  185,  190,  195,  200,
         205,  210,  215,  220,  225,  230,  235,  240,  245,  250,
         255,  260,  265,  270,  275,  280,  285,  290,  295,  300,
         305,  310,  315,  320,  325,  330,  335,  340,  345,  350,
         355,  360,  365,  370,  375,  380,  385,  390,  395,  400,
         405,  410,  415,  420,  425,  430,  435,  440,  445,  450,
         455,  460,  465,  470,  475,  480,  485,  490,  495,  500
    };

    int size = sizeof(list) / sizeof(list[0]);
    int target = 500;

    
    clock_t begining, end;
    double time;

    if (is_sorted_nondecreasing(list, size)) {

        // Linear search
        begining = clock();
        int linear_index = linear_search(list, size, target);
        end = clock();
        time = (double) (end - begining) / CLOCKS_PER_SEC;

        printf("Linear search time: %lf seconds\n ~Result: %i\n", time, linear_index);

        // Jump search
        begining = clock();
        int jump_index = jump_search(list, size, target);
        end = clock();
        time = (double) (end - begining) / CLOCKS_PER_SEC;

        printf("Jump search time: %lf seconds\n ~Result: %i\n", time, jump_index);

        // Binary search
        begining = clock();
        int binary_index = binary_search(list, size, target);
        end = clock();
        time = (double) (end - begining) / CLOCKS_PER_SEC;

        printf("Binary search time: %lf seconds\n ~Result: %i\n", time, binary_index);

    } else {
        printf("Test list is not sorted properly\n");
    }

    return 0;
}
