# Slack a Particle
This is some base code to put on a php server and a Particle board that will allow Slack to switch a 120V appliance on/off over the internet.

## Setup

1. Put server.php on a publicly accessable php web server
2. Set up an Outgoing Webhook integration in Slack pointing to file above
3. Configure server.php with Slack webhook token and Particle API info
4. Put particle.ino on your Particle board with Relay Shield
5. Turn stuff on/off from Slack
  
