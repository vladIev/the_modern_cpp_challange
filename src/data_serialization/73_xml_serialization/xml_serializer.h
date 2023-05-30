#ifndef XML_SERIALIZER_H
#define XML_SERIALIZER_H

#include "movie.h"

#include "pugixml/pugixml.hpp"

using namespace pugi;

struct XmlSerializer
{
    template<typename T> static auto serialize(const T &obj) -> xml_document
    {
        xml_document xml;
        serialize(xml, obj);
        return xml;
    }

    template<typename T> static auto deserialize(const xml_node &node) -> T;

    static auto serialize(xml_node &node, const MoviesList &moviesList) -> void
    {
        auto moviesNode = node.append_child("movies");
        for (const auto &movie : moviesList) { serialize(moviesNode, movie); }
    }


    static auto serialize(xml_node &node, const Movie &movie) -> void
    {
        auto movieNode = node.append_child("movie");
        movieNode.append_attribute("id") = movie.d_id;
        movieNode.append_attribute("title") = movie.d_title.c_str();
        movieNode.append_attribute("year") = movie.d_year;
        movieNode.append_attribute("length") = movie.d_length;

        auto castNode = movieNode.append_child("cast");
        for (const auto &role : movie.d_roles) { serialize(castNode, role); }

        auto directorsNode = movieNode.append_child("directors");
        for (const auto &director : movie.d_directors) {
            auto directorNode = directorsNode.append_child("director");
            directorNode.append_attribute("name") = director.c_str();
        }

        auto writersNode = movieNode.append_child("writers");
        for (const auto &writer : movie.d_writers) {
            auto writerNode = writersNode.append_child("writer");
            writerNode.append_attribute("name") = writer.c_str();
        }
    }

    static auto serialize(xml_node &node, const Role &role) -> void
    {
        auto roleNode = node.append_child("role");
        roleNode.append_attribute("star") = role.d_actor.c_str();
        roleNode.append_attribute("name") = role.d_character.c_str();
    }
};


template<> Role XmlSerializer::deserialize<Role>(const xml_node &roleNode)
{
    return { .d_actor = roleNode.attribute("star").as_string(),
        .d_character = roleNode.attribute("name").as_string() };
}

template<> Movie XmlSerializer::deserialize<Movie>(const xml_node &movieNode)
{
    Movie movie;
    movie.d_id = movieNode.attribute("id").as_uint();
    movie.d_title = movieNode.attribute("title").as_string();
    movie.d_year = movieNode.attribute("year").as_uint();
    movie.d_length = movieNode.attribute("length").as_uint();

    const auto castNode = movieNode.child("cast");
    for (const auto role : castNode) {
        movie.d_roles.push_back(deserialize<Role>(role));
    }

    const auto directorsNode = movieNode.child("directors");
    for (const auto director : directorsNode) {
        movie.d_directors.push_back(director.attribute("name").as_string());
    }

    const auto writersNode = movieNode.child("writers");
    for (const auto writer : writersNode) {
        movie.d_writers.push_back(writer.attribute("name").as_string());
    }

    return movie;
}

template<>
auto XmlSerializer::deserialize<MoviesList>(const xml_node &node) -> MoviesList
{
    MoviesList movies;
    const auto moviesNode = node.child("movies");
    for (const auto movie : moviesNode) {
        movies.push_back(deserialize<Movie>(movie));
    }
    return movies;
}


#endif
