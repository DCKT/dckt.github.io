open Helpers;

let component = ReasonReact.statelessComponent("Home");

let make = (~informations, ~experiences) => {
  ...component,
  render: _self =>
    <Fragment>
      <Head>
        <title> ("Thomas Deconinck - Développeur JavaScript" |> text) </title>
        <meta name="description" content="Everything is awesome!" />
      </Head>
      <Header />
      (
        switch ((informations: Types.postNode)) {
        | Inactive
        | Loading => "Loading ..." |> text
        | Errored => <ErrorPage />
        | Idle(post) =>
          <Section>
            <h1> (post##title |> text) </h1>
            <PhenomicPresetReactApp.BodyRenderer body=post##body />
          </Section>
        }
      )
      (
        switch ((experiences: Types.experiences)) {
        | Inactive
        | Loading => "Loading ..." |> text
        | Errored => "An error occured" |> text
        | Idle(posts) =>
          let postsList = posts##list |> Array.to_list;
          <div>
            <ul>
              (
                postsList
                |> List.map(item =>
                     <li key=item##id>
                       (item##title |> text)
                       (item##location |> text)
                     </li>
                   )
                |> list
              )
            </ul>
          </div>;
        }
      )
    </Fragment>,
};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~informations=PhenomicPresetReactApp.jsEdge(jsProps##informations),
      ~experiences=PhenomicPresetReactApp.jsEdge(jsProps##experiences),
    )
  );

let queries = props => {
  let informations =
    PhenomicPresetReactApp.query(
      Item({path: "content/home", id: "informations"}),
    );
  let experiences =
    PhenomicPresetReactApp.query(
      PaginatedList({
        path: "content/experiences",
        by: Some("default"),
        value: None,
        order: None,
        sort: None,
        limit: Some(4),
        after: Some(props##params##after),
      }),
    );
  {"informations": informations, "experiences": experiences};
};