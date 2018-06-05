type partialPost = {
  .
  "id": string,
  "title": string,
};

type posts =
  PhenomicPresetReactApp.edge(
    PhenomicPresetReactApp.jsNodeList(partialPost),
  );

type experience = {
  .
  "id": string,
  "title": string,
  "description": string,
  "location": string,
  "company": string,
  "date": string,
  "technologies": array(string),
};

type qualification = {
  .
  "title": string,
  "description": string,
  "location": string,
  "date": string,
};

type post = {
  .
  "id": string,
  "title": string,
  "body": PhenomicPresetReactApp.BodyRenderer.jsBody,
};

type postNode = PhenomicPresetReactApp.edge(post);

type informations = {
  .
  "id": string,
  "title": string,
  "technologies": array(string),
  "qualifications": array(qualification),
  "experiences": array(experience),
  "body": PhenomicPresetReactApp.BodyRenderer.jsBody,
};

type informationsNode = PhenomicPresetReactApp.edge(informations);

type timelineItem =
  | ExpPost(experience)
  | QuaPost(qualification);