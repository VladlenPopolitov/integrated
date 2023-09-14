#include <iostream>
#include <mimetic/mimetic.h>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <memory>

#include "cryptlib.h"
#include "base64.h"

int main(int argc, char** argv){
    try{
        // mimetic part
        std::cout << "Run..."<<std::endl;
        std::wstring input { 0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00 };// {"Text input1"};
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


        CryptoPP::byte decoded[] = { 0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00 };
        std::string encoded;

        CryptoPP::Base64Encoder encoder;
        encoder.Put(decoded,sizeof(decoded));
        encoder.MessageEnd();

        CryptoPP::word64 size = encoder.MaxRetrievable();
        if (size)
        {
            encoded.resize(size);
            encoder.Get((CryptoPP::byte*)&encoded[0], encoded.size());
        }

        std::cout << encoded << std::endl;

    } catch(...){
        return 1;
    }
 return 0;   
}

std::string  GetComputerString() {
    return "aaa";
}