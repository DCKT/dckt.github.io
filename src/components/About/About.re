let component = "About" |> ReasonReact.statelessComponent;

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <Section>
        <SectionTitle value="Hello" />
        <div className="dck-Hello">
          <p>
            (
              {js|
            Je m'appelle Thomas Deconinck, j'ai 25 ans et je suis un passionné d'informatique.
            Certains utiliseront le mot "geek", "nerd" ou encore "addict", mais je me vois plutôt comme un réel passionné.
            |js}
              |> ReasonReact.string
            )
            <br />
            <br />
            (
              {js|
            Je suis principalement attiré par la programmation, j'adore essayer et comparer différents langages comme par exemple le JavaScript, le Python, le Ruby ou plus récemment le Go.
              |js}
              |> ReasonReact.string
            )
            <br />
            <br />
            (
              {js|
                Mais je m'intéresse également à tout ce qui tourne autour de la programmation, comme l'administration système sous Linux, les objets connectés, etc..
                Mon objectif principal est, et restera, le perfectionnement. J'ai pour conviction que l'on peut toujours en apprendre plus ou mieux faire.

          |js}
              |> ReasonReact.string
            )
          </p>
          <Socials />
        </div>
      </Section>
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));