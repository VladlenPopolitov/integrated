#include <iostream>
#include <mimetic/mimetic.h>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <memory>

int main(int argc, char** argv){
    try{
        // mimetic part
        std::cout << "Run..."<<std::endl;
        std::string input{"Text input1"};
        std::string output{};
        auto ibeg=input.begin();
        auto iend=input.end();
        std::stringstream os;
        std::ostreambuf_iterator<char> out(os);
   
        mimetic::Base64::Encoder b64;
        mimetic::code(ibeg, iend, b64, out);
        os>>output;
        std::cout << output <<std::endl;
       	try {
		xercesc::XMLPlatformUtils::Initialize();
		//XalanTransformer::initialize();

        }
        catch (const xercesc::XMLException& toCatch) {
            char* message = xercesc::XMLString::transcode(toCatch.getMessage());
            std::cout << "Error during initialization! :\n" << message << "\n";
            xercesc::XMLString::release(&message);
            return 1;
        }

        std::unique_ptr<xercesc::XercesDOMParser> parser = std::make_unique < xercesc::XercesDOMParser >(); //memory021
        parser->setValidationScheme(xercesc::XercesDOMParser::Val_Always);
        parser->setDoNamespaces(true); // optional	
        std::cout << "Xml parser created" <<std::endl;


    } catch(...){
        return 1;
    }
 return 0;   
}