# TouchDesigner OSC Examples

This repository contains examples for using Open Sound Control (OSC) with TouchDesigner, focusing on two iOS applications: iDraw-OSC and iKeleton-OSC.

## Overview

These examples demonstrate how to receive and visualize data from iOS applications that send OSC messages. The repository includes:

- TouchDesigner project files (`.toe`) for working with both applications
- A Max/MSP patch for receiving drawing data
- Documentation on OSC message formats and setup instructions

## iOS Applications

### iDraw-OSC

An iOS application that sends drawing data through OSC. It captures pen/pencil movements on the iPad and transmits the data in real-time via OSC protocol.


### iKeleton-OSC

An iOS application that captures body tracking data using the iPhone camera and sends it via OSC.


## How to Download

Both applications are available on the Apple App Store:

- [iDraw-OSC](https://apps.apple.com/ch/app/idraw-osc/id6461118802) (Search "iDraw-OSC" on App Store)
- [iKeleton-OSC](https://apps.apple.com/ch/app/ikeleton-osc/id6448196217) (Search "iKeleton-OSC" on App Store)

## Setup Instructions

### Basic Setup for Both Applications

1. Download and install the iOS application on your device (iPad for iDraw-OSC, iPhone for iKeleton-OSC)
2. Make sure your iOS device and computer are on the same local network
3. Find your computer's IP address:
   - **macOS**: Option + Click on Wi-Fi icon in menu bar
   - **Windows**: Go to Settings > Network & Internet > Wi-Fi > Your Wi-Fi
4. Open the application on your iOS device and enter your computer's IP address and desired port number

### TouchDesigner Setup

1. Download the TouchDesigner project files from this repository
2. Open the appropriate `.toe` file in TouchDesigner:
   - `zigsim-tutorial.toe` can be used as a starting point
   - For iDraw-OSC, use the project file from https://github.com/gwangyu-lee/iDraw-OSC
   - For iKeleton-OSC, use the project file from https://github.com/gwangyu-lee/iKeleton-OSC
3. Configure the network port in the TouchDesigner project:
   - Locate the `oscin1` CHOP node
   - Set the port number to match what you configured in the iOS app

### Max/MSP Setup (for iDraw-OSC)

1. Open the `Receive_iDraw.maxpat` file in Max/MSP
2. The patch is configured to receive drawing data on port 8800 by default
3. Ensure the port number matches the one configured in the iDraw-OSC app

## OSC Message Format

### iDraw-OSC Messages

iDraw-OSC sends the following data:

- `/x`, `/y`: Drawing position coordinates
- `/pressure`: Pen/pencil pressure
- `/aspectX`, `/aspectY`: Tilt aspect of the pencil
- `/r`, `/g`, `/b`, `/a`: RGBA color values
- `/pen`, `/monoline`, `/marker`, etc.: Tool selection indicators
- `/canvasWidth`, `/canvasHeight`: Canvas dimensions
- `/drawingWidth`, `/eraserWidth`: Tool width settings

### iKeleton-OSC Messages

iKeleton-OSC sends body tracking data including:
- Joint positions
- Skeleton connections
- Body tracking confidence values

## Tutorials

For more detailed instructions, check these tutorial links:

### iDraw-OSC Tutorials
- [iDraw OSC & TouchDesigner Tutorial (English)](https://www.gwangyulee.com/p/idraw-osc-tutorial-eng.html)

### iKeleton-OSC Tutorials
- [iKeleton OSC & TouchDesigner Tutorial (English)](https://www.gwangyulee.com/p/ikeleton-osc-tutorial-eng.html)
- [iKeleton OSC & Max For Live Tutorial](https://www.gwangyulee.com/p/ikeleton-osc-max-for-live.html)

## Usage Examples

### Using iDraw-OSC

1. Open iDraw-OSC on your iPad
2. Configure the IP address and port
3. Tap the "Draw & Send!" button
4. Draw on the screen using Apple Pencil or your finger
5. The drawing data will be transmitted via OSC to your computer
6. View the visualization in TouchDesigner or process the data in Max/MSP

### Using iKeleton-OSC

1. Open iKeleton-OSC on your iPhone
2. Configure the IP address and port in the Settings page
3. Point your camera at a person
4. The body tracking data will be transmitted via OSC to your computer
5. View the skeleton visualization in TouchDesigner

## Working with Max/MSP

The included Max/MSP patch (`Receive_iDraw.maxpat`) provides a ready-to-use solution for receiving and processing drawing data from iDraw-OSC. The patch:

- Receives OSC messages on port 8800
- Routes different types of data (coordinates, pressure, tool selection, etc.)
- Displays the values in real-time for debugging and creative use

## Additional Resources

- Official iDraw-OSC Repository: [https://github.com/gwangyu-lee/iDraw-OSC](https://github.com/gwangyu-lee/iDraw-OSC)
- Official iKeleton-OSC Repository: [https://github.com/gwangyu-lee/iKeleton-OSC](https://github.com/gwangyu-lee/iKeleton-OSC)
- TouchDesigner Documentation: [https://docs.derivative.ca/](https://docs.derivative.ca/)
- OSC Specification: [http://opensoundcontrol.org/spec-1_0](http://opensoundcontrol.org/spec-1_0)

## Troubleshooting

- If you cannot connect, verify that your iOS device and computer are on the same network
- Check firewall settings that might block OSC communications
- Ensure the port numbers match between the iOS app and your TouchDesigner/Max project
- If using a corporate or school network, try a personal hotspot instead as institutional networks often block OSC traffic

## License

This project is provided for educational and creative purposes. The iOS applications are subject to their respective licenses on the App Store.

## Acknowledgments

- Created by Gwangyu Lee
- TouchDesigner by Derivative
- Max/MSP by Cycling '74
