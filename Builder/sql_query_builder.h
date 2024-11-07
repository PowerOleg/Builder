#pragma once
#include <string>
#include <vector>
#include <deque>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

class SqlSelectQueryBuilder
{

public:

	SqlSelectQueryBuilder()//нужно сделать поле через которое будет передаваться AddColumn значение из одного объекта в другой



	/*constexpr*/ char* BuildQuery()
	{
		char* result = new char[256] {};
		//id = 42 AND name = John; "

		strcpy(result, select);
		
		if (columns.size() > 0)
		{
			for (size_t i = 0; i < columns.size(); i++)
			{
				const char* column_var = columns.front().c_str();
				strcat(result, column_var);
				strcat(result, ",");
			}
			char* ptr = strrchr(result, ',');
			*ptr = 0;
			//проверка на длинну
		}
		else
		{
			const char* column_var = "* ";
			strcat(result, column_var);
		}

		strcat(result, from);


		for (size_t i = 0; i < where_names.size(); i++)
		{
			const char* where_name1 = where_names.front().c_str();
			const char* where_value1 = where_values.front().c_str();
			strcat(result, where_name1);
			strcat(result, " = ");
			strcat(result, where_value1);

			if (i + 1 < columns.size())
			{
				strcat(result, and_);
			}
			
			//проверка на длинну
		}
		
		strcat(result, ";");

		return result;
	}

	SqlSelectQueryBuilder AddColumn(const std::string column)
	{
		columns.push_back(column);
		return SqlSelectQueryBuilder(columns);
	}

	SqlSelectQueryBuilder AddWhere(const std::string name, const std::string value)
	{
		where_names.push_back(name);
		where_values.push_back(value);
		return SqlSelectQueryBuilder();
	}
	

private:
	std::vector<std::string> columns;
	std::vector<std::string> where_names;
	std::vector<std::string> where_values;
	const char* select  = "SELECT ";
	const char* from = " FROM students WHERE ";
	const char* and_ = " AND ";
};

