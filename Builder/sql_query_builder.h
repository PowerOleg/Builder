#pragma once
#include <string>
#include <vector>
#include <deque>


class SqlSelectQueryBuilder
{

public:
	//constexpr bool BuildQuery()
	constexpr char* BuildQuery()
	{
		char* result = new char[256] {};
		//id = 42 AND name = John; "
		strcat(result, select);

		const char* select1 = columns.back();

		/*std::to_string*/
		//strcat(select, );
		
		return result;
	}

	SqlSelectQueryBuilder AddColumn(const char* column)
	{
		columns.push_back(column);
		return SqlSelectQueryBuilder();
	}

	//SqlSelectQueryBuilder AddWhere(std::string name, std::string value)
	//{
	//	where_names.push_back(name);
	//	where_values.push_back(value);
	//}
	

private:
	std::vector<const char*> columns;
	std::vector<std::string> where_names;
	std::vector<std::string> where_values;
	const char* select  = "SELECT ";
	const char* from = "FROM students WHERE ";
};

