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
  "technologies": string,
};

type post = {
  .
  "id": string,
  "title": string,
  "body": PhenomicPresetReactApp.BodyRenderer.jsBody,
};

type postNode = PhenomicPresetReactApp.edge(post);

type experiences =
  PhenomicPresetReactApp.edge(
    PhenomicPresetReactApp.jsNodeList(experiencePost),
  );