#include "Line.h"

Line::Line(string& code, unsigned int& start, unsigned int line)
{
	this->line_number = line;
	FindTokens(code, start);
}

Line::~Line()
{

}

void Line::FindTokens(string& code, unsigned int& start)
{
	formatted_text = "";
	bool in_string = false;
	unsigned char at;
	string token;
	for (; start < code.length(); start++)
	{
		at = code[start];
		if (at != '\n')
			formatted_text.insert(formatted_text.end(), at);

		if (at == '\"')
		{
			in_string = !in_string;
			token.insert(token.end(), at);
		}
		else if (at == '\n' && !in_string)
		{
			if (!token.empty())
				tokens.push_back(token);
			if (in_string)
				ErrorReporter::AddWarning("Unclosed string literal.", line_number, formatted_text);
			start++;
			return;
		}
		else if (!in_string && (at == ',' || at == ':'))
		{
			if (at == ':')
				token.insert(token.end(), at);
			tokens.push_back(token);
			token.clear();
		}
		else
		{
			token.insert(token.end(), at);
		}
	}

	if (in_string)
		ErrorReporter::AddError("Unclosed string literal", line_number, formatted_text);
	if (!token.empty())
		tokens.push_back(token);
}

void Line::SetToken(unsigned int token_index, string value)
{
	formatted_text.clear();
	tokens[token_index] = value;
	for (unsigned int i = 0; i < tokens.size() - 1; i++)
		formatted_text.append(tokens[i]).append(",");
	formatted_text.append(tokens[tokens.size() - 1]);
}