open Helpers;

let component = ReasonReact.statelessComponent("Home");

let make = (~informations, ~experiences, ~qualifications, ~technologies) => {
  ...component,
  render: _self =>
    <Fragment>
      <Head>
        <title>
          ({js|Thomas Deconinck - Développeur JavaScript|js} |> text)
        </title>
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
            <SectionTitle value={js|Expériences|js} />
            <section id="cd-timeline" className="cd-container">
              (
                xpList
                |> List.mapi((i, item) =>
                     <TimelineItem
                       key=(string_of_int(i))
                       item=(ExpPost(item))
                       icon=Code
                     />
                   )
                |> list
              )
            </section>
          </Section>;
        }
      )
      (
        switch ((technologies: Types.technologieNode)) {
        | Inactive
        | Loading => "Loading ..." |> text
        | Errored => "An error occured" |> text
        | Idle(technologies) =>
          <Section>
            <SectionTitle value={js|Compétences|js} />
            <Container>
              (
                technologies##list
                |> Array.mapi((i, value) =>
                     <Tag key=(string_of_int(i)) value color="#e66815" />
                   )
                |> ReasonReact.arrayToElement
              )
            </Container>
          </Section>
        }
      )
      (
        switch ((qualifications: Types.qualifications)) {
        | Inactive
        | Loading => "Loading ..." |> text
        | Errored => "An error occured" |> text
        | Idle(qualification) =>
          <Section dark=true>
            <SectionTitle value={js|Diplômes|js} />
            <section id="cd-timeline" className="cd-container Qualifications">
              (
                qualification##list
                |> Array.to_list
                |> List.mapi((i, item) =>
                     <TimelineItem
                       key=(string_of_int(i))
                       item=(QuaPost(item))
                       icon=Graduation
                     />
                   )
                |> list
              )
            </section>
          </Section>
        }
      )
    </Fragment>,
};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~informations=PhenomicPresetReactApp.jsEdge(jsProps##informations),
      ~experiences=PhenomicPresetReactApp.jsEdge(jsProps##experiences),
      ~qualifications=PhenomicPresetReactApp.jsEdge(jsProps##qualifications),
      ~technologies=PhenomicPresetReactApp.jsEdge(jsProps##technologies),
    )
  );

let defaultQueryList: string => PhenomicPresetReactApp.listConfig =
  (path: string) => {
    path,
    by: Some("default"),
    value: None,
    order: None,
    sort: None,
    limit: None,
  };

let queries = props => {
  let informations =
    PhenomicPresetReactApp.query(
      Item({path: "content/home", id: "informations"}),
    );
  let experiences =
    PhenomicPresetReactApp.query(
      List(defaultQueryList("content/home/experiences")),
    );
  let qualifications =
    PhenomicPresetReactApp.query(
      List(defaultQueryList("content/home/qualifications")),
    );
  let technologies =
    PhenomicPresetReactApp.query(
      Item({path: "content/home", id: "technologies"}),
    );
  {
    "informations": informations,
    "experiences": experiences,
    "qualifications": qualifications,
    "technologies": technologies,
  };
};