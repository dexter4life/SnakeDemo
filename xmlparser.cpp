/*!
    Peter
*/

#include "xmlparser.h"

#include <iostream>
using std::cout;
using std::endl;


XmlParser::XmlParser()
{

}

XmlParser::XmlParser( std::string &path)
{
    doc = new TiXmlDocument( path.c_str() );

    if( !doc->LoadFile() )
        cout << doc->ErrorDesc() << endl;


    TiXmlElement *element = doc->FirstChildElement("level");
    w = atoi(element->Attribute("width") );
    h = atoi(element->Attribute("height"));
    level = atoi(element->Attribute("type"));

   setAttribute();

}


int XmlParser::getLevelType() const
{
    return level;
}

int XmlParser::getHeight() const
{
    return h;
}

int XmlParser::getWidth() const
{
    return w;
}

void XmlParser::setAttribute()
{
    Attribute attrib;

    TiXmlElement *element = doc->FirstChildElement();
    TiXmlElement *child = element->FirstChildElement();
    TiXmlElement *next = child;


    for(; next; next = next->NextSiblingElement() )
    {
        attrib.id = atoi( next->GetText() );
        attrib.x = atoi( next->Attribute("xcol"));
        attrib.y = atoi( next->Attribute("ycol"));
        attrib.xcount = atoi( next->Attribute("xcount"));
        attrib.ycount = atoi( next->Attribute("ycount"));
        data.push_back(attrib);
    }

}
