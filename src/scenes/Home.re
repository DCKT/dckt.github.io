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
            <div className="dck-Hello">
              <SectionTitle value="Bonjour !" />
              <PhenomicPresetReactApp.BodyRenderer body=post##body />
              <Socials />
            </div>
          </Section>
        }
      )
      (
        switch ((experiences: Types.experiences)) {
        | Inactive
        | Loading => "Loading ..." |> text
        | Errored => "An error occured" |> text
        | Idle(xp) =>
          let xpList = xp##list |> Array.to_list;
          <Section dark=true>
            <SectionTitle value="Expériences" />
            (
              xpList
              |> List.mapi((i, item) =>
                   <li key=(string_of_int(i))>
                     (item##title |> text)
                     (item##location |> text)
                   </li>
                 )
              |> list
            )
          </Section>;
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
      List({
        path: "content/experiences",
        by: Some("default"),
        value: None,
        order: None,
        sort: None,
        limit: None,
      }),
    );
  {"informations": informations, "experiences": experiences};
};