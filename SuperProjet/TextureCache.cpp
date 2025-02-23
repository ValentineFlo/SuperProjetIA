#include "TextureCache.h"
// a enlever 
#include <iostream>
sf::Texture& TextureCache::getTexture(const std::string& path)
{
    for (auto& textureinfo : m_allTextureInfos)
    {
        if (textureinfo.path == path)
        {
            return *textureinfo.texture;
        }
    }
    TextureInfo ti;
    ti.path = path;
    ti.texture = new sf::Texture;
    if (!ti.texture->loadFromFile(path))
        std::cout << "error font";
    m_allTextureInfos.push_back(ti);

    return *ti.texture;
}

TextureCache::~TextureCache()
{
    for (auto textureinfo : m_allTextureInfos)
        delete textureinfo.texture;
    m_allTextureInfos.clear();
}

sf::Font& FontCache::getFont(const std::string& path)
{
    for (auto& fontinfo : m_allFontInfos)
    {
        if (fontinfo.path == path)
        {
            return *fontinfo.font;
        }
    }
    Fontinfo fo;
    fo.path = path;
    fo.font = new sf::Font;
    if (!fo.font->loadFromFile(path))
        std::cout << "error font";
    m_allFontInfos.push_back(fo);
    return *fo.font;
}

FontCache::~FontCache()
{
    for (auto textureinfo : m_allFontInfos)
        delete textureinfo.font;
    m_allFontInfos.clear();
}
