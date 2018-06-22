project 'Builds/iOS/JuceRNExample.xcodeproj'
workspace 'Builds/iOS/JuceRNExample.xcworkspace'

target 'JuceRNExample - App' do
  pod 'React', :path => 'ReactNative/node_modules/react-native', :subspecs => [
    'Core',
    'CxxBridge', # Include this for RN >= 0.47
    'DevSupport', # Include this to enable In-App Devmenu if RN >= 0.43
    'RCTActionSheet',
    'RCTAnimation',
    'RCTGeolocation',
    'RCTImage',
    'RCTLinkingIOS',
    'RCTNetwork',
    'RCTSettings',
    'RCTText',
    'RCTWebSocket',
  ]

  # Explicitly include Yoga if you are using RN >= 0.42.0
  pod 'yoga', :path => 'ReactNative/node_modules/react-native/ReactCommon/yoga'

  # Third party deps podspec link
  pod 'DoubleConversion', :podspec => 'ReactNative/node_modules/react-native/third-party-podspecs/DoubleConversion.podspec'
  pod 'glog', :podspec => 'ReactNative/node_modules/react-native/third-party-podspecs/glog.podspec'
  pod 'Folly', :podspec => 'ReactNative/node_modules/react-native/third-party-podspecs/Folly.podspec'
end
