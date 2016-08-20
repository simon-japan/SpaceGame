//
// Created by SJ Holland on 4/12/16.
//

#include <iostream>
#include "XmlDOMDocument.h"
#include "XmlDomErrorHandler.h"

using namespace std;
using namespace xercesc;


void XmlDomDocument::createParser() {
    if (!parser)
    {
        XMLPlatformUtils::Initialize();
        parser = new XercesDOMParser();
        errorHandler = new XmlDomErrorHandler();
        parser->setErrorHandler(errorHandler);
    }
}

XmlDomDocument::XmlDomDocument(const char *xmlFile) : m_doc(nullptr) {
    createParser();
    try {
        parser->parse(xmlFile);
        m_doc = parser->getDocument();
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
    }
    catch (const DOMException& toCatch) {
        char* message = XMLString::transcode(toCatch.msg);
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
    }
    catch (...) {
        cout << "Unexpected Exception \n" ;
    }
}

XmlDomDocument::~XmlDomDocument() {
    if (m_doc) m_doc->release();
}

string XmlDomDocument::getChildValue(const char *parentTag, int parentIndex, const char *childTag, int childIndex) {
    XMLCh* temp = XMLString::transcode(parentTag);
    DOMNodeList* list = m_doc->getElementsByTagName(temp);
    XMLString::release(&temp);

    DOMElement* parent =
            dynamic_cast<DOMElement*>(list->item(parentIndex));
    DOMElement* child =
            dynamic_cast<DOMElement*>(parent->getElementsByTagName(
                    XMLString::transcode(childTag))->item(childIndex));

    string value;
    if (child) {
        char* temp2 = XMLString::transcode(child->getTextContent());
        value = temp2;
        XMLString::release(&temp2);
    }
    else {
        value = "";
    }
    return value;
}

std::string XmlDomDocument::getChildAttribute(const char* parentTag,
                              int parentIndex, int childIndex,
                              const char* childTag,
                              const char* attributeTag)
{
    XMLCh* temp = XMLString::transcode(parentTag);
    DOMNodeList* list = m_doc->getElementsByTagName(temp);
    XMLString::release(&temp);

    DOMElement* parent =
            dynamic_cast<DOMElement*>(list->item(parentIndex));
    DOMElement* child =
            dynamic_cast<DOMElement*>(parent->getElementsByTagName(XMLString::transcode(childTag))->item(childIndex));

    string value;
    if (child) {
        temp = XMLString::transcode(attributeTag);
        char* temp2 = XMLString::transcode(child->getAttribute(temp));
        value = temp2;
        XMLString::release(&temp2);
    }
    else {
        value = "";
    }
    return value;

}

int XmlDomDocument::getChildCount(const char *parentTag, int parentIndex, const char *childTag) {
    if (m_doc == nullptr)
    {
        return 0;
    }
    else {
        XMLCh *temp = XMLString::transcode(parentTag);
        DOMNodeList *list = m_doc->getElementsByTagName(temp);
        XMLString::release(&temp);

        DOMElement *parent = dynamic_cast<DOMElement *>(list->item(parentIndex));
        DOMNodeList *childList = parent->getElementsByTagName(XMLString::transcode(childTag));
        return (int) childList->getLength();
    }
}

bool XmlDomDocument::loadedSuccessfully() {
    return m_doc != nullptr;
}








