open Helpers;

let component = "Header" |> ReasonReact.statelessComponent;

module Styles = {
  open Css;
  let root =
    style([
      position(relative),
      display(`flex),
      justifyContent(center),
      alignItems(center),
      height(pct(98.5)),
      backgroundImage(url("/images/header.jpg")),
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
  let picture =
    style([
      display(block),
      margin2(~v=px(10), ~h=`auto),
      maxWidth(px(300)),
      borderRadius(pct(100.)),
      border(px(5), solid, hex("fff")),
      boxShadow(~x=px(0), ~y=px(2), rgba(24, 24, 24, 0.5)),
    ]);
};

let make = _children => {
  ...component,
  render: _self =>
    <header className=Styles.root>
      <div className=Styles.headerContent>
        <img
          className=Styles.picture
          src="/images/me.jpg"
          alt="Picture of me eating a MelonPan"
        />
        <h1 className=Styles.title> ("Thomas Deconinck" |> text) </h1>
      </div>
    </header>,
};