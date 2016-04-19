//
// Created by SJ Holland on 4/12/16.
//

#ifndef SDTTEST_XMLDOMERRORHANDLER_H
#define SDTTEST_XMLDOMERRORHANDLER_H

#include <xercesc/sax/HandlerBase.hpp>

class XmlDomErrorHandler: public xercesc::HandlerBase {

public:
    void fatalError(const xercesc::SAXParseException& e);

};


#endif //SDTTEST_XMLDOMERRORHANDLER_H
