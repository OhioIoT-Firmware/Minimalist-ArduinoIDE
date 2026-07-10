

#include <OhioIoT-Minimalist.h>


#define WIFI_SSID  "your-wifi-name"
#define WIFI_PASS  "your-wifi-password"
#define MQTT_USER  "your-mqtt-user"
#define MQTT_PASS  "your-mqtt-password"



// REGULAR SUBSCRIPTIONS AND MESSAGE HANDLING Part 1 ----------------------------------

static const char * subscription_list[] = {
	"~/~/cypress",
	nullptr				// keep this
};


void messageHandler(char * topic, char * payload) {
	Serial.println(payload);	// replace this with something more interesting when you are ready
}






void setup() {

	Serial.begin(115200);
	Serial.println("\n\n\n+++++++++++  DEVICE BOOT  ++++++++++++++++++++++++++++++++++\n");

	controller.setup(WIFI_SSID, WIFI_PASS, MQTT_USER, MQTT_PASS);

	// REGULAR SUBSCRIPTIONS AND MESSAGE HANDLING Part 2 -----------------------------------
	mqtt.set_subscriptions(subscription_list);
	mqtt.set_callback(messageHandler);

}




void loop() {

	controller.loop();

	if (mqtt.is_connected) {

		// do something
		
	}

}

