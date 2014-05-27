//
// map_test.c
//
// Copyright (c) 2014 Joao Cordeiro
// MIT licensed

#include <minunit/minunit.h>
#include "../inihmap.h"
#include <cmap/map.h>

MU_TEST(test1_check) {
    struct map_t* map = create_inimap("test1.ini");

    mu_assert(map != NULL, "failed to build map");
    mu_assert(map_size(map) == 3, "Wrong size");

    mu_assert(strcmp(map_get(map, "person/name"), "test_name") == 0, "Incorrect value for person/name");
    mu_assert(strcmp(map_get(map, "person/age"), "24") == 0, "Incorrect value for person/age");
    mu_assert(strcmp(map_get(map, "car/colour"), "black") == 0, "Incorrect value for car/colour");

    delete_inimap(&map);
}

MU_TEST_SUITE(main_suite) {
    MU_RUN_TEST(test1_check);
}

int main()
{
    MU_RUN_SUITE(main_suite);
    MU_REPORT();
}
