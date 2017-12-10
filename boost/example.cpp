#include <boost/regex.hpp>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    boost::regex pat("^Subject: (Re: | Aw: )*(.*)");

    while (cin) {
        getline(cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
            cout << matches[2] << endl;
    }
}
