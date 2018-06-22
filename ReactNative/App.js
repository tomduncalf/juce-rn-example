import * as React from 'react';
import {
  SafeAreaView,
  Text,
  Slider,
  NativeModules,
  NativeEventEmitter,
} from 'react-native';

class App extends React.Component {
  state = {
    time: undefined
  };

  componentDidMount() {
    // We need this to capture a pointer to the module instance
    NativeModules.ExampleModule.setup();

    // Set up the event listener
    const emitter = new NativeEventEmitter(NativeModules.ExampleModule);
    emitter.addListener('UPDATE_TIME', (args) => {
      this.setState({ time: args.time });
    });
  }

  render() {
    return (
      <SafeAreaView style={{ margin: 10 }}>
        <Text style={{ marginTop: 20 }}>Frequency</Text>
        <Slider
          onValueChange={v => NativeModules.ExampleModule.setFrequency(v)}
          value={440}
          minimumValue={50}
          maximumValue={2000}
        />

        <Text style={{ marginTop: 20 }}>Level</Text>
        <Slider
          onValueChange={v => NativeModules.ExampleModule.setLevel(v)}
          value={0}
          minimumValue={0}
          maximumValue={1}
        />

        {this.state.time !== undefined &&
          <Text style={{ marginTop: 20 }}>The time is: {this.state.time}</Text>}
      </SafeAreaView>
    );
  }
}

export default App;
