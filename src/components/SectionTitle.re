open Helpers;

let component = "SectionTitle" |> ReasonReact.statelessComponent;

module Styles = {
  open Css;
  let title =
    style([
      fontSize(px(40)),
      fontWeight(700),
      margin2(~v=px(30), ~h=px(0)),
      textAlign(center),
    ]);
};

let make = (~value: string, _children) => {
  ...component,
  render: _self => <h2 className=Styles.title> (value |> text) </h2>,
};