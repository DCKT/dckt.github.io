open BsReactNative;

open Helpers;

let component = "Socials" |> ReasonReact.statelessComponent;

module Styles = {
  open Css;
  let root =
    style([
      display(`flex),
      flexDirection(row),
      alignItems(center),
      justifyContent(center),
    ]);
  let link =
    style([padding(px(10)), selector(":hover", [opacity(0.7)])]);
  let socialImage = style([width(px(55))]);
};

let styles =
  StyleSheet.create(
    Style.(
      {
        "root":
          style([
            flex(1.0),
            flexDirection(Row),
            alignItems(Center),
            justifyContent(Center),
          ]),
      }
    ),
  );

let make = _children => {
  ...component,
  render: _self =>
    <View style=styles##root>
      <a href="https://twitter.com/DCK__" className=Styles.link>
        <img className=Styles.socialImage src="/images/socials/twitter.svg" />
      </a>
      <a href="https://github.com/DCKT" className=Styles.link>
        <img className=Styles.socialImage src="/images/socials/github.svg" />
      </a>
      <a
        href="https://www.linkedin.com/in/deconinckthomas/"
        className=Styles.link>
        <img className=Styles.socialImage src="/images/socials/linkedin.svg" />
      </a>
    </View>,
};