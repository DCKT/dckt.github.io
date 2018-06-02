type partialPost = {
  .
  "id": string,
  "title": string,
};

type posts =
  PhenomicPresetReactApp.edge(
    PhenomicPresetReactApp.jsNodeList(partialPost),
  );

type experiencePost = {
  .
  "id": string,
  "title": string,
  "description": string,
  "location": string,
  "company": string,
  "date": string,
  "technologies": array(string),
};

type qualificationPost = {
  .
  "id": string,
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

type technologie = {
  .
  "id": string,
  "list": array(string),
};

type technologieNode = PhenomicPresetReactApp.edge(technologie);

type experiences =
  PhenomicPresetReactApp.edge(
    PhenomicPresetReactApp.jsNodeList(experiencePost),
  );

type qualifications =
  PhenomicPresetReactApp.edge(
    PhenomicPresetReactApp.jsNodeList(qualificationPost),
  );

type timelineItem =
  | ExpPost(experiencePost)
  | QuaPost(qualificationPost);