int RELAY1 = D3;
int RELAY2 = D4;
int RELAY3 = D5;
int RELAY4 = D6;

void setup() {

	// Initilize the relay control pins as output
	pinMode(RELAY1, OUTPUT);
	pinMode(RELAY2, OUTPUT);
	pinMode(RELAY3, OUTPUT);
	pinMode(RELAY4, OUTPUT);

	// Initialize all relays to an OFF state
	digitalWrite(RELAY1, LOW);
	digitalWrite(RELAY2, LOW);
	digitalWrite(RELAY3, LOW);
	digitalWrite(RELAY4, LOW);

	// Expose relayControl function to Particle API
	Particle.function("relay", relayControl);
}

void loop() {
   // This loops forever
}

// Function to toggle relays
int relayControl(String command) {

	int relayState = 0;
	int relayNumber = command.charAt(1) - '0';
	if (relayNumber < 1 || relayNumber > 4) return -1;
	if (command.substring(3,7) == "HIGH") {
		relayState = 1;
		digitalWrite(relayNumber+2, relayState);
		delay(7200000); // leave on for two hours
		relayState = 0;
		digitalWrite(relayNumber+2, relayState);
	} else if (command.substring(3,6) == "LOW") {
		relayState = 0;
		digitalWrite(relayNumber+2, relayState);
	} else {
		return -1;
	}

	return 1;
}
