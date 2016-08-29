//
// Created by SJ Holland on 4/12/16.
//

#ifndef SPACEGAME_XMLDOMERRORHANDLER_H
#define SPACEGAME_XMLDOMERRORHANDLER_H

#include <xercesc/sax/HandlerBase.hpp>

class XmlDomErrorHandler: public xercesc::HandlerBase {

public:
    void fatalError(const xercesc::SAXParseException& e);

};


#endif //SPACEGAME_XMLDOMERRORHANDLER_H
