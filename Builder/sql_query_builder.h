#pragma once
#include <string>
#include <vector>
#include <deque>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

class SqlSelectQueryBuilder
{
public:
	/*constexpr*/ char* BuildQuery()
	{
		const int length = 256;
		char* result = new char[length] {};
		strcpy(result, select);
		
		if (columns.size() > 0)
		{
			for (size_t i = 0; i < columns.size(); i++)
			{
				
				const char* column_var = columns.at(i).c_str();
				strcat(result, column_var);
				strcat(result, ",");
			}
			char* ptr = strrchr(result, ',');
			*ptr = 0;
			if (IsLengthMore(result, length))
			{
				result[255] = 0;
				return result;
			}
		}
		else
		{
			const char* column_var = "* ";
			strcat(result, column_var);
		}

		strcat(result, from); 
		const std::string table = tables.front();
		tables.pop_front();
		strcat(result, table.c_str());
		strcat(result, where);

		for (size_t i = 0; i < where_names.size(); i++)
		{
			const char* where_name1 = where_names.at(i).c_str();
			const char* where_value1 = where_values.at(i).c_str();
			strcat(result, where_name1);
			strcat(result, " = ");
			strcat(result, where_value1);

			if (i + 1 < columns.size())
			{
				strcat(result, and_);
			}
			
			if (IsLengthMore(result, length))
			{
				result[255] = 0;
				return result;
			}
		}
		
		strcat(result, ";");

		return result;
	}

	SqlSelectQueryBuilder& AddColumn(const std::string column)
	{
		columns.push_back(column);
		return *this;
	}

	SqlSelectQueryBuilder& AddWhere(const std::string name, const std::string value)
	{
		where_names.push_back(name);
		where_values.push_back(value);
		return *this;
	}

	SqlSelectQueryBuilder& AddFrom(const std::string table)
	{
		tables.push_front(table);
		return *this;
	}

	bool IsLengthMore(const char* str, int max_length)
	{
		std::cout << strlen(str);
		if (strlen(str) > max_length)
		{
			return true;
		}
		return false;
	}
	
private:
	//SqlSelectQueryBuilder* select_query;
	std::vector<std::string> columns;
	std::vector<std::string> where_names;
	std::vector<std::string> where_values;
	std::deque<std::string> tables;
	const char* select  = "SELECT ";
	const char* from = " FROM ";
	const char* where = " WHERE ";
	const char* and_ = " AND ";
};

