open BsReactNative;

open Helpers;

let component = "SocialLink" |> ReasonReact.statelessComponent;

let styles =
  StyleSheet.create(
    Style.(
      {
        "link": style([padding(Pt(10.))]),
        "image": style([width(Pt(55.))]),
      }
    ),
  );

let make = (~href: string, _children) => {
  ...component,
  render: _self => {
    let handleClick = () => Js.log("test");
    <TouchableOpacity accessibilityTraits=[`link] onPress=handleClick>
      <Text> ("open https://github.com/DCKT" |> text) </Text>
    </TouchableOpacity>;
  },
};