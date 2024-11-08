#include <iostream>
#include <string>
#include "sql_query_builder.h"
#include <cmath>

int main(int argc, char** argv) {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
    /*constexpr*/ char* result = query_builder.BuildQuery();
    std::cout << result;

    //static_assert(query_builder.BuildQuery(),
    //                "SELECT name, phone FROM students WHERE id=42 AND name=John;");
    return 0;
}