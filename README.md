## Pre-requisites
1. A Mac with XCode and XCode command line tools installed
2. Install `npm` to install JS dependencies (https://nodejs.org/en/ or `brew install node` - may already be installed)
3. Install Cocoapods to install native dependencies (https://guides.cocoapods.org/using/getting-started.html - `sudo gem install cocoapods` should work on most systems)
4. Install `react-native-cli` globally with `npm install -g react-native-cli`

## Setup
1. `cd` into the `ReactNative` subdirectory of the project
2. run `npm install` to install the JS dependencies (i.e. React Native itself)
3. Open `JuceRNExample.jucer` in Projucer and press Cmd-S to export for XCode (we don't want to open the project yet)
4. `cd ..` back to the top level and run `pod install` to install the native depdencies into the XCode workspace
5. Open `Builds/iOS/JuceRNExample.xcworkspace` (*not* `.xcodeproj`) in XCode

*Note:* if you make any changes to the Projucer project, you need to export and then run `pod install` again, otherwise the Cocoapods specific settings will be lost

## Running the project (development mode)
1. From the `ReactNative` subdirectory, run `react-native start` to start the development server
2. Ensure the `Debug` build configuration is selected in XCode's Product > Scheme > Edit Scheme dialog
3. Run the project from Xcode.

*Note:* if you are running on a real device rather than the simulator, you'll need to update `127.0.0.1` in `BridgeDelegate.mm` to your computer's wifi LAN address so that the device can load from the computer over the wifi network.
