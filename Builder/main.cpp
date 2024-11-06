#include <iostream>
#include <string>
#include "sql_query_builder.h"
#include <cmath>

int main(int argc, char** argv) {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    //query_builder.AddWhere("id", "42");

    //query_builder.AddFrom("students");
    //query_builder.AddWhere("id", "42").AddWhere("name", "John");
    
    //constexpr bool result = query_builder.BuildQuery();

    //static_assert(result,
    //                "SELECT name, phone FROM students WHERE id=42 AND name=John;");




    return 0;
}