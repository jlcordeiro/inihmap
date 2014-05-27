//
// inihmap.c
//
// Copyright (c) 2014 Joao Cordeiro
// MIT licensed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inih/ini.h>
#include <cmap/map.h>

/**
 * \brief Receives each ini file entry at a time and
 * saves it into the map in the format "section/name" => "value".
 * \param vmap Map to be updated with the ini entry.
 * \param section Ini section.
 * \param name Ini entry name.
 * \param value Ini entry value.
 */
static int handler(void* vmap, const char* section, const char* name,
                   const char* value)
{
    size_t key_len = strlen(section) + strlen(name) + 2; // 2 = \0 + '/'
    char* key = (char*)malloc(key_len * sizeof(char));;
    sprintf(key, "%s/%s", section, name);

    size_t value_len = strlen(value);
    char* val = (char*)malloc(value_len * sizeof(char));
    strncpy(val, value, value_len);

    map_set((struct map_t*)vmap, key, (void*)val);

    free(key);

    return 1;
}

static void free_ini_value(void* value)
{
    if (value) {
        free(value);
    }
}

struct map_t* create_inimap(const char* inifile)
{
    struct map_t* inimap = new_map();
    map_set_free_func(inimap, free_ini_value);

    if (ini_parse(inifile, handler, inimap) < 0) {
        destroy_map(&inimap);
        inimap = NULL;
    }

    return inimap;
}

void delete_inimap(struct map_t** map)
{
    destroy_map(map);
}
