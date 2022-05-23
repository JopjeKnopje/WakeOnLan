#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#include "PowerButton.h"
#include "Credentials.h"


// TODO define the credentials here if the header is not included

// #ifndef CREDENTIALS_H
// #define WIFI_SSID ""
// #define WIFI_PASSWORD ""
// #define BOT_TOKEN ""
// #define USER_ID ""
// #endif

const unsigned long BOT_SCAN_TIME = 1000; // mean time between scan messages


PowerButton laptopPowerButton(5);
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long bot_lasttime; // last time messages' scan has been done


bool poweroffDialog = false;


void handleNewMessages(int numNewMessages)
{
	Serial.print("handleNewMessages ");
	Serial.println(numNewMessages);

	for (int i = 0; i < numNewMessages; i++)
	{
		String chat_id = bot.messages[i].chat_id;
		String text = bot.messages[i].text;


		if (!(bot.messages[i].from_id == USER_ID))
		{
			// TODO Log random people to file 
			bot.sendMessage(chat_id, "What are you trying bro...", "");
			return;
		}	


		else if (text == "/poweron")
		{
			Serial.println("/poweron");
			bot.sendMessage(chat_id, "powering on...", "");
			laptopPowerButton.turnOn();

		}

		else if (text == "/poweroff")
		{
			Serial.println("/poweroff");
			bot.sendMessage(chat_id, "You are about to physically turn off the server.\n Are you sure?\n [y/n]");
			poweroffDialog = true;
		}


		else if (poweroffDialog && text == "yes")
		{        
			Serial.println("/poweroff yes");
			bot.sendMessage(chat_id, "turning off server.");
		
			laptopPowerButton.turnOff();
			poweroffDialog = false;
	}

		else if (text == "/help")
		{
			String help_msg = "Cursed WoL implementation.\n\n";
			help_msg += "/poweron : Presses the power button\n";
			help_msg += "/poweroff : Presses the power button for a long time\n";
			bot.sendMessage(chat_id, help_msg, "Markdown");
			Serial.println("/help");
		}
		else
		{
			bot.sendMessage(chat_id, "Command not found try /help");
		}
		
	}
}


void setup()
{
	Serial.begin(115200);
	Serial.println();



	// attempt to connect to Wifi network:
	configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
	secured_client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
	Serial.print("Connecting to Wifi SSID ");
	Serial.print(WIFI_SSID);
	WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
	while (WiFi.status() != WL_CONNECTED)
	{
		Serial.print(WIFI_SSID);
		Serial.print(WIFI_PASSWORD);
		Serial.print(BOT_TOKEN);
		Serial.print(USER_ID);
		Serial.print(".");
		delay(500);
	}
	Serial.print("\nWiFi connected. IP address: ");
	Serial.println(WiFi.localIP());

	// Check NTP/Time, usually it is instantaneous and you can delete the code below.
	Serial.print("Retrieving time: ");
	time_t now = time(nullptr);
	while (now < 24 * 3600)
	{
		Serial.print(".");
		delay(100);
		now = time(nullptr);
	}
	Serial.println(now);
}

void loop()
{
	// TODO Add timer class
	if (millis() - bot_lasttime > BOT_SCAN_TIME)
	{
		// check for new message by giving it the previous received message count and adding 1
		int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

		while (numNewMessages)
		{
			Serial.println("got response");
			Serial.println(numNewMessages);
			handleNewMessages(numNewMessages);
			// if the numNewMessages reaches zero there are no messages left to process
			numNewMessages = bot.getUpdates(bot.last_message_received + 1);
		}

		bot_lasttime = millis();
	}
}