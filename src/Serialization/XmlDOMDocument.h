//
// Created by SJ Holland on 4/12/16.
// Copied from http://vichargrave.com/xml-parsing-with-dom-using-c/
//

#ifndef SDTTEST_XMLDOMDOCUMENT_H
#define SDTTEST_XMLDOMDOCUMENT_H


#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <string>


class XmlDomDocument
{
    xercesc::DOMDocument* m_doc;

public:
    XmlDomDocument(const char* xmlfile);
    ~XmlDomDocument();
    std::string getChildValue(const char* parentTag, int parentIndex,
                         const char* childTag, int childIndex);
    std::string getChildAttribute(const char* parentTag,
                             int parentIndex, int childIndex,
                             const char* childTag,
                             const char* attributeTag);
    int getChildCount(const char* parentTag, int parentIndex,
                      const char* childTag);


private:
    XmlDomDocument();
    XmlDomDocument(const XmlDomDocument&);
    void createParser();
    xercesc::XercesDOMParser*   parser = NULL;
    xercesc::ErrorHandler*      errorHandler = NULL;
};


#endif //SDTTEST_XMLDOMDOCUMENT_H
