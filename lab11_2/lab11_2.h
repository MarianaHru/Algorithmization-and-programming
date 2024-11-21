#ifndef LAB11_2_H
#define LAB11_2_H

#include <string>

bool CheckNestedQuotes(const std::string &line);

std::string RemoveQuotesContent(const std::string &line);

void ProcessFile(const std::string &inputFile, const std::string &outputFile);

#endif
