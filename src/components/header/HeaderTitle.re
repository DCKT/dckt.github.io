open BsReactNative;

open Helpers;

let component = "HeaderTitle" |> ReasonReact.statelessComponent;

let make = _children => {
  ...component,
  render: _self =>
    <View>
      <Text>
        ("Thomas Deconinck" |> text)
        <Text> ({js|Développeur JavaScript|js} |> text) </Text>
      </Text>
    </View>,
};