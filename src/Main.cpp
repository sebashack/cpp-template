#include "Generator.h"


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " WORDS_FILEPATH" << std::endl;
        return 1;
    }

    std::string filepath = argv[1];
    Generator gen(filepath);

    gen.printSentences();

    return 0;
}
