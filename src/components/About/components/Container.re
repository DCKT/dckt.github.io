let component = "Container" |> ReasonReact.statelessComponent;

module Styles = {
  open Css;
  let root =
    style([
      display(`flex),
      flexWrap(`wrap),
      maxWidth(px(960)),
      alignItems(`center),
      margin(`auto),
    ]);
};

let make = children => {
  ...component,
  render: _self =>
    ReasonReact.createDomElement(
      "div",
      ~props={"className": Styles.root},
      children,
    ),
};