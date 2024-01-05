#include "ResourceFactory.h"
#include "stringResouce/InOutReSource.h"
#include "stringResouce/TextFileManager.h"
ResourceFactory::ResourceFactory()
{

}

std::unique_ptr<InOutReSource> ResourceFactory::create(char choosen)
{
    switch(choosen)
    {
     case 'F':
         return std::make_unique<TextFileManager>();

    }
}
