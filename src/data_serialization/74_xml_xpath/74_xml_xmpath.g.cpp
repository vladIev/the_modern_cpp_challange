#include "pugixml/pugixml.hpp"

#include <vector>
#include <string>

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
    <movie id="9872" title="The Matrix" year="1999" length="196">
		<cast>
			<role star="Keanu Reeves" name="Neo" />
			<role star="Laurence Fishburne" name="Morpheus" />
            <role star="Carrie-Anne Moss" name="Trinity" />
            <role star="Hugo Weaving" name="Agent Smith" />
		</cast>
		<directors>
			<director name="Lana Wachowski" />
            <director name="Lilly Wachowski" />
		</directors>
		<writers>
			<writer name="Lana Wachowski" />
			<writer name="Lilly Wachowski" />
		</writers>
	</movie>
</movies>
)";

TEST(xml_xpath, movies_older_that_given_year) {
    pugi::xml_document doc;
    ASSERT_TRUE(doc.load_string(xml.data()));
    EXPECT_NO_THROW(
        {
            const auto list_of_old_movies = doc.select_nodes("/movies/movie[@year>1995]");
            EXPECT_EQ(list_of_old_movies.size(), 1);
            const auto selected_title = std::string_view(
                list_of_old_movies[0].node().attribute("title").as_string());
            EXPECT_EQ(selected_title, std::string_view("The Matrix"));
        }
    );
}

TEST(xml_xpath, select_roles) {
    pugi::xml_document doc;
    ASSERT_TRUE(doc.load_string(xml.data()));
    EXPECT_NO_THROW(
        {
            const auto roles = doc.select_nodes("/movies/movie/cast/role[last()]");
            EXPECT_EQ(roles.size(), 2);
            const auto role0 = std::string_view(
                roles[0].node().attribute("star").as_string());
            EXPECT_EQ(role0, std::string_view("Sally Field"));
            const auto role1 = std::string_view(
                roles[1].node().attribute("star").as_string());
            EXPECT_EQ(role1, std::string_view("Hugo Weaving"));
        }
    );
}