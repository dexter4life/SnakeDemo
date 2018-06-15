#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <tinyxml.h>

#include <string>
#include <vector>
using std::vector;

#ifndef ATTRIBUTE
#define ATTRIBUTE

struct Attribute
{
    int id;
    int x;
    int y;
    int xcount;
    int ycount;
};

#endif

class XmlParser
{
public:
    XmlParser();
    XmlParser(std::string &);

    int getLevelType() const;
    int getHeight() const;
    int getWidth() const;

    vector< Attribute > &getLevelAttribute()
    {
        return data;
    }

    void setAttribute();

private:
    int h, w, level;
    TiXmlDocument *doc;
    vector< Attribute > data;
};

#endif // XMLPARSER_H
