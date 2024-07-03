#include "Soundex.h"
#include <cctype>

char getSoundexCode(char c)
{
    static const char soundexCodes[26] = {0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2};
    return soundexCodes[toupper(c) - 'A'];
}

std::string generateSoundex(const std::string& name) 
{
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i)
    {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode)
        {
            soundex += code;
            prevCode = code;
        }
    }

    while (soundex.length() < 4) 
    {
        soundex += '0';
    }

    return soundex;
}
