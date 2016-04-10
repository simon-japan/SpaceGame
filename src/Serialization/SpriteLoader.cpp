//
// Created by SJ Holland on 4/9/16.
//

#include "SpriteLoader.h"
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLString.hpp>
#include <iostream>

using namespace std;
using namespace xercesc;

int SpriteLoader::loadSprites(std::string filename, SpriteRepository & spriteRepository,
                              TextureRepository & textureRepository, SDL_Renderer *renderer) {

    // Initialize Xerces
    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization! :\n"
        << message << "\n";
        XMLString::release(&message);
        return 1;
    }

    // Set up XML parser
    XercesDOMParser* parser = new XercesDOMParser();
    parser->setValidationScheme(XercesDOMParser::Val_Always);
    parser->setDoNamespaces(true);    // optional
    parser->setDoSchema(true);
    parser->setValidationConstraintFatal(true);

    //ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
    //parser->setErrorHandler(errHandler);

    try {
        parser->parse(XMLString::transcode(filename.c_str()));

        DOMElement* docRootNode;
        DOMDocument* doc;
        DOMNodeIterator * walker;
        doc = parser->getDocument();
        docRootNode = doc->getDocumentElement();

        // Create the node iterator, that will walk through each element.
        walker = doc->createNodeIterator(docRootNode,DOMNodeFilter::SHOW_ELEMENT,NULL,true);

        DOMNode * current_node = NULL;
        string thisNodeName;
        string parentNodeName;
        bool clipParts[6] = {false,false,false,false,false,false};

        // Walk thru the document.
        for (current_node = walker->nextNode(); current_node != 0; current_node = walker->nextNode()) {

            thisNodeName = XMLString::transcode(current_node->getNodeName());
            parentNodeName = XMLString::transcode(current_node->getParentNode()->getNodeName());
        }

    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
        << message << "\n";
        XMLString::release(&message);
        return -1;
    }
    catch (const DOMException& toCatch) {
        char* message = XMLString::transcode(toCatch.msg);
        cout << "Exception message is: \n"
        << message << "\n";
        XMLString::release(&message);
        return -1;
    }
    catch (...) {
        cout << "Unexpected Exception \n" ;
        return -1;
    }

    delete parser;
    //delete errHandler;

    XMLPlatformUtils::Terminate();

    // Other terminations and cleanup.
    return 0;

}

bool SpriteLoader::loadTexture(std::string fileName, string textureName, TextureRepository & textureRepository,
                               SDL_Renderer *renderer) {
    LTexture texture;
    if(texture.loadFromFile(fileName, renderer))
    {
        printf( "Failed to load dot texture!\n" );
        return false;
    }
    textureRepository.addTexture(textureName, &texture);
    return true;
}





