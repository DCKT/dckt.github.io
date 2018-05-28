open Helpers;

let component = "Header" |> ReasonReact.statelessComponent;

module Styles = {
  open Css;
  let root =
    style([
      display(`flex),
      justifyContent(center),
      alignItems(center),
      height(pct(98.5)),
      backgroundImage(url("/images/h.jpg")),
      backgroundSize(cover),
      backgroundPosition(pct(50.), pct(50.)),
      selector(
        "&:before",
        [
          unsafe("content", " "),
          display(block),
          position(`absolute),
          top(px(0)),
          left(px(0)),
          width(pct(100.)),
          height(pct(100.)),
          backgroundColor(rgba(33, 33, 33, 0.5)),
        ],
      ),
    ]);
  let headerContent = style([zIndex(1)]);
  let title = style([fontSize(px(32)), color(hex("fff"))]);
};

let make = _children => {
  ...component,
  render: _self =>
    <header className=Styles.root>
      <div className=Styles.headerContent>
        <h1 className=Styles.title> ("Thomas Deconinck" |> text) </h1>
      </div>
    </header>,
};