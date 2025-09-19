#pragma once
#include <string>
#include <vector>
#include <cstdint>

#ifdef ENTERARMYDISCORD_EXPORTS
#define EAD_API __declspec(dllexport)
#else
#define EAD_API __declspec(dllimport)
#endif

namespace EnterArmyDiscord {

	struct EmbedField {
		std::string name;
		std::string value;
		bool inlineField = false;
	};

	class EAD_API EmbedBuilder {
	private:
		std::string title;
		std::string description;
		int color = 0;
		std::string authorName;
		std::string authorUrl;
		std::string authorIconUrl;
		std::string footerText;
		std::string footerIconUrl;
		std::string imageUrl;
		std::string thumbnailUrl;
		std::string timestamp;
		std::vector<EmbedField> fields;

	public:
		EmbedBuilder& Title(const std::string& t) { title = t; return *this; }
		EmbedBuilder& Description(const std::string& d) { description = d; return *this; }
		EmbedBuilder& Color(int c) { color = c; return *this; }
		EmbedBuilder& Author(const std::string& name, const std::string& url = "", const std::string& iconUrl = "") { authorName = name; authorUrl = url; authorIconUrl = iconUrl; return *this; }
		EmbedBuilder& Footer(const std::string& text, const std::string& iconUrl = "") { footerText = text; footerIconUrl = iconUrl; return *this; }
		EmbedBuilder& Image(const std::string& url) { imageUrl = url; return *this; }
		EmbedBuilder& Thumbnail(const std::string& url) { thumbnailUrl = url; return *this; }
		EmbedBuilder& Timestamp(const std::string& ts) { timestamp = ts; return *this; }

		EmbedBuilder& AddField(const std::string& name, const std::string& value, bool inlineField = false) { fields.push_back({ name, value, inlineField });
			return *this;
		}

		std::string ToString() const;
	};


	class EAD_API DiscordWebhook {
	public:
		static int Send(const std::string& webhookUrl, const std::string& content);
		static int SendEmbed(const std::string& webhookUrl, const std::string& embedJson);
		static int SendFile(const std::string& webhookUrl, const std::string& filePath, const std::string& message = "");
	};

	extern "C" {
		EAD_API int SendWebhook(const char* webhookUrl, const char* content);
		EAD_API int SendEmbed(const char* webhookUrl, const char* embedJson);
		EAD_API int SendFile(const char* webhookUrl, const char* filePath, const char* message = nullptr);
	}

}

// ENTERARMY | discord: mlodyrr