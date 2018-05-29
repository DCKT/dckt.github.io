let component = "Section" |> ReasonReact.statelessComponent;

module Styles = {
  open Css;
  let container = style([padding2(~v=px(80), ~h=px(20))]);
};

let make = children => {
  ...component,
  render: _self =>
    ReasonReact.createDomElement(
      "div",
      ~props={"className": Styles.container},
      children,
    ),
};