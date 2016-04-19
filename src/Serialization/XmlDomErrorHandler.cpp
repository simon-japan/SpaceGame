//
// Created by SJ Holland on 4/12/16.
//

#include <iostream>
#include "XmlDomErrorHandler.h"

void XmlDomErrorHandler::fatalError(const xercesc::SAXParseException & e) {
    std::cout << "Fatal parsing error at line " << (int)e.getLineNumber() << std::endl;
}

