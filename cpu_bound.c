//
//  hello_cpu_bound.c
//  OS_course_2021
//
//  Created by Bibhas Ghoshal on 15/08/21.
//  Copyright © 2021 Bibhas Ghoshal. All rights reserved.
//

#include <stdio.h>

int main()
{
    int x = 3;
    while (1)
    {
        x = x + 3;
    }
}