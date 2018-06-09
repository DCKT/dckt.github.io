open Helpers;

let component = ReasonReact.statelessComponent("Home");

let make = (~informations) => {
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
        switch ((informations: Types.informationsNode)) {
        | Inactive
        | Loading => nothing
        | Errored => "An error occured" |> text
        | Idle(infos) =>
          <Fragment>
            <Section>
              <div className="dck-Hello">
                <SectionTitle value="Bonjour !" />
                <PhenomicPresetReactApp.BodyRenderer body=infos##body />
                <SocialsContainer>
                  <SocialLink
                    href="https://twitter.com/DCK__"
                    imageSource="/images/socials/twitter.svg"
                  />
                  <SocialLink
                    href="https://github.com/DCKT"
                    imageSource="/images/socials/github.svg"
                  />
                  <SocialLink
                    href="https://www.linkedin.com/in/deconinckthomas/"
                    imageSource="/images/socials/linkedin.svg"
                  />
                </SocialsContainer>
              </div>
            </Section>
            <Section dark=true>
              <SectionTitle textColor="#fff" value={js|Expériences|js} />
              <section id="cd-timeline" className="cd-container">
                (
                  infos##experiences
                  |> Array.mapi((i, item) =>
                       <TimelineItem
                         key=(string_of_int(i))
                         item=(ExpPost(item))
                         icon=Code
                       />
                     )
                  |> ReasonReact.arrayToElement
                )
              </section>
            </Section>
            <Section>
              <SectionTitle value={js|Compétences|js} />
              <Container>
                <TagsList
                  tags=infos##technologies
                  textColor=(Some("#fff"))
                  backgroundColor=(Some("#e66815"))
                />
              </Container>
            </Section>
            <Section dark=true>
              <SectionTitle textColor="#fff" value={js|Diplômes|js} />
              <section
                id="cd-timeline" className="cd-container Qualifications">
                (
                  infos##qualifications
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
            <Section>
              <div className="dck-Hello">
                <SectionTitle value="Contact" />
                <p>
                  (
                    {js|Besoin d'aide sur votre projet ? N'hésitez pas à me laisser un message, vous obtiendrez toujours une réponse dans les 24 heures !|js}
                    |> text
                  )
                </p>
                <a className="text-orange" href="mailto:dck@outlook.fr">
                  ("Envoyez un mail" |> text)
                </a>
              </div>
            </Section>
          </Fragment>
        }
      )
    </Fragment>,
};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~informations=PhenomicPresetReactApp.jsEdge(jsProps##informations))
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
  {"informations": informations};
};