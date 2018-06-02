open Helpers;

let component = "TimelineItem" |> ReasonReact.statelessComponent;

module Styles = {
  open Css;
  let tag =
    style([
      padding2(~v=px(5), ~h=px(10)),
      marginRight(px(5)),
      backgroundColor(hex("75ce66")),
      color(hex("fff")),
      borderRadius(px(2)),
      marginBottom(px(5)),
    ]);
};

let make = (~item: Types.timelineItem, _children) => {
  ...component,
  render: _self =>
    <div className="cd-timeline-block">
      <div className="cd-timeline-img cd-picture">
        <img src="images/code.svg" alt="Picture" />
      </div>
      <div className="cd-timeline-content">
        <h2>
          (
            switch (item) {
            | QuaPost(t) =>
              <span className="Works-itemTitle"> (t##title |> text) </span>
            | ExpPost(t) =>
              <span className="Works-itemTitle"> (t##title |> text) </span>
            }
          )
          (
            switch (item) {
            | QuaPost(_) => nothing
            | ExpPost(t) =>
              <span className="Works-itemCompany"> (t##company |> text) </span>
            }
          )
          (
            switch (item) {
            | QuaPost(t) =>
              <span className="Works-itemPlace"> (t##location |> text) </span>
            | ExpPost(t) =>
              <span className="Works-itemPlace"> (t##location |> text) </span>
            }
          )
        </h2>
        (
          switch (item) {
          | QuaPost(t) => <p> (t##description |> text) </p>
          | ExpPost(t) => <p> (t##description |> text) </p>
          }
        )
        (
          switch (item) {
          | QuaPost(_) => nothing
          | ExpPost(t) =>
            <div className="Works-itemTech">
              (
                t##technologies
                |> Array.mapi((i, t) =>
                     <span key=(string_of_int(i)) className=Styles.tag>
                       (t |> text)
                     </span>
                   )
                |> ReasonReact.arrayToElement
              )
            </div>
          }
        )
        (
          switch (item) {
          | QuaPost(t) => <span className="cd-date"> (t##date |> text) </span>
          | ExpPost(t) => <span className="cd-date"> (t##date |> text) </span>
          }
        )
      </div>
    </div>,
};