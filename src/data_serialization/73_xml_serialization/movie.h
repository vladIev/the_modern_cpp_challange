#ifndef MOVIE_H
#define MOVIE_H
#include <vector>
#include <string>

struct Role
{
    std::string d_actor;
    std::string d_character;
};

struct Movie
{
    uint32_t d_id;
    std::string d_title;
    uint16_t d_year;
    uint16_t d_length;
    std::vector<Role> d_roles;
    std::vector<std::string> d_directors;
    std::vector<std::string> d_writers;
};

using MoviesList = std::vector<Movie>;

#endif