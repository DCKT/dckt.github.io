open Helpers;

let component = "TimelineItem" |> ReasonReact.statelessComponent;

let make = (~experience: Types.experiencePost, _children) => {
  ...component,
  render: _self =>
    <div className="cd-timeline-block">
      <div className="cd-timeline-img cd-picture">
        <img src="images/code.svg" alt="Picture" />
      </div>
      <div className="cd-timeline-content">
        <h2>
          (experience##title |> text)
          <span className="Works-itemCompany">
            (experience##company |> text)
          </span>
          <span className="Works-itemPlace">
            (experience##location |> text)
          </span>
        </h2>
        <p> (experience##description |> text) </p>
        <div className="Works-itemTech">
          (experience##technologies |> text)
        </div>
        <span className="cd-date"> (experience##date |> text) </span>
      </div>
    </div>,
};