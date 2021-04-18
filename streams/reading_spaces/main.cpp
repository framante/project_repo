#include <string>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <iostream>



int main()
{
  std::string s;
  std::ifstream file("input.txt");
// lambdas to test condition.
// I use unsigned char as parameter, since it has better following the rule, but simply char (or even int!) should work
  auto notspace=[](unsigned char const & c){return !std::isspace(c);};
  int counter=0;
  while (!file.eof())
  {
    ++counter;
    std::getline(file,s);
    // traverse the string from end to beginning to find
    // the last character that is not a space
    // I use reverse iterators
    auto it = std::find_if(s.rbegin(),s.rend(),notspace);
    bool fullS=(it==s.rend()); // if true is either empty or full of spaces
    std::cout<<"Line:"<<counter<<" contains "<<s.size()<<" characters"<<std::endl;
    if(s.empty()) // well the line was empty.ie. it contained only newline, which is discarded by getline
      std::cout<<std::boolalpha<<"Line:"<<counter<<" is empty"<<std::endl;
    else
    {
      if(fullS)std::cout<<"Line:"<<counter<<" is full of spaces!"<<std::endl;
    }
  } // iterate until end of file
file.close(); // always better closing the file
}
