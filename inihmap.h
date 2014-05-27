//
// inihmap.h
//
// Copyright (c) 2014 Joao Cordeiro
// MIT licensed

/**
 * \brief Create a map with all the entries in the ini file.
 * Each entry is saved as "section/name" => "value"
 * \param inifile Path to the ini file to be parsed.
 * \return Newly created map.
 */
struct map_t* create_inimap(const char* inifile);

/**
 * \brief Delete all resources allocated by the map.
 * \param map Map to be deleted.
 */
void delete_inimap(struct map_t** map);
