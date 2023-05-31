#include "xml_serializer.h"
#include "movie.h"

#include "pugixml/pugixml.hpp"

#include <gtest/gtest.h>

// clang-format off
constexpr std::string_view xml= R"(<?xml version="1.0"?>
<movies>
	<movie id="9871" title="Forrest Gump" year="1994" length="202">
		<cast>
			<role star="Tom Hanks" name="Forrest Gump" />
			<role star="Sally Field" name="Mrs. Gump" />
		</cast>
		<directors>
			<director name="Robert Zemeckis" />
		</directors>
		<writers>
			<writer name="Winstom Groom" />
			<writer name="Eric Roth" />
		</writers>
	</movie>
</movies>
)";
// clang-format on

TEST(pugixml_lib, breathing)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(xml.data());
    EXPECT_TRUE(result);
}

TEST(pugixml_lib, movies_list_deserialization)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(xml.data());
    EXPECT_TRUE(result);

    auto moviesList = XmlSerializer::deserialize<MoviesList>(doc);
    EXPECT_EQ(moviesList.size(), 1);
    const auto &movie = moviesList[0];
    EXPECT_EQ(movie.d_id, 9871);
    EXPECT_EQ(movie.d_title, std::string_view("Forrest Gump"));
    EXPECT_EQ(movie.d_year, 1994);
    EXPECT_EQ(movie.d_length, 202);

    std::vector<std::string> writers = { "Winstom Groom", "Eric Roth" };
    EXPECT_EQ(movie.d_writers.size(), 2);
    EXPECT_EQ(movie.d_writers, writers);
    EXPECT_EQ(movie.d_directors.size(), 1);

    std::vector<std::string> directors = { "Robert Zemeckis" };
    EXPECT_EQ(movie.d_directors, directors);

    std::vector<Role> roles = {
        { .d_actor = "Tom Hanks", .d_character = "Forrest Gump" },
        { .d_actor = "Sally Field", .d_character = "Mrs. Gump" },
    };
    EXPECT_EQ(movie.d_roles.size(), roles.size());
    for (auto i = 0u; i < movie.d_roles.size(); i++) {
        EXPECT_EQ(movie.d_roles[i].d_actor, roles[i].d_actor);
        EXPECT_EQ(movie.d_roles[i].d_character, roles[i].d_character);
    }
}

TEST(pugixml_lib, movies_list_serialization)
{
    MoviesList moviesList{ 
        {
            .d_id = 9871,
            .d_title = "Forrest Gump",
            .d_year = 1994,
            .d_length = 202,
            .d_roles = {
                { .d_actor = "Tom Hanks", .d_character = "Forrest Gump" },
                { .d_actor = "Sally Field", .d_character = "Mrs. Gump" },
            },
            .d_directors = { "Robert Zemeckis" },
            .d_writers = { "Winstom Groom", "Eric Roth" },
        }
    };
    pugi::xml_document serialized = XmlSerializer::serialize(moviesList);
    auto deserializedMoviesList =
        XmlSerializer::deserialize<MoviesList>(serialized);

    EXPECT_EQ(moviesList.size(), deserializedMoviesList.size());
    for (auto i = 0u; i < moviesList.size(); i++) {
        const auto &movieOrig = moviesList[i];
        const auto &movieDeser = deserializedMoviesList[i];
        EXPECT_EQ(movieOrig.d_id, movieDeser.d_id);
        EXPECT_EQ(movieOrig.d_title, movieDeser.d_title);
        EXPECT_EQ(movieOrig.d_year, movieDeser.d_year);
        EXPECT_EQ(movieOrig.d_length, movieDeser.d_length);
        EXPECT_EQ(movieOrig.d_writers, movieDeser.d_writers);
        EXPECT_EQ(movieOrig.d_directors, movieDeser.d_directors);
        EXPECT_EQ(movieOrig.d_roles.size(), movieDeser.d_roles.size());
        for (auto i = 0u; i < movieOrig.d_roles.size(); i++) {
            EXPECT_EQ(
                movieOrig.d_roles[i].d_actor, movieDeser.d_roles[i].d_actor);
            EXPECT_EQ(movieOrig.d_roles[i].d_character,
                movieDeser.d_roles[i].d_character);
        }
    }
}