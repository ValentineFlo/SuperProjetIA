#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class TextureCache
{
public:
	sf::Texture& getTexture(const std::string& execFilePath);
	~TextureCache();
private:
	struct TextureInfo
	{
		sf::Texture* texture;
		std::string path;
	};
	std::vector<TextureInfo> m_allTextureInfos;
};

class FontCache
{
public:
	sf::Font& getFont(const std::string& path);
	~FontCache();
private:
	struct Fontinfo
	{
		sf::Font* font;
		std::string path;
	};
	std::vector<Fontinfo> m_allFontInfos;
};
